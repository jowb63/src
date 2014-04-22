#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Expression.h"
using namespace std;


string Expression::getType()
{
    return "Expression";
}

string Expression::toString()
{
	ostringstream stringOutput;

	stringOutput << num1->toString() << op << num2->toString();
	return stringOutput.str();
}

Number* Expression::getNum1()
{
	return num1;
}

Number* Expression::getNum2()
{
	return num2;
}

char Expression::getOperator()
{
	return op;
}

void Expression::simplify()
{}

bool Expression::isInt()
{return false;}

int Expression::getValueOne()
{return 0;}

int Expression::getValueTwo()
{return 0;}

