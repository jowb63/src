//
//  RationalPlusPi_or_e.cpp
//  CppProject
//
//  Created by Medhir Bhargava on 4/13/14.
//  Copyright (c) 2014 Medhir Bhargava. All rights reserved.
//

#include "RationalPlusPi_or_e.h"
#include "Rational.h"
#include "Pi_or_e.h"
#include <sstream>

RationalPlusPi_or_e::RationalPlusPi_or_e()
{
	Number* ratVal = new Rational(1, 1);
    Number* pi_eVal = new Pi_or_e(1, "pi");
}

RationalPlusPi_or_e::RationalPlusPi_or_e(Number* ratVal, Number* pi_eVal)
{
	this->ratVal = ratVal;
    this->pi_eVal = pi_eVal;
}

string RationalPlusPi_or_e::getType()
{
	return "RationalPlusPi_or_e";
}

int RationalPlusPi_or_e::getValueOne()
{
	return 0;
}

int RationalPlusPi_or_e::getValueTwo()
{
	return 0;
}

Number* RationalPlusPi_or_e::getNum1()
{
    return ratVal;
}

Number* RationalPlusPi_or_e::getNum2()
{
    return pi_eVal;
}

bool RationalPlusPi_or_e::isInt()
{
	return false;
}


void RationalPlusPi_or_e::simplify()
{
    
}

string RationalPlusPi_or_e::toString()
{
	ostringstream value;
    value << ratVal->toString() << "+" << pi_eVal->toString();
    return value.str();
}

