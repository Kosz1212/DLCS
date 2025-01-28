#include <iostream>

#include "function.h"
#include "structure.h"
#include <iomanip>
#include <ostream>

void help_short()
{
    std::cout
        << "Invalid program usage."
        << std::endl
        << "Use 'DLCS -h' or 'DLCS --help' to get more information."
        << std::endl; 
}

void help()
{
    int space = 3;
    int n = 5;
    std::cout
        << std::left
        << "NAME"
        << std::endl
        << std::setw(space) << " "
        << "DLCS - Digital Logic Circuit Simulator"
        << std::endl
        << std::endl
        << "SYNOPSIS"
        << std::endl
        << std::setw(space) << " "
        << "DLCS <operation>"
        << std::endl
        << std::endl
        << "DESCRIPTION"
        << std::endl
        << std::setw(space) << " "
        << "DLCS is a command-line tool designed to simulate digital logic circuits. The program processes two input files:"
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << "1. Circuit Definition File: Specifies the structure of the logic circuit, including the types of gates (e.g., AND, OR, XOR) and their connections."
        << std::endl
        << std::setw(space) << " "
        << "2. Input States File: Provides the binary input states (0 or 1) for each simulation scenario."
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << "Based on the provided inputs and the defined circuit, tuc computes the resulting output signals and writes them to an output file. The simulator supports various logic gates and ensures the integrity of the circuit by checking for errors such as invalid gate types or signal loops."
        << std::endl
        << std::endl
        << "OPERATIONS"
        << std::endl
        << std::setw(space) << " "
        << "-h, --help"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "Display detailed information about the program's usage and exit."
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << "-i, --inputs <path> <path>"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "Specify the paths to the input files. The first path corresponds to the circuit definition file, and the second path corresponds to the input states file."
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "Example:"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "DLCS -i circuit.txt inputs.txt"
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << "-o, --output <path>"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "Specify the path for the output file where the simulation results will be stored. If not provided, the default output file is `output.txt`."
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "Example:"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "DLCS -o results.txt"
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << "The program requires the `-i` or `--inputs` flag to function. The `-o` or `--output` flag is optional but recommended for specifying a custom output file name."
        << std::endl
        << std::endl
        << "EXAMPLES"
        << std::endl
        << std::setw(space) << " "
        << "Simulate a logic circuit with specified input and output files:"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "DLCS -i circuit.txt inputs.txt -o results.txt"
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << "Display the help message:"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "DLCS --help"
        << std::endl
        << std::endl
        << "DESCRIPTION OF INPUT FILES"
        << std::endl
        << std::setw(space) << " "
        << "Circuit Definition File (First Input File)"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "- The first line should start with \"IN:\" followed by two input node numbers."
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "- The second line should start with \"OUT:\" followed by the output node number."
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "- Subsequent lines define the gates in the circuit with the format:"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "<GATE_TYPE> <FIRST_INPUT> <SECOND_INPUT> <OUTPUT>"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "- `GATE_TYPE` can be one of the following: NEG, AND, NAND, OR, NOR, XOR, XNOR."
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "- For the NEG gate, the `SECOND_INPUT` should be the same as the `FIRST_INPUT`."
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "Example:"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "IN:"
        << std::setw(n) << "1"
        << std::setw(n) << "2"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "OUT:"
        << std::setw(n) << "5"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "AND"
        << std::setw(n) << "1"
        << std::setw(n) << "2"
        << std::setw(n) << "3"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "OR"
        << std::setw(n) << "3"
        << std::setw(n) << "2"
        << std::setw(n) << "4"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "NEG"
        << std::setw(n) << "4"
        << std::setw(n) << "4"
        << std::setw(n) << "5"
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << "Input States File (Second Input File)"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "- Each line represents a simulation scenario with input states."
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "- The format for each line is:"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "<FirstInputNumber> <FirstInputState> <SecondInputNumber> <SecondInputState>"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "- `FirstInputState` and `SecondInputState` should be either 0 or 1."
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "Example:"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "1"
        << std::setw(n) << "0"
        << std::setw(n) << "2"
        << std::setw(n) << "1"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "1"
        << std::setw(n) << "1"
        << std::setw(n) << "2"
        << std::setw(n) << "0"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "1"
        << std::setw(n) << "1"
        << std::setw(n) << "2"
        << std::setw(n) << "1"
        << std::endl
        << std::endl
        << "OUTPUT FILE"
        << std::endl
        << std::setw(space) << " "
        << "The output file contains the results of the simulation for each input scenario. Each line corresponds to an input scenario and follows the format:"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << "The output file contains the results of the simulation for each input scenario. Each line corresponds to an input scenario and follows the format:"
        << std::endl
        << std::endl
        << std::setw(space) << " "
        << "Example:"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "IN:"
        << std::setw(n) << "1:0"
        << std::setw(n) << "2:1"
        << std::setw(n) << "OUT:"
        << std::setw(n) << "5:1"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "IN:"
        << std::setw(n) << "1:1"
        << std::setw(n) << "2:0"
        << std::setw(n) << "OUT:"
        << std::setw(n) << "5:0"
        << std::endl
        << std::setw(space) << " "
        << std::setw(space) << " "
        << std::setw(n) << "IN:"
        << std::setw(n) << "1:1"
        << std::setw(n) << "2:1"
        << std::setw(n) << "OUT:"
        << std::setw(n) << "5:1"
        << std::endl;
}

/**
 * @brief Processes command-line arguments and sets appropriate flags and file paths.
 *
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 * @param input_one Structure containing data from the first input file.
 * @param input_two Structure containing data from the second input file.
 * @param output_file Structure storing the simulation output data.
 * @return True if argument processing is successful, false otherwise.
 */

bool protocols(const int & argc, char * argv[], input_file_one & input_one, input_file_two & input_two, output_file & output_file)
{
    bool hasInputFlag = false;
    for (int i = 1; i < argc; ++i) {
        if (checkFlag(argv[i], "-i", "--inputs"))
        {
            hasInputFlag = true;
            if (i + 2 >= argc)
            {
                std::cerr << "Missing required input files after the -i/--inputs flags!" << std::endl;
                return false;
            }
            if (inputProtocolFlag(argv,i))
            {
                std::cerr << "Invalid input files!" << std::endl;
                return false;
            }
            else
            {
                input_one.file_name = argv[i+1];
                input_two.file_name = argv[i+2];
            }
        }
        if (checkFlag(argv[i], "-o", "--output"))
        {
            if (i + 1 >= argc)
            {
                std::cerr << "Missing output file name after the -o/--output flags!" << std::endl;
                return false;
            }
            if (!outputProtocolFlag(argv, i))
            {
                output_file.file_name = argv[i+1];
            }
        }
        if (checkFlag(argv[i], "-h", "--help"))
        {
            help();
            return false;
        }
    }
    if (!hasInputFlag)
    {
        std::cerr << "The -i/--inputs flag is required for the program to function!" << std::endl;
        return false;
    }
    return true;
}

bool checkFlag(const char* arg, const std::string& flag1, const std::string& flag2) 
{
    return ((std::string(arg) == flag1) or (std::string(arg) == flag2));
}

bool inputProtocolFlag(char * arg[], int & i)
{
    return (checkFlag(arg[i+1], "-o", "--output") or
            checkFlag(arg[i+1], "-h", "--help") or
            checkFlag(arg[i+2], "-o", "--output")or
            checkFlag(arg[i+2], "-h", "--help"));
}

bool outputProtocolFlag(char * arg[], int & i)
{
    return (checkFlag(arg[i+1], "-i", "--inputs") or
            checkFlag(arg[i+1], "-h", "--help"));
}