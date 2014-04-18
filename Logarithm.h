/*
 * Logarithm.h
 *
 *  Created on: Apr 7, 2014
 *      Author: Joshua
 */

#ifndef LOGARITHM_H_
#define LOGARITHM_H_
#include "Number.h"
#include <iostream>
using namespace std;

class Logarithm: public Number
{
	public:
		Logarithm();
		Logarithm(int base, int log);
		~Logarithm();
		string getType();
		int getBase();
		int getLog(); //log is the value after the base
		void simplify();
		string toString();
		int getValueOne();
		int getValueTwo();
		bool isInt();
		Number* getNum1();
		Number* getNum2();

	private:
		int base;
		int log;
};

#endif /* LOGARITHM_H_ */
