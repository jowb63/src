/*
 * Exception.cpp
 *
 *  Created on: Apr 9, 2014
 *      Author: Joshua
 */
#include "Exception.h"
#include <sstream>

Exception::Exception()
{
	value = "";
}

Exception::Exception(string value)
{
	this->value = value;
}

string Exception::getType()
{
	return "Exception";
}

int Exception::getValueOne()
{
	return 0;
}

int Exception::getValueTwo()
{
	return 0;
}

bool Exception::isInt()
{
	return false;
}


void Exception::simplify()
{

}

string Exception::toString()
{
	return value;
}

string Exception::add(Number* num1, Number* num2)
{
	std::ostringstream oss;
	oss << num1->toString() << " + " << num2->toString();
	return oss.str();
}

string Exception::subtract(Number* num1, Number* num2)
{
	std::ostringstream oss;
	oss << num1->toString() << " - " << num2->toString();
	return oss.str();
}

string Exception::multiply(Number* num1, Number* num2)
{
	std::ostringstream oss;
	oss << num1->toString() << " * " << num2->toString();
	return oss.str();
}

string Exception::divide(Number* num1, Number* num2)
{
	std::ostringstream oss;
	oss << num1->toString() << " / " << num2->toString();
	return oss.str();
}

Number* Exception::getNum1()
{
	return NULL;
}

Number* Exception::getNum2()
{
	return NULL;
}



