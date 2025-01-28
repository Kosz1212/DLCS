#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

#include "files_testing.h"
#include "function.h"
#include "structure.h"

int FirstFileTest(input_file_one & file_one)
{
	std::ifstream file(file_one.file_name);
	if (!file)
	{
		std::cerr << "Failed to open the file!" << std::endl;
		return 0;
	}

	std::string line;
	std::string comment;
	int linia = 1;
	std::set<int> used_gates;
	std::set<int> uniqueGates;
	while (getline(file, line))
	{
		std::stringstream sst(line);
		// Checking the consistency of the first line of the file
		if (linia == 1)
		{
			sst >> file_one.input.input >> file_one.input.FirstInputNumber >> file_one.input.SecondInputNumber;
			std::cout << "1. Read: \"" << file_one.input.input << "\" " << file_one.input.FirstInputNumber << " " << file_one.input.SecondInputNumber << std::endl;
			if (sst.fail())
			{
				comment = "The provided input data is unacceptable.";
				ErrorFileInput(file_one.file_name, linia, comment);
				return 0;
			}
			if (file_one.input.input != "IN:")
			{
				comment = "Expected \"IN:\" as a label, but received: " + file_one.input.input;
				ErrorFileInput(file_one.file_name, linia, comment);
				return 0;
			}
		}
		// Checking the consistency of the second line of the file
		if (linia == 2)
		{
			sst >> file_one.output.output >> file_one.output.OutputNumber;
			std::cout << "2. Read: \"" << file_one.output.output << "\" " << file_one.output.OutputNumber << std::endl;
			if (sst.fail())
			{
				comment = "The provided input data is unacceptable.";
				ErrorFileInput(file_one.file_name, linia, comment);
				return 0;
			}
			if (file_one.output.output != "OUT:")
			{
				comment = "Expected \"OUT:\" as a label, but received: " + file_one.output.output;
				ErrorFileInput(file_one.file_name, linia, comment);
				return 0;
			}
		}
		// Checking the consistency of the remaining lines of the file
		if (linia > 2)
		{
			std::string gateName;
			int firstInput, secondInput, output;
			sst >> gateName >> firstInput >> secondInput >> output;
			std::cout << line << ". Read: \"" << gateName << "\" " << firstInput << " " << secondInput << " " << output << std::endl;
			if (sst.fail())
			{
				comment = "The provided input data is unacceptable.";
				ErrorFileInput(file_one.file_name, linia, comment);
				return 0;
			}
			if ((firstInput == file_one.output.OutputNumber) or (secondInput == file_one.output.OutputNumber))
			{
				comment = "The gate cannot require input signals from the system's output!";
				ErrorFileInput(file_one.file_name, linia, comment);
				return 0;
			}
			if ((output == file_one.input.FirstInputNumber) or (output == file_one.input.SecondInputNumber))
			{
				comment = "Cannot create a gate with the same number as the system's input signals!";
				ErrorFileInput(file_one.file_name, linia, comment);
				return 0;
			}
			if ((gateName == "NEG") and (firstInput != secondInput))
			{
				comment = "The \"NEG\" gate can only take one input value!";
				ErrorFileInput(file_one.file_name, linia, comment);
				return 0;
			}
			if (!IsValidGate(gateName))
			{
				comment = "Invalid gate label: " + gateName;
				ErrorFileInput(file_one.file_name, linia, comment);
				return 0;
			}

			// Verifying unique gate identifiers
			if (!uniqueGates.insert(output).second)
			{
				comment = "Duplicate gate output identifier found.";
				ErrorFileInput(file_one.file_name, linia, comment);
				return 0;
			}
			file_one.gate.gate.push_back(gateName);
			file_one.gate.FirstInputOfTheGate.push_back(firstInput);
			file_one.gate.SecondInputOfTheGate.push_back(secondInput);
			file_one.gate.OutputOfTheGate.push_back(output);
		}
		++linia;
	}
	if (file_one.input.FirstInputNumber == file_one.input.SecondInputNumber)
	{
		comment = "The provided input node numbers are identical.";
		ErrorFileInput(file_one.file_name, 1, comment);
		return 0;
	}
	if ((file_one.input.FirstInputNumber == file_one.output.OutputNumber) or (file_one.output.OutputNumber == file_one.input.SecondInputNumber))
	{
		comment = "One of the provided input node numbers is the same as the output node number.";
		ErrorFileInput(file_one.file_name, 2, comment);
		return 0;
	}
	// Detecting signal loops
	if (!IsLoopGate(file_one))
	{
		comment = "Signal loop detected!";
		ErrorFileInput(file_one.file_name, 0, comment);
		return 0;
	}
	// Verifying signal flow
	if (!signalTransition(file_one, file_one.output.OutputNumber, used_gates))
	{
		comment = "The signal does not reach the output.";
		ErrorFileInput(file_one.file_name, 0, comment);
		return 0;
	}
	// Identifying unnecessary gates
	for (size_t i = 0; i < file_one.gate.OutputOfTheGate.size(); ++i)
	{
		if (!used_gates.count(file_one.gate.OutputOfTheGate[i]))
		{
			comment = "Warning: An unused gate with output: " + std::to_string(file_one.gate.OutputOfTheGate[i]);
			WarningFileInput(file_one.file_name, comment);
		}
	}
	file.close();
	return 1;
}

