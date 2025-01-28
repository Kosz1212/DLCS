#include "structure.h"
#include <unordered_map>
#include "algorithm.h"
#include "gates.h"

void algorithm(std::vector<bool> & results, input_file_one file_one, input_file_two file_two)
{
    std::unordered_map<int, bool> used_gates;
    for (size_t line = 0; line < file_two.FirstInputNumber.size(); ++line)
    {
        bool result = signalTransition(file_one, file_two, file_one.output.OutputNumber, used_gates, line);
        results.push_back(result);
        used_gates.clear();
    }
}

bool signalTransition(input_file_one& input_one, input_file_two& input_two, int& test_gate, std::unordered_map<int, bool>& used_gates, int line)
{
    auto it = used_gates.find(test_gate);
    if (it != used_gates.end())
    {
        return it->second;
    }
    if (test_gate == input_one.input.FirstInputNumber)
    {
        used_gates.emplace(test_gate, input_two.FirstInputStates[line]);
        return input_two.FirstInputStates[line];
    }
    if (test_gate == input_one.input.SecondInputNumber)
    {
        used_gates.emplace(test_gate, input_two.SecondInputStates[line]);
        return input_two.SecondInputStates[line];
    }
    for (size_t i = 0; i < input_one.gate.OutputOfTheGate.size(); ++i) {
        if (test_gate == input_one.gate.OutputOfTheGate[i])
        {
            std::string gate_name = input_one.gate.gate[i];
            bool firstSignal = signalTransition(input_one, input_two, input_one.gate.FirstInputOfTheGate[i], used_gates, line);
            bool secondSignal = signalTransition(input_one, input_two, input_one.gate.SecondInputOfTheGate[i], used_gates, line);
            bool result = false;
            if (gate_name == "NEG")
            {
                result = NEG(firstSignal);
            }
            else if (gate_name == "AND")
            {
                result = AND(firstSignal, secondSignal);
            }
            else if (gate_name == "NAND")
            {
                result = NAND(firstSignal, secondSignal);
            }
            else if (gate_name == "OR")
            {
                result = OR(firstSignal, secondSignal);
            }
            else if (gate_name == "NOR")
            {
                result = NOR(firstSignal, secondSignal);
            }
            else if (gate_name == "XOR")
            {
                result = XOR(firstSignal, secondSignal);
            }
            else if (gate_name == "XNOR")
            {
                result = XNOR(firstSignal, secondSignal);
            }
            used_gates.emplace(test_gate, result);
            return  result;
        }
    }
    return false;
}
