#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @struct input_gates
 * @brief Structure storing information about input gates.
 */
struct input_gates {
    std::string input;              /**< Input label */
    int FirstInputNumber;           /**< First input number */
    int SecondInputNumber;          /**< Second input number */
};

/**
 * @struct output_gate
 * @brief Structure storing information about the output gate.
 */
struct output_gate {
    std::string output;             /**< Output label */
    int OutputNumber;               /**< Output number */
};

/**
 * @struct gates
 * @brief Structure storing information about gates in the circuit.
 */
struct gates {
    std::vector<std::string> gate;             /**< Types of gates (e.g., AND, OR) */
    std::vector<int> FirstInputOfTheGate;      /**< Numbers of the first inputs of gates */
    std::vector<int> SecondInputOfTheGate;     /**< Numbers of the second inputs of gates */
    std::vector<int> OutputOfTheGate;          /**< Numbers of the outputs of gates */
};

/**
 * @struct input_file_one
 * @brief Structure storing data from the first input file (circuit definition).
 */
struct input_file_one{
    input_gates input;       /**< Information about inputs */
    output_gate output;      /**< Information about the output */
    gates gate;              /**< Information about gates */
    std::string file_name;   /**< File name */
};

/**
 * @struct input_file_two
 * @brief Structure storing data from the second input file (input states).
 */
struct input_file_two {
    std::vector<int> FirstInputNumber;         /**< Numbers of the first inputs */
    std::vector<int> SecondInputNumber;        /**< Numbers of the second inputs */
    std::vector<int> FirstInputStates;         /**< States of the first inputs (0 or 1) */
    std::vector<int> SecondInputStates;        /**< States of the second inputs (0 or 1) */
    std::string file_name;                     /**< File name */
};

/**
 * @struct output_file
 * @brief Structure storing the simulation output data.
 */
struct output_file {
    std::vector<bool> result;  /**< Simulation results for each scenario */
    std::string file_name;     /**< Output file name */
};

#endif