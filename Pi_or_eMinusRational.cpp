//
//  Pi_or_eMinusRational.cpp
//  CppProject
//
//  Created by Medhir Bhargava on 4/13/14.
//  Copyright (c) 2014 Medhir Bhargava. All rights reserved.
//

#include "Pi_or_eMinusRational.h"
#include "Rational.h"
#include "Pi_or_e.h"
#include <sstream>

Pi_or_eMinusRational::Pi_or_eMinusRational()
{
	Number* ratVal = new Rational(1, 1);
    Number* pi_eVal = new Pi_or_e(1, "pi");
}

Pi_or_eMinusRational::Pi_or_eMinusRational(Number* ratVal, Number* pi_eVal)
{
	this->ratVal = ratVal;
    this->pi_eVal = pi_eVal;
}

string Pi_or_eMinusRational::getType()
{
	return "Pi_or_eMinusRational";
}

int Pi_or_eMinusRational::getValueOne()
{
	return 0;
}

int Pi_or_eMinusRational::getValueTwo()
{
	return 0;
}

Number* Pi_or_eMinusRational::getNum1()
{
    return ratVal;
}

Number* Pi_or_eMinusRational::getNum2()
{
    return pi_eVal;
}

bool Pi_or_eMinusRational::isInt()
{
	return false;
}


void Pi_or_eMinusRational::simplify()
{
    
}

string Pi_or_eMinusRational::toString()
{
	ostringstream value;
    value << pi_eVal->toString() << "-" << ratVal->toString();
    return value.str();
}
