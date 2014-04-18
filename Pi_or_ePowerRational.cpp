//
//  Pi_or_ePowerRational.cpp
//  CppProject
//
//  Created by Medhir Bhargava on 4/13/14.
//  Copyright (c) 2014 Medhir Bhargava. All rights reserved.
//

#include "Pi_or_ePowerRational.h"
#include "Rational.h"
#include "Pi_or_e.h"
#include <sstream>

Pi_or_ePowerRational::Pi_or_ePowerRational()
{
	Number* ratVal = new Rational(1, 1);
    Number* pi_eVal = new Pi_or_e(1, "pi");
}

Pi_or_ePowerRational::Pi_or_ePowerRational(Number* ratVal, Number* pi_eVal)
{
	this->ratVal = ratVal;
    this->pi_eVal = pi_eVal;
}

string Pi_or_ePowerRational::getType()
{
	return "Pi_or_ePowerRational";
}

int Pi_or_ePowerRational::getValueOne()
{
	return 0;
}

int Pi_or_ePowerRational::getValueTwo()
{
	return 0;
}

Number* Pi_or_ePowerRational::getNum1()
{
    return ratVal;
}

Number* Pi_or_ePowerRational::getNum2()
{
    return pi_eVal;
}

bool Pi_or_ePowerRational::isInt()
{
	return false;
}


void Pi_or_ePowerRational::simplify()
{
    
}

string Pi_or_ePowerRational::toString()
{
	ostringstream value;
    value << pi_eVal->toString() << "^" << ratVal->toString();
    return value.str();
}