int SecondFileTest(const input_file_one& file_one, input_file_two & file_two)
{
	std::ifstream file(file_two.file_name);
	if (!file)
	{
		std::cerr << "Failed to open the file!" << std::endl;
		return 0;
	}
	std::string line;
	// Checking file consistency
	while (getline(file, line))
	{
		std::stringstream sst(line);
		char sign;
		int linia = 1;
		int i = 0;
		std::string comment;
		int FirstInputStates, SecondInputStates, FirstInputNumber, SecondInputNumber;
		sst >> FirstInputNumber >> sign >> FirstInputStates >> SecondInputNumber >> sign >> SecondInputStates;
		if (sst.fail())
		{
        comment = "The provided input data is unacceptable.";
			ErrorFileInput(file_two.file_name, linia, comment);
			return 0;
		}
		if ((FirstInputStates != 0) and (FirstInputStates != 1))
		{
        comment = "Expected \"0\" or \"1\" as a label, but received: " + std::to_string(FirstInputStates);
			ErrorFileInput(file_two.file_name, linia, comment);
			return 0;
		}
		if ((SecondInputStates != 0) and (SecondInputStates != 1))
		{
        comment = "Expected \"0\" or \"1\" as a label, but received: " + std::to_string(SecondInputStates);
			ErrorFileInput(file_two.file_name, linia, comment);
			return 0;
		}
		if ((FirstInputNumber != file_one.input.FirstInputNumber))
		{
        comment = "Expected \"" + std::to_string(file_one.input.FirstInputNumber) + "\" as a label, but received: " + std::to_string(FirstInputNumber);
			ErrorFileInput(file_two.file_name, linia, comment);
			return 0;
		}
		if ((SecondInputNumber != file_one.input.SecondInputNumber))
		{
        comment = "Expected \"" + std::to_string(file_one.input.SecondInputNumber) + "\" as a label, but received: " + std::to_string(SecondInputNumber);
			ErrorFileInput(file_two.file_name, linia, comment);
			return 0;
		}
		++linia;
		++i;
		file_two.FirstInputNumber.push_back(FirstInputNumber);
		file_two.SecondInputNumber.push_back(SecondInputNumber);
		file_two.FirstInputStates.push_back(FirstInputStates);
		file_two.SecondInputStates.push_back(SecondInputStates);
	}
	file.close();
	return 1;
}

bool signalTransition(input_file_one& input_one, int& test_gate, std::set<int>& used_gates)
{
	// Skipping if the gate has already been used
	if (used_gates.count(test_gate)) return true;
	// Condition to stop recursion
	if ((input_one.input.FirstInputNumber == test_gate) or (input_one.input.SecondInputNumber == test_gate)) {
		// Marking the gate as used
		used_gates.insert(test_gate);
		return true;
	}
	// Recursive loop in a tree-like structure
	for (size_t i = 0; i < input_one.gate.OutputOfTheGate.size(); ++i) {
		// Special condition for "NEG" -> two identical inputs
		if (input_one.gate.gate[i] == "NEG")
		{
			if (signalTransition(input_one, input_one.gate.FirstInputOfTheGate[i], used_gates)) return true;
		}
		else if (test_gate == input_one.gate.OutputOfTheGate[i])
		{
			bool firstSignal = signalTransition(input_one, input_one.gate.FirstInputOfTheGate[i], used_gates);
			bool secondSignal = signalTransition(input_one, input_one.gate.SecondInputOfTheGate[i], used_gates);
			// Marking the gate as used
			used_gates.insert(test_gate);
			if (firstSignal && secondSignal) return true;
		}
	}
	return false;
}

bool IsValidGate(const std::string& gate)
{
	return gate == "NEG" || gate == "AND" || gate == "NAND" || gate == "OR" || gate == "NOR" || gate == "XOR" || gate == "XNOR";
}

bool IsLoopGate(const input_file_one& input_one)
{
	size_t size = input_one.gate.OutputOfTheGate.size();
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = (i+1); j < size; ++j)
		{
			if ((input_one.gate.FirstInputOfTheGate[i] == input_one.gate.OutputOfTheGate[j]) and (input_one.gate.FirstInputOfTheGate[j] == input_one.gate.OutputOfTheGate[i])) return false;
			if ((input_one.gate.FirstInputOfTheGate[i] == input_one.gate.OutputOfTheGate[j]) and (input_one.gate.SecondInputOfTheGate[j] == input_one.gate.OutputOfTheGate[i])) return false;
			if ((input_one.gate.SecondInputOfTheGate[i] == input_one.gate.OutputOfTheGate[j]) and (input_one.gate.FirstInputOfTheGate[j] == input_one.gate.OutputOfTheGate[i])) return false;
			if ((input_one.gate.SecondInputOfTheGate[i] == input_one.gate.OutputOfTheGate[j]) and (input_one.gate.SecondInputOfTheGate[j] == input_one.gate.OutputOfTheGate[i])) return false;
			if ((input_one.gate.FirstInputOfTheGate[j] == input_one.gate.OutputOfTheGate[i]) and (input_one.gate.FirstInputOfTheGate[i] == input_one.gate.OutputOfTheGate[j])) return false;
			if ((input_one.gate.FirstInputOfTheGate[j] == input_one.gate.OutputOfTheGate[i]) and (input_one.gate.SecondInputOfTheGate[i] == input_one.gate.OutputOfTheGate[j])) return false;
			if ((input_one.gate.SecondInputOfTheGate[j] == input_one.gate.OutputOfTheGate[i]) and (input_one.gate.FirstInputOfTheGate[i] == input_one.gate.OutputOfTheGate[j])) return false;
			if ((input_one.gate.SecondInputOfTheGate[j] == input_one.gate.OutputOfTheGate[i]) and (input_one.gate.SecondInputOfTheGate[i] == input_one.gate.OutputOfTheGate[j])) return false;
		}
	}
	return true;
}