#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "function.h"

void ErrorFileInput(const std::string& file, const int& line, const std::string& comment)
{
    std::ofstream log_file("../Log/error.txt");
    if (!log_file)
    {
        std::cerr << "Failed to open the file!" << std::endl;
        return;
    }

    log_file
        << std::left
        << std::setw(14)
        << "File:"
        << std::setw(20)
        << file
        << std::endl
        << std::setw(14)
        << "Line:"
        << std::setw(20)
        << line
        << std::endl
        << std::setw(14)
        << "Comment:"
        << std::setw(20)
        << comment
        << std::endl;
    
    std::cout << "ERROR LOG FILE HAS BEEN CREATED!!!" << std::endl;
    std::cout << "IT IS RECOMMENDED TO CHECK IT!" << std::endl;
    log_file.close();
}