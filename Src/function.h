#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <string>
#include <vector>
#include "structure.h"

/**
 * @brief Generates and saves the result file with simulation results.
 *
 * Creates an output file based on the simulation results and input data.
 *
 * @param file_one Structure containing data from the first input file.
 * @param file_two Structure containing data from the second input file.
 * @param output_file Structure storing the simulation output data.
 */

void CreateEndFile(input_file_one& file_one, input_file_two& file_two, output_file& output_file);

/**
 * @brief Generates an operational error log file.
 *
 * Creates or overwrites the `error.txt` file with error information.
 *
 * @param file Name of the file where the error occurred.
 * @param line Line number where the error occurred.
 * @param comment Comment describing the error.
 */

void ErrorFileInput(const std::string& file, const int& line, const std::string& comment);

/**
 * @brief Generates a warning log file.
 *
 * Creates or overwrites the `warning.txt` file with warning information.
 *
 * @param file Name of the file where the warning occurred.
 * @param comment Comment describing the warning.
 */

void WarningFileInput(const std::string& file, const std::string& comment);

/**
 * @brief Displays a short help message about program usage.
 */

void help_short();

/**
 * @brief Displays detailed help about program usage.
 */

void help();

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

bool protocols(const int & argc, char * argv[], input_file_one & input_one, input_file_two & input_two, output_file & output_file);

/**
 * @brief Checks if a given argument matches one of the specified flags.
 *
 * @param arg Argument to check.
 * @param flag1 First possible flag.
 * @param flag2 Second possible flag.
 * @return True if the argument matches any of the flags, false otherwise.
 */

bool checkFlag(const char* arg, const std::string& flag1, const std::string& flag2);

/**
 * @brief Processes flags related to input files.
 *
 * @param arg Array of arguments.
 * @param i Index of the current argument.
 * @return True if an error occurs while processing flags, false otherwise.
 */

bool inputProtocolFlag(char ** arg, int & i);

/**
 * @brief Processes flags related to output files.
 *
 * @param arg Array of arguments.
 * @param i Index of the current argument.
 * @return True if an error occurs while processing flags, false otherwise.
 */

bool outputProtocolFlag(char ** arg, int & i);

#endif