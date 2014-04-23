/*
 * Logarithm.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: Joshua
 */
#include "Logarithm.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

Logarithm::Logarithm()
{
	this->base = 10;
	this->log = 1;
}

Logarithm::Logarithm(int base, int log)
{
	this->base = base;
	this->log = log;
	this->simplify();
}

Logarithm::~Logarithm()
{
}

string Logarithm::getType()
{
	return "Logarithm";
}

int Logarithm::getBase()
{
	return base;
}

int Logarithm::getLog()
{
	return log;
}

void Logarithm::simplify()
{

    if (log%base== 0){

	int baseToPower = 1;
	int power = 0;
	while(baseToPower < log && baseToPower != log)
	{
		baseToPower *= base;
		power++;
	}

	if(baseToPower == log)
	{
		log = 1;
		base = power;
	}

	}
    /*vector<int> factors;
    for(int factor = 2; factor <= log; factor++)
    {
        while(log % factor == 0) {
            log = log / factor;
            factors.push_back(factor);
        }
    }

    for (int i = 0; i<factors.size();i++){
        if (i==factors.size()-1){
          cout<< "log_" << base << ":" << factors[i] << endl;
        }
        else
     cout<< "log_" << base << ":" << factors[i] << "+";
}*/
    }

string Logarithm::toString()
{
	if(log != 1)
	{
		std::ostringstream oss;
		oss << "log_" << base << ":" << log;
		return oss.str();
	}
	else
	{
		std::ostringstream oss;
		oss << base;
		return oss.str();
	}

}

int Logarithm::getValueOne()
{
	return base;
}

int Logarithm::getValueTwo()
{
	return log;
}

bool Logarithm::isInt()
{
	if(log == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Number* Logarithm::getNum1()
{
	return NULL;
}

Number* Logarithm::getNum2()
{
	return NULL;
}






