#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "function.h"

void WarningFileInput(const std::string& file, const std::string& comment)
{
    std::ofstream log_file("../Log/warning.txt");
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
        << "Comment:"
        << std::setw(20)
        << comment
        << std::endl;

    std::cerr << "WARNING LOG FILE HAS BEEN CREATED!!!" << std::endl;
    std::cerr << "IT IS RECOMMENDED TO REVIEW IT!" << std::endl;
    log_file.close();
}