#include "gates.h"

bool NEG(const bool& input1)
{
	if (input1 == 0) return 1;
	else return 0;
}

bool AND(const bool& input1, const bool& input2)
{
	if ((input1 == 0) and (input2 == 0)) return 0;
	if ((input1 == 1) and (input2 == 0)) return 0;
	if ((input1 == 0) and (input2 == 1)) return 0;
	else return 1;
}

bool NAND(const bool& input1, const bool& input2)
{
	if ((input1 == 0) and (input2 == 0)) return 1;
	if ((input1 == 1) and (input2 == 0)) return 1;
	if ((input1 == 0) and (input2 == 1)) return 1;
	else return 0;
}

bool OR(const bool& input1, const bool& input2)
{
	if ((input1 == 0) and (input2 == 0)) return 0;
	if ((input1 == 1) and (input2 == 0)) return 1;
	if ((input1 == 0) and (input2 == 1)) return 1;
	else return 1;
}

bool NOR(const bool& input1, const bool& input2)
{
	if ((input1 == 0) and (input2 == 0)) return 1;
	if ((input1 == 1) and (input2 == 0)) return 0;
	if ((input1 == 0) and (input2 == 1)) return 0;
	else return 0;
}

bool XOR(const bool& input1, const bool& input2)
{
	if ((input1 == 0) and (input2 == 0)) return 0;
	if ((input1 == 1) and (input2 == 0)) return 1;
	if ((input1 == 0) and (input2 == 1)) return 1;
	else return 0;
}

bool XNOR(const bool& input1, const bool& input2)
{
	if ((input1 == 0) and (input2 == 0)) return 1;
	if ((input1 == 1) and (input2 == 0)) return 0;
	if ((input1 == 0) and (input2 == 1)) return 0;
	else return 1;
}