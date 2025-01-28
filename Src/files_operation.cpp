#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "function.h"
#include "structure.h"

void CreateEndFile(input_file_one & file_one, input_file_two & file_two, output_file & output_file)
{
    std::ofstream file(output_file.file_name);
    if (!file)
    {
        std::cerr << "Failed to open the file!" << std::endl;
        return;
    }
    for (size_t i = 0; i < output_file.result.size(); i++)
    {
        file
        << std::left
        << std::setw(7)
        << "IN:"
        << file_one.input.FirstInputNumber
        << ":"
        << std::setw(5)
        << file_two.FirstInputStates[i]
        << file_one.input.SecondInputNumber
        << ":"
        << std::setw(5)
        << file_two.SecondInputStates[i]
        << std::setw(8)
        << "OUT:"
        << file_one.output.OutputNumber
        << ":"
        << output_file.result[i]
        << std::endl;
    }
    std::cout << "File created!" << std::endl;
    file.close();
}