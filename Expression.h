/*
 * Expression.h
 *
 *  Created on: Apr 17, 2014
 *      Author: Joshua
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_


/*
 * Expression.h
 *
 *  Created on: Apr 17, 2014
 *      Author: Joshua
 */

#ifndef Expression_H_
#define Expression_H_
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

class Expression: public Number
{
	public:
		Expression();
		Expression(Number* num1, Number* num2, string op);
		~Expression();
		string getOperator();

	private:
		Expression* Expression1;
		Expression* Expression2;
		string op;
};

#endif /* Expression_H_ */



#endif /* EXPRESSION_H_ */
