#ifndef GATES_H
#define GATES_H

/**
 * @brief Function implementing the NOT (NEG) gate.
 *
 * @param input1 Input to the gate.
 * @return Result of the NOT gate operation.
 */

bool NEG(const bool& input1);

/**
 * @brief Function implementing the AND gate.
 *
 * @param input1 First input to the gate.
 * @param input2 Second input to the gate.
 * @return Result of the AND gate operation.
 */

bool AND(const bool& input1, const bool& input2);

/**
 * @brief Function implementing the NAND gate.
 *
 * @param input1 First input to the gate.
 * @param input2 Second input to the gate.
 * @return Result of the NAND gate operation.
 */

bool NAND(const bool& input1, const bool& input2);

/**
 * @brief Function implementing the OR gate.
 *
 * @param input1 First input to the gate.
 * @param input2 Second input to the gate.
 * @return Result of the OR gate operation.
 */

bool OR(const bool& input1, const bool& input2);

/**
 * @brief Function implementing the NOR gate.
 *
 * @param input1 First input to the gate.
 * @param input2 Second input to the gate.
 * @return Result of the NOR gate operation.
 */

bool NOR(const bool& input1, const bool& input2);

/**
 * @brief Function implementing the XOR gate.
 *
 * @param input1 First input to the gate.
 * @param input2 Second input to the gate.
 * @return Result of the XOR gate operation.
 */

bool XOR(const bool& input1, const bool& input2);

/**
 * @brief Function implementing the XNOR gate.
 *
 * @param input1 First input to the gate.
 * @param input2 Second input to the gate.
 * @return Result of the XNOR gate operation.
 */

bool XNOR(const bool& input1, const bool& input2);

#endif