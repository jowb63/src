//
//  RationalMinusPi_or_e.cpp
//  CppProject
//
//  Created by Medhir Bhargava on 4/13/14.
//  Copyright (c) 2014 Medhir Bhargava. All rights reserved.
//

#include "RationalMinusPi_or_e.h"
#include "Rational.h"
#include "Pi_or_e.h"
#include <sstream>

RationalMinusPi_or_e::RationalMinusPi_or_e()
{
	Number* ratVal = new Rational(1, 1);
    Number* pi_eVal = new Pi_or_e(1, "pi");
}

RationalMinusPi_or_e::RationalMinusPi_or_e(Number* ratVal, Number* pi_eVal)
{
	this->ratVal = ratVal;
    this->pi_eVal = pi_eVal;
}

string RationalMinusPi_or_e::getType()
{
	return "RationalMinusPi_or_e";
}

int RationalMinusPi_or_e::getValueOne()
{
	return 0;
}

int RationalMinusPi_or_e::getValueTwo()
{
	return 0;
}

Number* RationalMinusPi_or_e::getNum1()
{
    return ratVal;
}

Number* RationalMinusPi_or_e::getNum2()
{
    return pi_eVal;
}

bool RationalMinusPi_or_e::isInt()
{
	return false;
}


void RationalMinusPi_or_e::simplify()
{
    
}

string RationalMinusPi_or_e::toString()
{
	ostringstream value;
    value << ratVal->toString() << "-" << pi_eVal->toString();
    return value.str();
}
