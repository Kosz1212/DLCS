#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "structure.h"
#include <unordered_map>

/**
 * @brief Main function of the algorithm simulating the logic circuit.
 *
 * @param results Vector storing the simulation results.
 * @param file_one Structure containing data from the first input file.
 * @param file_two Structure containing data from the second input file.
 */
void algorithm(std::vector<bool> & results, input_file_one file_one, input_file_two file_two);

/**
 * @brief Function for passing a signal through logic gates.
 *
 * @param input_one Structure containing data from the first input file.
 * @param input_two Structure containing data from the second input file.
 * @param test_gate Number of the tested gate.
 * @param used_gates Map storing used gates and their results.
 * @param line Line number of the current scenario.
 * @return True if the signal is valid, false otherwise.
 */
bool signalTransition(input_file_one& input_one, input_file_two& input_two, int& test_gate, std::unordered_map<int, bool>& used_gates, int line);

#endif