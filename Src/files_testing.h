#ifndef FILES_TESTING_H
#define FILES_TESTING_H

#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "structure.h"

/**
 * @brief Tests the validity of the first input file.
 *
 * Verifies the consistency of input data with the definition of the logic circuit.
 *
 * @param file_one Structure containing data from the first input file.
 * @return 1 if the test is successful, 0 otherwise.
 */

int FirstFileTest(input_file_one& file_one);

/**
 * @brief Tests the validity of the second input file.
 *
 * Verifies the consistency of input states with the definition of the logic circuit.
 *
 * @param file_one Structure containing data from the first input file.
 * @param file_two Structure containing data from the second input file.
 * @return 1 if the test is successful, 0 otherwise.
 */

int SecondFileTest(const input_file_one& file_one, input_file_two & file_two);

/**
 * @brief Checks if the provided gate is supported.
 *
 * @param gate Type of logic gate.
 * @return True if the gate is supported, false otherwise.
 */

bool IsValidGate(const std::string& gate);

/**
 * @brief Passes a signal through logic gates and checks its validity.
 *
 * @param input_one Structure containing data from the first input file.
 * @param test_gate Number of the tested gate.
 * @param used_gates Set of used gates.
 * @return True if the signal is valid, false otherwise.
 */

bool signalTransition(input_file_one& input_one, int& test_gate, std::set<int>& used_gates);

/**
 * @brief Checks if there is a signal loop in the logic circuit.
 *
 * @param input_one Structure containing data from the first input file.
 * @return True if no loop exists, false otherwise.
 */

bool IsLoopGate(const input_file_one& input_one);

#endif