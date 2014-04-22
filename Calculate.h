/*
 * Calculate.h
 *
 *  Created on: Apr 7, 2014
 *      Author: Joshua
 */

#ifndef CALCULATE_H_
#define CALCULATE_H_
#include "Number.h"

using namespace std;

class Calculate
{
	public:
		Calculate();
		~Calculate();
		Number* log(Number*, Number*);
		Number* add(Number*, Number*);
		Number* subtract(Number*, Number*);
		Number* multiply(Number*, Number*);
		Number* divide(Number*, Number*);
		Number* exponentiate(Number*, Number*);
		Number* root(Number*, Number*);
};

#endif /* CALCULATE_H_ */
