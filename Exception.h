/*
 * Exception.h
 *
 *  Created on: Apr 9, 2014
 *      Author: Joshua
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include "Number.h"

using namespace std;

class Exception: public Number
{
	public:
		Exception();
		Exception(string value);
		string add(Number*, Number*);
		string subtract(Number*, Number*);
		string multiply(Number*, Number*);
		string divide(Number*, Number*);
		string getType();
		int getValueOne();
		int getValueTwo();
		bool isInt();
		void simplify();
		string toString();
		Number* getNum1();
		Number* getNum2();

	private:
		string value;
};

#endif /* EXCEPTION_H_ */
