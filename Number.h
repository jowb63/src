/*
 * Number.h
 *
 *  Created on: Apr 7, 2014
 *      Author: Joshua
 */

#ifndef NUMBER_H_
#define NUMBER_H_
#include <iostream>
using namespace std;

class Number
{
	public:
		virtual string getType() = 0;
		virtual int getValueOne() = 0;
		virtual int getValueTwo() = 0;
		virtual bool isInt() = 0;
		virtual void simplify() = 0;
		virtual string toString() = 0;
		virtual Number* getNum1() = 0;
		virtual Number* getNum2() = 0;
};

#endif /* NUMBER_H_ */
