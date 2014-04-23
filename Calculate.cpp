/*
 * Calculate.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: Joshua
 */
#include "Calculate.h"
#include "Rational.h"
#include "Logarithm.h"
#include "Exception.h"
#include "nthroot.h"
#include "Pi_or_e.h"
#include "RationalPlusPi_or_e.h"
#include "RationalMinusPi_or_e.h"
#include "Pi_or_eMinusRational.h"
#include "Pi_or_ePowerRational.h"
#include "Expression.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <queue>
#include <stdexcept>

using namespace std;

Calculate::Calculate()
{

}

Calculate::~Calculate()
{

}

Number* Calculate::log(Number* base, Number* log)
{
    try {
            if ( log->isInt()&& log->getValueOne()<=0){
                throw std::invalid_argument( "log_b:a a must be greater than 0" );
            }
            if ( base->isInt()&&base->getValueOne()<=0||(base->isInt()&&base->getValueOne()<=1)){
                 throw std::invalid_argument( "log_b:a b must be greater than 0 and not equal to 0" );
            }
            /*
            if (log->getType() == "Rational)
            {
            find float representation of expression
            /if value is less than 0 than
                throw std::invalid_argument( "log_b:a a must be greater than 0" );
            }
            if (base->getType() == "Rational)
            {
            find float representation of expression
            if value is less than <=0 || ==1 than
                throw std::invalid_argument( "log_b:a a must be greater than 0" );

            }
            if (!(log->getType()=="Rational)
            {
            //find float representation of expression
            //if value is less than 0 than
            //throw std::invalid_argument( "log_b:a a must be greater than 0" );
            //if log is not rational
            }
            if(!(base->getType() =="Rational")){
              //find float representation of expression
            //if value is less than <=0 || ==1 than return
            //throw std::invalid_argument( "log_b:a b must be greater than 0 and not equal to 0" );
            }

            */
        } catch (const std::invalid_argument& e) {
            cout << e.what()<<endl;

        }

        if(base->getType() == "e" && log->getType() == "Pi_or_ePowerRational")
        {
        	return log->getNum1();
        }
    if ((base->getValueOne() == log->getValueOne()) && (base->getValueTwo()==log->getValueTwo()))
    {

        Number* ans = new Rational(1, 1);
        return ans;
    }
	if(base->getType() == "Rational" && log->getType() == "Rational" && base->isInt()&&(base->getValueOne() == log->getValueTwo()))
	{
        int pow = log->getValueOne();
        Number* negpow = new Rational(0-pow, 1);
        return negpow;
	}
	if(base->getType() == "Rational" && log->getType() == "Rational")
		{
			if(base->isInt() && log->isInt())
			{
				Number* num = new Logarithm(base->getValueOne(), log->getValueOne());
				return num;
			}
		}
	/*if(base->getType() == "Rational" && log->getType() == "Rational" && base->isInt() && log->isInt())
	{
        Number* nlog = new Logarithm(base->getValueOne(),log->getValueOne());
        nlog->simplify();
        return nlog;
	}*/

	/*if(base->getType() == "Logarithm"){
      Number* newlog =  new Logarithm(base->getValueOne(), base->getValueTwo());
    newlog->simplify();
        return newlog;
	}*/
// if (base is pi and log is expoenttial and base of exponent == base.string() than
//base ==
//

if((log->getType() != base->getType()||base->getType()=="Exception" || log->getType()=="Exception")){
            //is this the same as if(log->getType() != base->getType())
        ostringstream result;
        result << "log_" << base->toString() << ":" << log->toString();
        Number* ans = new Exception(result.str());
        return ans;
}


	/*if(log->getType() == "Rational" && (base->getType() == "e"||base->getType() == "pi") && log->isInt() == true){
            //is this the same as if(log->getType() != base->getType())
        ostringstream result;
        result << "log_" << base->toString() << ":" << log->toString();
        Number* ans = new Exception(result.str());
        return ans;
	}
	//
	if((log->getType() == "e"||log->getType() == "pi") && (base->getType() == "e"||base->getType() == "pi") ){

       ostringstream result;
        result << "log_" << base->toString() << ":" << log->toString();
        Number* ans = new Exception(result.str());
        return ans;
	}
	if(base->getType() == "Rational" && (log->getType() == "e"||log->getType() == "pi") && base->isInt() == true){
     ostringstream result;
        result << "log_" << base->toString() << ":" << log->toString();
        Number* ans = new Exception(result.str());
        return ans;
	}*/
	/*if(base->getType()=="Exception" || log->getType()=="Exception"){
        ostringstream result;
        result << "log_" << base->toString() << ":" << log->toString();
        Number* ans = new Exception(result.str());
        return ans;
	}*/
}

Number* Calculate::add(Number* x, Number* y)
{
    //evaluate ints as rationals
    if(x->getType()=="Rational" && y->getType()=="Rational")
    {
	   	//rational and rational
	    int a, b;
	    if(x->isInt()== true && y->isInt()==true) //works
	    {
            a = x->getValueOne()+y->getValueOne();
	        b = 1;
		    Number* ans = new Rational(a, b);
	        return ans;
        }
        else
	    {
	       	//at least one not int"


	        if(x->getValueTwo()==y->getValueTwo()) //works
	        {
	            a = x->getValueOne()+y->getValueOne();
	            b = x->getValueTwo();
                Number* ans = new Rational (a, b);

	            return ans;
            }
            else //works
            {
                b = x->getValueTwo() * y->getValueTwo();
                a = (x->getValueOne()*y->getValueTwo()) + (y->getValueOne()*x->getValueTwo());
                Number* ans = new Rational (a, b);

	            return ans;
            }
        }
    }
    else if((x->getType() == "Logarithm" || x->getType()=="nth_root") && (y->getType()=="Logarithm" || y->getType()=="nth_root")) //works
    {
        int a, b;
        if(x->isInt()==true && y->isInt()==true)
        {
            int a = x->getValueOne() + y->getValueOne();//simplified log value 1 + value 2
            int b = 1;
            Number* ans = new Rational(a, b);
            return ans;
        }
        else
        {
        	Number* ans = new Expression(x,y,'+');
            return ans;
        }
    }
    else if((x->getType()=="pi" || x->getType()=="Pi") && (y->getType()=="pi" || y->getType()=="Pi")) //works
    {
        int a = x->getValueOne()+y->getValueOne();
        string name = "pi";
        Number* ans = new Pi_or_e(a, name);
        return ans;
    }
    else if(x->getType()=="e"&& y->getType()=="e") //works
    {
        int a = x->getValueOne()+y->getValueOne();
        string name = "e";
        Number* ans = new Pi_or_e(a, name);
        return ans;
    }
    else if(x->getType() == "Rational"  && (y->getType() == "Logarithm"|| y->getType()=="nth_root"))
	{
	    int a, b;
	    if(x->isInt()==true && y->isInt()==true) //works
        {
            a=x->getValueOne() + y->getValueOne();//y->getValueOne() how to find the value for simplified log?;
            b=1;
            Number* ans = new Rational(a, b);
            return ans;
        }
        else if(x->isInt() == false && y->isInt()==true) //works
        {
            a=(x->getValueOne()*y->getValueTwo())+y->getValueOne();//simplified logarithm as an integers
            b=y->getValueTwo();
            Number* ans = new Rational(a, b);
            return ans;
        }
        else //works
        {
            Number* ans = new Expression(x,y,'+');
            return ans;
        }
	}
    else if((x->getType() == "Logarithm" || x->getType()=="nth_root") && y->getType() == "Rational")
	{
	    int a, b;
	    if(x->isInt()==true && y->isInt()==true) //works
        {
            a=x->getValueOne() + y->getValueOne(); //how to find the value for simplified log?;
            b=1;
            Number* ans = new Rational(a, b);
            return ans;
        }
        else if(x->isInt() == true && y->isInt()==false) //works
        {
            a=(x->getValueOne()*y->getValueTwo())+y->getValueOne();//simplified logarithm as an integer
            b=y->getValueTwo();
            Number* ans = new Rational(a, b);
            return ans;
        }
        else //works
        {
            Number* ans = new Expression(x,y,'+');
            return ans;
        }
	}
    //new Expression conditional statements

    //Expression + Rational || Rational + Expression
    else if(x->getType()=="Expression" && y->getType()=="Rational")
    {
    	//if first number in expression is rational
    	if(x->getNum1()->getType() == "Rational")
    	{
    		//create Number to store added rational values
    		Number* ansNum1 = add(x->getNum1(), y);
    		//create "result" Number which adds new rational value to other number stored in Expression
    		Number* result = add(x->getNum2(), ansNum1);
    		return result;
    	}
    	if(x->getNum2()->getType() == "Rational")
    	{
    		Number* ansNum2 = add(x->getNum2(), y);
    		Number* result = add(x->getNum1(), ansNum2);
    		return result;
    	}
    	else
    	{
    		//if neither number in Expression is a rational, then create a new Expression
    		Number* result = new Expression(x, y, '+');
    		return result;
    	}
    }
    else if(x->getType()=="Rational" && y->getType()=="Expression")
    {
    	if(y->getNum1()->getType() == "Rational")
    	{
    		Number* ansNum1 = add(y->getNum1(), x);
    		Number* result = add(y->getNum2(), ansNum1);
    		return result;
    	}
    	if(y->getNum2()->getType() == "Rational")
    	{
    		Number* ansNum2 = add(y->getNum2(), y);
    		Number* result = add(y->getNum1(), ansNum2);
    		return result;
    	}
    	else
    	{
    		Number* result = new Expression(x, y, '+');
    		return result;
    	}
    }

    //Expression + Log || Log + Expression
    else if(x->getType()=="Expression" && y->getType()=="Logarithm")
    {
    	//if both numbers are of type "Logarithm"
    	if(x->getNum1()->getType() == "Logarithm" && x->getNum2()->getType() == "Logarithm")
    	{
    		//create two "trial numbers"
    		Number* try1 = add(x->getNum1(), y);
    		Number* try2 = add(x->getNum2(), y);
    		//simplify "trial numbers"
    		try1->simplify();
    		try2->simplify();

    		//if either trial succeeds int test, create new expression with new Rational and old Log value
    		if(try1->isInt())
    		{
    			Number* answer = new Expression(try1, x->getNum2(), '+');
    			return answer;
    		}
    		if(try2->isInt())
    		{
    			Number* answer = new Expression(try2, x->getNum1(), '+');
    			return answer;
    		}
    		else
    		{
    			Number* answer = new Expression(x, y, '+');
    			return answer;
    		}
    	}
    	if(x->getNum1()->getType() == "Logarithm" && x->getNum2()->getType() != "Logarithm")
    	{
    		Number* newLogVal = add(x->getNum1(), y);
    		Number* answer = new Expression(x->getNum2(), newLogVal, '+');
    		return answer;
    	}
    	if(x->getNum2()->getType() == "Logarithm" && x->getNum1()->getType() != "Logarithm")
    	{
    		Number* newLogVal = add(x->getNum2(), y);
    		Number* answer = new Expression(x->getNum1(), newLogVal, '+');
    		return answer;
    	}

    }
    else if(x->getType()=="Logarithm" && y->getType()=="Expression")
    {
    	if(y->getNum1()->getType() == "Logarithm" && y->getNum2()->getType() == "Logarithm")
    	{
    		//create two "trial numbers"
    		Number* try1 = add(x, y->getNum1());
    		Number* try2 = add(x, y->getNum2());
    		//simplify "trial numbers"
    		try1->simplify();
    		try2->simplify();

    		//if either trial succeeds int test, create new expression with new Rational and old Log value
    		if(try1->isInt())
    		{
    			Number* answer = new Expression(try1, y->getNum2(), '+');
    			return answer;
    		}
    		if(try2->isInt())
    		{
    			Number* answer = new Expression(try2, y->getNum1(), '+');
    			return answer;
    		}
    		else
    		{
    			Number* answer = new Expression(x, y, '+');
    			return answer;
    		}
    	}
    	if(y->getNum1()->getType() == "Logarithm" && y->getNum2()->getType() != "Logarithm")
    	{
    		Number* newLogVal = add(y->getNum1(), x);
    		Number* answer = new Expression(newLogVal, y->getNum2(), '+');
    		return answer;
    	}
    	if(y->getNum2()->getType() == "Logarithm" && y->getNum1()->getType() != "Logarithm")
    	{
    		Number* newLogVal = add(y->getNum2(), x);
    		Number* answer = new Expression(newLogVal, y->getNum1(), '+');
    		return answer;
    	}
    }

    //Expression + nthRoot || nthRoot + Expression
    else if(x->getType()=="Expression" && y->getType()=="nth_root")
    {
    	//if both numbers are of type "nth_root"
    	if(x->getNum1()->getType() == "nth_root" && x->getNum2()->getType() == "nth_root")
    	{
    		//create two "trial numbers"
    		Number* try1 = add(x->getNum1(), y);
    		Number* try2 = add(x->getNum2(), y);
    		//simplify "trial numbers"
    		try1->simplify();
    		try2->simplify();

    		//if either trial succeeds int test, create new expression with new Rational and old Log value
    		if(try1->isInt())
    		{
    			Number* answer = new Expression(try1, x->getNum2(), '+');
    			return answer;
    		}
    		if(try2->isInt())
    		{
    			Number* answer = new Expression(try2, x->getNum1(), '+');
    			return answer;
    		}
    		else
    		{
    			Number* answer = new Expression(x, y, '+');
    			return answer;
    		}
    	}
    	if(x->getNum1()->getType() == "nth_root" && x->getNum2()->getType() != "nth_root")
    	{
    		Number* newLogVal = add(x->getNum1(), y);
    		Number* answer = new Expression(x->getNum2(), newLogVal, '+');
    		return answer;
    	}
    	if(x->getNum2()->getType() == "nth_root" && x->getNum1()->getType() != "nth_root")
    	{
    		Number* newLogVal = add(x->getNum2(), y);
    		Number* answer = new Expression(x->getNum1(), newLogVal, '+');
    		return answer;
    	}

    }
    else if(x->getType()=="nth_root" && y->getType()=="Expression")
    {
    	if(y->getNum1()->getType() == "nth_root" && y->getNum2()->getType() == "nth_root")
    	{
    		//create two "trial numbers"
    		Number* try1 = add(x, y->getNum1());
    		Number* try2 = add(x, y->getNum2());
    		//simplify "trial numbers"
    		try1->simplify();
    		try2->simplify();

    		//if either trial succeeds int test, create new expression with new Rational and old Log value
    		if(try1->isInt())
    		{
    			Number* answer = new Expression(try1, y->getNum2(), '+');
    			return answer;
    		}
    		if(try2->isInt())
    		{
    			Number* answer = new Expression(try2, y->getNum1(), '+');
    			return answer;
    		}
    		else
    		{
    			Number* answer = new Expression(x, y, '+');
    			return answer;
    		}
    	}
    	if(y->getNum1()->getType() == "nth_root" && y->getNum2()->getType() != "nth_root")
    	{
    		Number* newLogVal = add(y->getNum1(), x);
    		Number* answer = new Expression(newLogVal, y->getNum2(), '+');
    		return answer;
    	}
    	if(y->getNum2()->getType() == "nth_root" && y->getNum1()->getType() != "nth_root")
    	{
    		Number* newLogVal = add(y->getNum2(), x);
    		Number* answer = new Expression(newLogVal, y->getNum1(), '+');
    		return answer;
    	}
    }

    //Expression + Pi_or_e || Pi_or_e + Expression
    else if(x->getType()=="Expression" && y->getType()=="Pi_or_e")
    {
    	//if first number in Expression is of type Pi_or_e
    	if(x->getNum1()->getType() == "Pi_or_e")
    	{
    		Number* ansNum1 = add(x->getNum1(), y);
    		Number* result = new Expression(ansNum1, x->getNum2(), '+');
    		return result;
    	}
    	//if second number in Expression is of type Pi_or_e
    	else
    	{
    		Number* ansNum2 = add(x->getNum2(), y);
    		Number* result = new Expression(ansNum2, x->getNum1(), '+');
    		return result;
    	}
    }
    else if(x->getType()=="Pi_or_e" && y->getType()=="Expression")
    {
    	//if first number in Expression is of type Pi_or_e
    	if(y->getNum1()->getType() == "Pi_or_e")
    	{
    		Number* ansNum1 = add(y->getNum1(), x);
    		Number* result = new Expression(ansNum1, y->getNum2(), '+');
    		return result;
    	}
    	//if second number in Expression is of type Pi_or_e
    	else
    	{
    		Number* ansNum2 = add(y->getNum2(), x);
    		Number* result = new Expression(ansNum2, y->getNum1(), '+');
    		return result;
    	}
    }

    //Expression + Expression
    else if(x->getType()=="Expression" && y->getType()=="Expression")
    {
    	//Get parameter values of each expression
    	Expression* xExpression = dynamic_cast<Expression*>(x);
    	Expression* yExpression = dynamic_cast<Expression*>(y);
    	char opExp1 = xExpression->getOperator();
    	char opExp2 = yExpression->getOperator();
    	Number* Exp1Num1 = x->getNum1();
    	Number* Exp1Num2 = x->getNum2();
    	Number* Exp2Num1 = y->getNum1();
    	Number* Exp2Num2 = y->getNum2();

    	//return bool values for type equivalencies
    	bool val_13 = (Exp1Num1->getType() == Exp2Num1->getType());
    	bool val_14 = (Exp1Num1->getType() == Exp2Num2->getType());
    	bool val_23 = (Exp1Num2->getType() == Exp2Num1->getType());
    	bool val_24 = (Exp1Num2->getType() == Exp2Num2->getType());

    	//if both Expression operators are '+'
    	if(opExp1 == '+' && opExp2 == '+')
    	{
    		if(val_13 && val_24)
    		{
    			Number* ansNum1 = add(Exp1Num1, Exp2Num1);
    			Number* ansNum2 = add(Exp1Num2, Exp2Num2);
    			Number* result = add(ansNum1, ansNum2);
    			return result;
    		}
    		else if(val_14 && val_23)
    		{
    			Number* ansNum1 = add(Exp1Num1, Exp2Num2);
    			Number* ansNum2 = add(Exp1Num2, Exp2Num1);
    			Number* result = add(ansNum1, ansNum2);
    			return result;
    		}
    		else if(val_13)
    		{
    			Number* ansNum1 = add(Exp1Num1, Exp2Num1);
    			Number* ansNum2 = add(ansNum1, Exp1Num2);
    			Number* result = add(ansNum2, Exp2Num2);
    			return result;
    		}
    		else if(val_14)
    		{
    			Number* ansNum1 = add(Exp1Num1, Exp2Num2);
    			Number* ansNum2 = add(ansNum1, Exp1Num2);
    			Number* result = add(ansNum2, Exp2Num1);
    			return result;
    		}
    		else if(val_23)
    		{
    			Number* ansNum1 = add(Exp1Num2, Exp2Num1);
    			Number* ansNum2 = add(ansNum1, Exp1Num1);
    			Number* result = add(ansNum2, Exp2Num2);
    			return result;
    		}
    		else
    		{
    			Number* ansNum1 = add(Exp1Num2, Exp2Num2);
    			Number* ansNum2 = add(ansNum1, Exp1Num1);
    			Number* result = add(ansNum2, Exp2Num1);
    			return result;
    		}
    	}
    	else if(opExp1 == '+' && opExp2 == '-')
    	{
    		if(val_13 && val_24)
    		{
    			Number* ansNum1 = add(Exp1Num1, Exp2Num1);
    			Number* ansNum2 = subtract(Exp1Num2, Exp2Num2);
    			Number* result = add(ansNum1, ansNum2);
    			return result;
    		}
    		else if(val_14 && val_23)
    		{
    			Number* ansNum1 = subtract(Exp1Num1, Exp2Num2);
    			Number* ansNum2 = add(Exp1Num2, Exp2Num1);
    			Number* result = add(ansNum1, ansNum2);
    			return result;
    		}
    		else if(val_13)
    		{
    			Number* ansNum1 = add(Exp1Num1,Exp2Num1);
    			Number* ansNum2 = add(ansNum1, Exp1Num2);
    			Number* result = subtract(ansNum2, Exp2Num2);
    			return result;
    		}
    		else if(val_14)
    		{
    			Number* ansNum1 = subtract(Exp1Num1, Exp2Num2);
    			Number* ansNum2 = add(ansNum1, Exp1Num2);
    			Number* result = add(ansNum2, Exp2Num1);
    			return result;
    		}
    		else if(val_23)
    		{
    			Number* ansNum1 = add(Exp1Num2, Exp2Num1);
    			Number* ansNum2 = add(ansNum1, Exp1Num1);
    			Number* result = subtract(ansNum2, Exp2Num2);
    			return result;
    		}
    		else
    		{
    			Number* ansNum1 = subtract(Exp1Num2, Exp2Num2);
    			Number* ansNum2 = add(ansNum1, Exp1Num1);
    			Number* result = add(ansNum2, Exp2Num1);
    			return result;
    		}
    	}
    	else if(opExp1 == '-' && opExp2 == '+')
    	{
    		//create result number calling add method with Expression numbers flipped
    		//should go to if statement right above
    		Number* result = add(y, x);
    		return result;
    	}
    	else if(opExp1 == '-' && opExp2 == '-')
    	{
    		if(val_13 && val_24)
    		{
    			Number* ansNum1 = add(Exp1Num1, Exp2Num1);
    			Number* ansNum2 = subtract(Exp1Num2, Exp2Num2);
    			Number* result = subtract(ansNum1, ansNum2);
    			return result;
    		}
    		else if(val_14 && val_23)
    		{
    			Number* ansNum1 = subtract(Exp1Num1, Exp2Num2);
    			Number* ansNum2 = subtract(Exp2Num1, Exp1Num2);
    			Number* result = add(ansNum1, ansNum2);
    			return result;
    		}
    		else if(val_13)
    		{
    			Number* ansNum1 = add(Exp1Num1, Exp2Num1);
    			Number* ansNum2 = subtract(ansNum1, Exp1Num2);
    			Number* result = subtract(ansNum2, Exp2Num2);
    			return result;
    		}
    		else if(val_14)
    		{
    			Number* ansNum1 = subtract(Exp1Num1, Exp2Num2);
    			Number* ansNum2 = subtract(ansNum1, Exp1Num2);
    			Number* result = add(ansNum2, Exp2Num2);
    			return result;
    		}
    		else if(val_23)
    		{
    			//make second number negative
    			Number* nullRational = new Rational(0, 0);
    			Number* negNum = subtract(nullRational, Exp1Num2);

    			//continue calculation as normal
    			Number* ansNum1 = add(negNum, Exp2Num1);
    			Number* ansNum2 = add(ansNum1, Exp1Num1);
    			Number* result = subtract(ansNum2, Exp2Num2);
    			return result;
    		}
    		else
    		{
    			//make second number negative
    			Number* nullRational = new Rational(0, 0);
    			Number* negNum = subtract(nullRational, Exp1Num2);

    			//continuing calculation
    			Number* ansNum1 = subtract(negNum, Exp2Num2);
    			Number* ansNum2 = add(ansNum1, Exp1Num1);
    			Number* result = add(ansNum2, Exp2Num1);
    			return result;
    		}
    	}
    	else if(opExp1 == '/' && opExp2 == '/')
    	{
    		/*if(*Exp1Num2 == *Exp2Num2) we haven't overload the == operator for deferenced numbers
    		{
    			Number* ansNumerator = add(Exp1Num1, Exp2Num1);
    			Number* result = new Expression(ansNumerator, Exp1Num2, '/');
    			return result;
    		}
    		else
    		{*/
    			Number* result = new Expression(x, y, '+');
    			return result;
    		//}
    	}
    	else if(opExp1 == '*' && opExp2 == '*')
    	{
    		/*if((*Exp1Num1 == *Exp2Num1) && (*Exp1Num2 == *Exp2Num2)) we haven't overload the == operator for deferenced numbers
    		{
    			Number* multiplier = new Rational(2,1);
    			Number* result = multiply(multiplier, x);
    			return result;
    		}
    		else
    		{*/
    			Number* result = new Expression(x,y,'+');
    			return result;
    		//}
    	}
    	else
    	{
    		Number* result = new Expression(x, y, '+');
    		return result;
    	}
    }
    else //works
    {
        Number* ans = new Expression(x,y,'+');
    }
}

Number* Calculate::subtract(Number* x, Number* y)
{
	cout << "x to string: " << x->toString() << endl;
	cout << "y to string: " << y->toString() << endl;

    if(x->getType()=="Rational" && y->getType()=="Rational")
    {
	   	//rational and rational
	    int a, b;
	    if(x->isInt()== true && y->isInt()==true) //works
	    {
            a = x->getValueOne()-y->getValueOne();
	        b = 1;
		    Number* ans = new Rational (a, b);
	        return ans;
        }
        else
	    {
	       	//at least one not int"


	        if(x->getValueTwo()==y->getValueTwo())
	        {
	        	cout << "money" << endl;
	            a = x->getValueOne()-y->getValueOne();
	            b = x->getValueTwo();
                Number* ans = new Rational (a, b);

	            return ans;
            }
            else
            {
                b = x->getValueTwo() * y->getValueTwo();
                a = (x->getValueOne()*y->getValueTwo()) - (y->getValueOne()*x->getValueTwo());
                Number* ans = new Rational (a, b);

	            return ans;
            }
        }
    }
    if((x->getType() == "Logarithm"|| x->getType()=="nth_root") && (y->getType()=="Logarithm"||y->getType()=="nth_root"))
    {


        int a, b;
        if(x->isInt()==true && y->isInt()==true)
        {
            int a = x->getValueOne() - y->getValueOne();//simplified log value 1 + value 2
            int b = 1;
            Number* ans = new Rational(a, b);
            return ans;
        }
        else
        {
            ostringstream e;
            e<<x->toString()<<"-"<<y->toString();
            Number* ans = new Exception(e.str());
            return ans;
        }
    }
    if((x->getType()=="pi" || x->getType()=="Pi") && (y->getType()=="pi" || y->getType()=="Pi"))
    {
        int a = x->getValueOne()-y->getValueOne();
        string name = "pi";
        Number* ans = new Pi_or_e(a, name);
        return ans;
    }
    if(x->getType()=="e"&& y->getType()=="e")
    {
        int a = x->getValueOne()-y->getValueOne();
        string name = "e";
        Number* ans = new Pi_or_e(a, name);
        return ans;
    }
    if(x->getType()=="e" && (y->getType()=="pi" || y->getType()=="Pi"))
    {
        ostringstream e;
        e<<x->toString()<<"-"<<y->toString();
        Number* ans = new Exception(e.str());
        return ans;
    }
    if((x->getType()=="pi" || x->getType()=="Pi") && y->getType()=="e")
    {
        ostringstream e;
        e<<x->toString()<<"-"<<y->toString();
        Number* ans = new Exception(e.str());
        return ans;
    }
    /*if(x->getType()=="Exception" && y->getType()=="Exception")
    {
        if(x->toString()==y->toString())
    }
    */
	if(x->getType() == "Rational"  && (y->getType() == "Logarithm"|| y->getType()=="nth_root" ))
	{
	    int a, b;


	    if(x->isInt()==true && y->isInt()==true)
        {
            a=x->getValueOne() - y->getValueOne();//y->getValueOne() how to find the value for simplified log?;
            b=1;
            Number* ans = new Rational(a, b);

            return ans;
        }
        else if(x->isInt() == false && y->isInt()==true)
        {
            a=(x->getValueOne()*y->getValueTwo())-y->getValueOne();//simplified logarithm as an integer
            b=y->getValueTwo();
            Number* ans = new Rational(a, b);

            return ans;
        }
        else
        {
            ostringstream e;
            e<<x->toString()<<"-"<<y->toString();
            Number* ans = new Exception(e.str());
            return ans;
        }
	}
    if((x->getType() == "Logarithm" || x->getType()=="nth_root") && y->getType() == "Rational")
	{
	    int a, b;


	    if(x->isInt()==true && y->isInt()==true)
        {
            a=x->getValueOne() - y->getValueOne(); //how to find the value for simplified log?;
            b=1;
            Number* ans = new Rational(a, b);
            return ans;
        }
        else if(x->isInt() == true && y->isInt()==false)
        {
            a=(x->getValueOne()*y->getValueTwo())-y->getValueOne();//simplified logarithm as an integer
            b=y->getValueTwo();
            Number* ans = new Rational(a, b);

            return ans;
        }
        else
        {
            ostringstream e;
            e<<x->toString()<<"-"<<y->toString();
            Number* ans = new Exception(e.str());
            return ans;
        }
	}
    if(x->getType()=="Rational" && (y->getType()=="Pi" || y->getType()=="pi")) //works
        {
            Number* e = new RationalMinusPi_or_e(x, y);
            return e;
        }
        if((x->getType()=="Pi" || x->getType()=="pi") && y->getType()=="Rational") //works
        {
            Number* e = new Pi_or_eMinusRational(y, x);
            return e;
        }
        if(x->getType()=="Rational" && (y->getType()=="e" || y->getType()=="e"))//works
            {
                Number* e = new RationalMinusPi_or_e(x, y);
                return e;
            }
        if((x->getType()=="e" || x->getType()=="e") && y->getType()=="Rational")//works
            {
                Number* e = new Pi_or_eMinusRational(y, x);
                return e;
            }
        if(x->getType()=="RationalPlusPi_or_e" && y->getType()=="Rational") //works
        {
            Number* ans = new RationalPlusPi_or_e(this->subtract(x->getNum1(), y), x->getNum2());
            return ans;
        }
        if(x->getType()=="Rational" && y->getType()=="RationalPlusPi_or_e") //works
        {
            Number* ans = new RationalPlusPi_or_e(this->subtract(x, y->getNum1()), y->getNum2());
            return ans;
        }
        if(x->getType() == "Rational" && y->getType() == "RationalMinusPi_or_e") // works
        {
        Number* ans = new RationalMinusPi_or_e(this->subtract(x, y->getNum1()), y->getNum2());
        return ans;
        }
        if(x->getType() == "RationalMinusPi_or_e" && y->getType() == "e") //works
        {
        Number* ans = new RationalMinusPi_or_e(x->getNum1(), this->add(x->getNum2(), y));
        return ans;
        }
        if(x->getType() == "e" && y->getType() == "RationalMinusPi_or_e") // rational number is wrong negation of ans
        {
        Number* ans = new RationalPlusPi_or_e(y->getNum1(), this->add(x, y->getNum2()));
        return ans;
        }
        if(x->getType() == "pi" && y->getType() == "RationalMinusPi_or_e")
        {
        Number* ans = new RationalPlusPi_or_e(y->getNum1(), this->add(x, y->getNum2()));
        return ans;
        }
        if(x->getType() == "RationalMinusPi_or_e" && y->getType() == "pi") //works
        {
        Number* ans = new RationalMinusPi_or_e(x->getNum1(), this->add(x->getNum2(), y));
        return ans;
        }
        if(x->getType() == "RationalMinusPi_or_e" && y->getType() == "RationalMinusPi_or_e") //close when both pi or both e
        {
        	Number* num1 = this->subtract(x->getNum1(), y->getNum1());
        	Number* num2 = this->subtract(x->getNum2(), y->getNum2());
        Number* ans = new RationalMinusPi_or_e(num1,num2);
        return ans;
        }
        /*if(x->getType()=="Rational" && y->getType()=="RationalPlusPi_or_e")
        {
            Number* ans = new RationalPlusPi_or_e(this->subtract(x, y->getNum1()), y->getNum2());
            return ans;
        }
        if(x->getType()=="Rational" && y->getType()=="e")
        {
            Number* ratVal = new Rational(x->getValueOne(), x->getValueTwo());
            Number* e = new RationalPlusPi_or_e(ratVal, y);
            return e;
        }
        if(x->getType()=="e" && y->getType()=="Rational")
        {
            Number* ratVal = new Rational(y->getValueOne(), y->getValueTwo());
            Number* e = new RationalPlusPi_or_e(ratVal, x);
            return e;
        }
        if(x->getType()=="RationalPlusPi_or_e" && y->getType()=="RationalPlusPi_or_e")
        {
            Number* ans = new RationalPlusPi_or_e(this->subtract(x->getNum1(), y->getNum1()),this->subtract(x->getNum2(),y->getNum2()));
            return ans;
        }
        if(x->getType()=="e" && y->getType()=="RationalPlusPi_or_e")
        {
        Number* ans = new RationalPlusPi_or_e(y->getNum1(), this->add(x,y->getNum2()));
        return ans;
        }
        if(x->getType()=="pi"||x->getType()=="Pi" && y->getType()=="RationalPlusPi_or_e")
        {
        Number* ans = new RationalPlusPi_or_e(y->getNum1(), this->add(x,y->getNum2()));
        return ans;
        }
        if(x->getType()=="RationalPlusPi_or_e" && y->getType()=="e")
        {
        Number* ans = new RationalPlusPi_or_e(x->getNum1(), this->add(x->getNum2(),y));
        return ans;
        }
        if(x->getType()=="RationalPlusPi_or_e" && y->getType()=="pi" || y->getType()=="Pi")
        {
        Number* ans = new RationalPlusPi_or_e(x->getNum1(), this->add(x->getNum2(),y));
        return ans;
        }*/
    if(x->getType()=="e" && y->getType()=="Logarithm")
    {

        ostringstream e;
        e<<x->toString()<<"-"<<y->toString();
        Number* ans = new Exception(e.str());
        return ans;
    }
    if(x->getType()=="Logarithm" && y->getType()=="e")
    {

        ostringstream e;
        e<<x->toString()<<"-"<<y->toString();
        Number* ans = new Exception(e.str());
        return ans;
    }
    if(x->getType()=="Logarithm" && (y->getType()=="pi"|| y->getType()=="Pi"))
    {

        ostringstream e;
        e<<x->toString()<<"-"<<y->toString();
        Number* ans = new Exception(e.str());
        return ans;
    }
    if((x->getType()=="Pi" || y->getType()=="pi") && y->getType()=="Logarithm")
    {

        ostringstream e;
        e<<x->toString()<<"-"<<y->toString();
        Number* ans = new Exception(e.str());
        return ans;
    }
    if(x->getType()=="e" && y->getType()=="nth_root")
    {

        ostringstream e;
        e<<x->toString()<<"-"<<y->toString();
        Number* ans = new Exception(e.str());
        return ans;
    }
    if(x->getType()=="nth_root" && y->getType()=="e")
    {

        ostringstream e;
        e<<x->toString()<<"-"<<y->toString();
        Number* ans = new Exception(e.str());
        return ans;
    }
    if(x->getType()=="pi" || (x->getType()=="Pi" && y->getType()=="nth_root"))
    {

        ostringstream e;
        e<<x->toString()<<"-"<<y->toString();
        Number* ans = new Exception(e.str());
        return ans;
    }
    if(x->getType()=="nth_root" && (y->getType()=="pi"||y->getType()=="Pi"))
    {

        ostringstream e;
        e<<x->toString()<<"-"<<y->toString();
        Number* ans = new Exception(e.str());
        return ans;
    }
    return 0;
}

// multiply two number pointers
Number* Calculate::multiply(Number* a, Number* b) {
	// multiply two rational numbers
	if (a->getType() == "Rational" && b->getType() == "Rational") {
		int newNum, newDenom;


		// both rationals are ints (denominators = 1)
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the first rational number is an int
		else if (a->isInt() == true && b->isInt() == false) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = b->getValueTwo();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the second rational number is an int
		else if (a->isInt() == false && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = a->getValueTwo();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// both rational numbers are not ints
		else if (a->isInt() == false && b->isInt() == false) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = a->getValueTwo() * b->getValueTwo();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply a rational number and a logarithm
	else if (a->getType() == "Rational" && b->getType() == "Logarithm") {
		int newNum, newDenom;


		// both the rational and logarithm simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the rational simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << "*" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the logarithm simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = a->getValueTwo();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// neither simplifies to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << "(" << a->getValueOne() << "*" << b->toString() << ")" << "/" << a->getValueTwo();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// multiply a logarithm and a rational number
	else if (a->getType() == "Logarithm" && b->getType() == "Rational") {
		int newNum, newDenom;


		// both the logarithm and the rational simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the logarithm simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = b->getValueTwo();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the rational simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << "*" << a->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither simplify to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << "(" << b->getValueOne() << "*" << a->toString() << ")" << "/" << b->getValueTwo();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//__________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________

	// multiply a rational number and an nth_root
	else if (a->getType() == "Rational" && b->getType() == "nth_root") {
		int newNum, newDenom;


		// both the rational and the nth_root simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the rational simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << "*" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the nth_root simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = a->getValueTwo();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// neither simplify to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << "(" << a->getValueOne() << "*" << b->toString() << ")" << "/" << a->getValueTwo();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//__________________________________________________________________________________________________________________________

	// multiply an nth_root and a rational number
	else if (a->getType() == "nth_root" && b->getType() == "Rational") {
		int newNum, newDenom;


		// both the nth_root and the rational simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the nth_root simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = b->getValueTwo();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the rational simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << "*" << a->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither simplify to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << "(" << b->getValueOne() << "*" << a->toString() << ")" << "/" << b->getValueTwo();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply a rational number with pi
		else if (a->getType() == "Rational" && b->getType() == "pi")
		{
			// rational number simplifies to int
			if (a->isInt() == true)//works
			{
				Number* output = new Pi_or_e(b->getValueOne()*a->getValueOne(), "pi");
				return output;
			}
			// rational number does not simplify to int
			else if (a->isInt() == false) {
				ostringstream oss;
				oss << "(" << a->getValueOne() << "pi" << ")" << "/" << a->getValueTwo();
				Number* exc = new Exception(oss.str());
				return exc;
			}
		}

//______________________________________________________________________________________________________________________________________________

	// multiply pi with a rational number
	else if (a->getType() == "pi" && b->getType() == "Rational") {

		// rational number simplifies to int
		if (b->isInt() == true) {//works
			Number* output = new Pi_or_e(b->getValueOne()*a->getValueOne(), "pi");
			return output;
		}
		// rational number does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << "(" << b->getValueOne() << "pi" << ")" << "/" << b->getValueTwo();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply a rational number with e
	else if (a->getType() == "Rational" && b->getType() == "e") {

		if (a->isInt() == true) {//works
			Number* output = new Pi_or_e(b->getValueOne()*a->getValueOne(), "e");
			return output;
		}
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << "(" << a->getValueOne() << "e" << ")" << "/" << a->getValueTwo();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// multiply e with a rational number
	else if (a->getType() == "e" && b->getType() == "Rational") {

		if (b->isInt() == true) {//works
			Number* output = new Pi_or_e(b->getValueOne()*a->getValueOne(), "e");
			return output;
		}
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << "(" << b->getValueOne() << a->toString() << ")" << "/" << b->getValueTwo();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply two logs
	else if (a->getType() == "Logarithm" && b->getType() == "Logarithm") {
		int newNum, newDenom;


		// both logs simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the first log simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the second log simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << a->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither log simplifies to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "*" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply a log and an nth root
	else if (a->getType() == "Logarithm" && b->getType() == "nth_root") {
		int newNum, newDenom;


		// both the log and nth_root simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the log simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the nth_root simplifies to an
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << a->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither simplifies to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "*" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// multiply an nth_root with a log
	else if (a->getType() == "nth_root" && b->getType() == "Logarithm") {
		int newNum, newDenom;


		// both the log and nth_root simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the nth_root simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the logarithm simplifies to an
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << a->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither simplifies to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "*" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply a logarithm with pi
	else if (a->getType() == "Logarithm" && b->getType() == "pi") {

		// logarithm simplifies to int
		if (a->isInt() == true) {
			ostringstream oss;
			oss << a->getValueOne() << "pi";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// logarithm does not simplify to int
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "*" << "pi";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// multiply pi with a logarithm
	else if (a->getType() == "pi" && b->getType() == "Logarithm") {

		// logarithm simplifies to int
		if (b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << "pi";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// logarithm does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << b->toString() << "*" << "pi";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply a logarithm with e
	else if (a->getType() == "Logarithm" && b->getType() == "e") {

		// logarithm simplifies to int
		if (a->isInt() == true) {
			ostringstream oss;
			oss << a->getValueOne() << "e";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// logarithm does not simplify to int
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "*" << "e";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// multiply e with a logarithm
	else if (a->getType() == "e" && b->getType() == "Logarithm") {

		// logarithm simplifies to int
		if (b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << "e";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// logarithm does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << b->toString() << "*" << "e";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply two nth_roots
	else if (a->getType() == "nth_root" && b->getType() == "nth_root") {
		int newNum, newDenom;


		// both nth_roots simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() * b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the first nth_root simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << "*" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the second nth_root simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << "*" << a->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither nth_root simplifies to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "*" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply an nth_root and pi
	else if (a->getType() == "nth_root" && b->getType() == "pi") {

		// nth_root simplifies to int
		if (a->isInt() == true) {
			ostringstream oss;
			oss << a->getValueOne() << "pi";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// nth_root does not simplify to int
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << b->toString() << "*" << "pi";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// multiply pi with an nth_root
	else if (a->getType() == "pi" && b->getType() == "nth_root") {

		// nth_root simplifies to int
		if (b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << "pi";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// nth_root does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "*" << "pi";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply an nth_root with e
	else if (a->getType() == "nth_root" && b->getType() == "e") {

		// nth_root simplifies to int
		if (a->isInt() == true) {
			ostringstream oss;
			oss << a->getValueOne() << "e";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// nth_root does not simplify to int
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << b->toString() << "*" << "e";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// multiply e with an nth_root
	else if (a->getType() == "e" && b->getType() == "nth_root") {

		// nth_root simplifies to int
		if (b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << "e";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// nth_root does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "*" << "e";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// multiply pi with pi
	else if (a->getType() == "pi" && b->getType() == "pi") {
		int coeff1 = a->getValueOne();
		int coeff2 = b->getValueOne();
		ostringstream oss;
		oss << coeff1*coeff2 << "pi^2";
		Number* exc = new Exception(oss.str());
		return exc;
	}

//______________________________________________________________________________________________________________________________________________

	// multiply pi with e or e with pi
	else if ((a->getType() == "pi" && b->getType() == "e") || (a->getType() == "e" && b->getType() == "pi")) {
		int coeff1 = a->getValueOne();
		int coeff2 = b->getValueOne();
		ostringstream oss;
		oss << coeff1*coeff2 << "pi*e";
		Number* exc = new Exception(oss.str());
		return exc;
	}

//______________________________________________________________________________________________________________________________________________

	// multiply e with e
	else if (a->getType() == "e" && b->getType() == "e") {
		int coeff1 = a->getValueOne();
		int coeff2 = b->getValueOne();
		ostringstream oss;
		oss << coeff1*coeff2 << "e^2";
		Number* exc = new Exception(oss.str());
		return exc;
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________
	// foil; example: (3+pi)*(3+pi)
		else if (a->getType() == "RationalPlusPi_or_e" && b->getType() == "RationalPlusPi_or_e") { // works
			Number* num1 = this->multiply(a->getNum1(), b->getNum1());
			Number* num2 = this->multiply(a->getNum1(), b->getNum2());
			Number* num3 = this->multiply(a->getNum2(), b->getNum1());
			Number* num4 = this->add(num2, num3);
			Number* num5 = this->multiply(a->getNum2(), b->getNum2());

			ostringstream oss;
			oss << num1->toString() << "+" << num4->toString() << "+" << num5->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}

		else if (a->getType() == "RationalPlusPi_or_e" && b->getType() == "RationalMinusPi_or_e") { // works
			Number* num1 = this->multiply(a->getNum1(), b->getNum1());
			Number* num2 = this->multiply(a->getNum1(), b->getNum2());
			Number* num3 = this->multiply(a->getNum2(), b->getNum1());
			Number* num4 = this->subtract(num2, num3);
			Number* num5 = this->multiply(a->getNum2(), b->getNum2());

			ostringstream oss;
			oss << num1->toString() << "+" << num4->toString() << "-" << num5->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}

		else if (a->getType() == "RationalMinusPi_or_e" && b->getType() == "RationalPlusPi_or_e") {
			Number* num1 = this->multiply(a->getNum1(), b->getNum1());
			Number* num2 = this->multiply(a->getNum1(), b->getNum2());
			Number* num3 = this->multiply(a->getNum2(), b->getNum1());
			Number* num4 = this->subtract(num2, num3);
			Number* num5 = this->multiply(a->getNum2(), b->getNum2());

			ostringstream oss;
			oss << num1->toString() << "+" << num4->toString() << "-" << num5->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}

}

Number* Calculate::divide(Number* a, Number* b) {
	// divide two rational numbers
	if (a->getType() == "Rational" && b->getType() == "Rational") {
		if(b->getValueOne() == 0)
		{
			return new Exception("You can not divide by zero");
		}
		int newNum, newDenom;
		// both rationals are ints (denominators = 1)
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne();
			newDenom = b->getValueOne();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the first rational number is an int
		else if (a->isInt() == true && b->isInt() == false) {
			newNum = a->getValueOne() * b->getValueTwo();
			newDenom = b->getValueOne();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the second rational number is an int
		else if (a->isInt() == false && b->isInt() == true) {
			newNum = a->getValueOne();
			newDenom = a->getValueTwo() * b->getValueOne();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// both rational numbers are not ints
		else if (a->isInt() == false && b->isInt() == false) {
			newNum = a->getValueOne() * b->getValueTwo();
			newDenom = a->getValueTwo() * b->getValueOne();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide a rational number by a logarithm
	else if (a->getType() == "Rational" && b->getType() == "Logarithm") {
		int newNum, newDenom;


		// both the rational and logarithm simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() / b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the rational simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << "(" << a->getValueOne() << "/" << b->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the logarithm simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			newNum = a->getValueOne();
			newDenom = a->getValueTwo() * b->getValueOne();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// neither simplifies to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << "/" << "(" << a->getValueTwo() << b->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// divide a logarithm by a rational number
	else if (a->getType() == "Logarithm" && b->getType() == "Rational") {
		int newNum, newDenom;


		// both the logarithm and the rational simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() / b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the logarithm simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			newNum = a->getValueOne() * b->getValueTwo();
			newDenom = b->getValueOne();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the rational simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << a->toString() << "/" << b->getValueOne();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither simplify to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << "(" << b->getValueTwo() << "*" << a->toString() << ")" << "/" << b->getValueOne();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//__________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________

	// divide a rational number by an nth_root
	else if (a->getType() == "Rational" && b->getType() == "nth_root") {
		int newNum, newDenom;


		// both the rational and the nth_root simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() / b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the rational simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << "(" << a->getValueOne() << "/" << b->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the nth_root simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			newNum = a->getValueOne();
			newDenom = a->getValueTwo() * b->getValueOne();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// neither simplify to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << "/" << "(" << a->getValueTwo() << b->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//__________________________________________________________________________________________________________________________

	// divide an nth_root by a rational number
	else if (a->getType() == "nth_root" && b->getType() == "Rational") {
		int newNum, newDenom;


		// both the nth_root and the rational simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() / b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the nth_root simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			newNum = a->getValueOne() * b->getValueTwo();
			newDenom = b->getValueOne();
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the rational simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << a->toString() << "/" << b->getValueOne();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither simplify to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << "(" << b->getValueTwo() << "*" << a->toString() << ")" << "/" << b->getValueOne();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide a rational number by pi
	else if (a->getType() == "Rational" && b->getType() == "pi") {

		// rational number simplifies to int
		if (a->isInt() == true) {
			ostringstream oss;
			oss << a->getValueOne() << "/" << "pi";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// rational number does not simplify to int
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << "/" << "(" << a->getValueTwo() << "pi" << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// divide pi by a rational number
	else if (a->getType() == "pi" && b->getType() == "Rational") {

		// rational number simplifies to int
		if (b->isInt() == true) {
			ostringstream oss;
			oss << "pi" << "/" << b->getValueOne();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// rational number does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << "(" << b->getValueTwo() << "pi" << ")" << "/" << b->getValueOne();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide a rational number by e
	else if (a->getType() == "Rational" && b->getType() == "pi") {

		// rational number simplifies to int
		if (a->isInt() == true) {
			ostringstream oss;
			oss << a->getValueOne() << "/" << "e";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// rational number does not simplify to int
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << "/" << "(" << a->getValueTwo() << "e" << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// divide e by a rational number
	else if (a->getType() == "pi" && b->getType() == "Rational") {

		// rational number simplifies to int
		if (b->isInt() == true) {
			ostringstream oss;
			oss << "e" << "/" << b->getValueOne();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// rational number does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << "(" << b->getValueTwo() << "e" << ")" << "/" << b->getValueOne();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide two logs
	else if (a->getType() == "Logarithm" && b->getType() == "Logarithm") {
		int newNum, newDenom;


		// both logs simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() / b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the first log simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << "/" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the second log simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << "/" << a->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither log simplifies to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "/" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide a log by an nth root
	else if (a->getType() == "Logarithm" && b->getType() == "nth_root") {
		int newNum, newDenom;


		// both the log and nth_root simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() / b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the log simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << "/" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the nth_root simplifies to an
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << "/" << a->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither simplifies to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "/" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// divide an nth_root by a log
	else if (a->getType() == "nth_root" && b->getType() == "Logarithm") {
		int newNum, newDenom;


		// both the log and nth_root simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() / b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the nth_root simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << a->getValueOne() << "/" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the logarithm simplifies to an
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << b->getValueOne() << "/" << a->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither simplifies to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "/" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide a logarithm by pi
	else if (a->getType() == "Logarithm" && b->getType() == "pi") {

		// logarithm simplifies to int
		if (a->isInt() == true) {
			ostringstream oss;
			oss << "(" << a->getValueOne() << "/" << "pi" << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// logarithm does not simplify to int
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << "(" << a->toString() << "/" << "pi" << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// divide pi by a logarithm
	else if (a->getType() == "pi" && b->getType() == "Logarithm") {

		// logarithm simplifies to int
		if (b->isInt() == true) {
			ostringstream oss;
			oss << "(" << "pi" << "/" << b->getValueOne() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// logarithm does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << "(" << "pi" << "/" << b->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide a logarithm by e
	else if (a->getType() == "Logarithm" && b->getType() == "e") {

		// logarithm simplifies to int
		if (a->isInt() == true) {
			ostringstream oss;
			oss << "(" << a->getValueOne() << "/" << "e" << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// logarithm does not simplify to int
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << "(" << a->toString() << "/" << "e" << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// divide e by a logarithm
	else if (a->getType() == "pi" && b->getType() == "Logarithm") {

		// logarithm simplifies to int
		if (b->isInt() == true) {
			ostringstream oss;
			oss << "(" << "e" << "/" << b->getValueOne() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// logarithm does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << "(" << "e" << "/" << b->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide two nth_roots
	else if (a->getType() == "nth_root" && b->getType() == "nth_root") {
		int newNum, newDenom;


		// both nth_roots simplify to ints
		if (a->isInt() == true && b->isInt() == true) {
			newNum = a->getValueOne() / b->getValueOne();
			newDenom = 1;
			Number* ans = new Rational(newNum, newDenom);

			return ans;
		}
		// only the first nth_root simplifies to an int
		else if (a->isInt() == true && b->isInt() == false) {
			ostringstream oss;
			oss << "(" << a->getValueOne() << "/" << b->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// only the second nth_root simplifies to an int
		else if (a->isInt() == false && b->isInt() == true) {
			ostringstream oss;
			oss << "(" << b->getValueOne() << "/" << a->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// neither nth_root simplifies to an int
		else if (a->isInt() == false && b->isInt() == false) {
			ostringstream oss;
			oss << a->toString() << "/" << b->toString();
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide an nth_root by pi
	else if (a->getType() == "nth_root" && b->getType() == "pi") {

		// nth_root simplifies to int
		if (a->isInt() == true) {
			ostringstream oss;
			oss << "(" << a->getValueOne() << "pi" << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// nth_root does not simplify to int
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << "(" << b->toString() << "/" << "pi" << ")"; // do we call toString() on the pi object?
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// divide pi by an nth_root
	else if (a->getType() == "pi" && b->getType() == "nth_root") {

		// nth_root simplifies to int
		if (b->isInt() == true) {
			ostringstream oss;
			oss << "(" << "pi" << "/" << b->getValueOne() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// nth_root does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << "(" << "pi" << "/" << b->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide an nth_root by e
	else if (a->getType() == "nth_root" && b->getType() == "e") {

		// nth_root simplifies to int
		if (a->isInt() == true) {
			ostringstream oss;
			oss << "(" << a->getValueOne() << "/" << "e" << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// nth_root does not simplify to int
		else if (a->isInt() == false) {
			ostringstream oss;
			oss << "(" << a->toString() << "/" << "e" << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________

	// divide e by an nth_root
	else if (a->getType() == "pi" && b->getType() == "nth_root") {

		// nth_root simplifies to int
		if (b->isInt() == true) {
			ostringstream oss;
			oss << "(" << "e" << "/" << b->getValueOne() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
		// nth_root does not simplify to int
		else if (b->isInt() == false) {
			ostringstream oss;
			oss << "(" << "e" << "/" << b->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________

	// divide pi by pi
	else if (a->getType() == "pi" && b->getType() == "pi") {
		int newNum, newDenom, coeff1, coeff2;
		coeff1 = a->getValueOne();
		coeff2 = b->getValueOne();
		newNum = coeff1;
		newDenom = coeff2;
		Number* exc = new Rational(coeff1, coeff2);
		exc->simplify();
		return exc;
	}

//______________________________________________________________________________________________________________________________________________

	// divide pi with e
	else if (a->getType() == "pi" && b->getType() == "e") {
		int coeff1, coeff2;
		coeff1 = a->getValueOne();
		coeff2 = b->getValueOne();
		Number* newCoeff = new Rational(coeff1, coeff2);
		newCoeff->simplify();
		ostringstream oss;
		oss << "(" << newCoeff->toString() << ")" << "pi/e";
		Number* exc = new Exception(oss.str());
		return exc;
	}

//______________________________________________________________________________________________________________________________________________

	// divide e with pi
	else if (a->getType() == "e" && b->getType() == "pi") {
		int coeff1, coeff2;
		coeff1 = a->getValueOne();
		coeff2 = b->getValueOne();
		Number* newCoeff = new Rational(coeff1, coeff2);
		newCoeff->simplify();
		ostringstream oss;
		oss << "(" << newCoeff->toString() << ")" << "e/pi";
		Number* exc = new Exception(oss.str());
		return exc;
	}

//______________________________________________________________________________________________________________________________________________

	// divide e by e
	else if (a->getType() == "e" && b->getType() == "e") {
		int newNum, newDenom, coeff1, coeff2;
		coeff1 = a->getValueOne();
		coeff2 = b->getValueOne();
		newNum = coeff1;
		newDenom = coeff2;
		Number* exc = new Rational(coeff1, coeff2);
		exc->simplify();
		return exc;
	}

//______________________________________________________________________________________________________________________________________________
//______________________________________________________________________________________________________________________________________________
	//divide a (rational and piore) by (rational and piore) example: (3+pi)/(4+pi)
		else if (a->getType() == "RationalPlusPi_or_E" && b->getType() == "RationalPlusPi_or_E") {
			if (a->getNum1() ==  b->getNum1() && a->getNum2() == b->getNum2()) {
				Number* rash = new Rational(1,1);
				return rash;
			}
			ostringstream oss;
			oss << "(" << a->toString() << ")" << "/" << "(" << b->toString() << ")";
			Number* exc = new Exception(oss.str());
			return exc;
		}
}

Number* Calculate::exponentiate(Number* a, Number* b)
{

	if(a->getType() == "Rational" && b->getType() == "Rational" && a->isInt() == true && b ->isInt() == true)
    {
        int newNum = pow(a->getValueOne(), b->getValueOne());
        int newDenom = 1;
        Number* ans = new Rational(newNum, newDenom);
        return ans;
    }

    //if(a->getType() == "Rational" && b->getType() == "Rational" && a->isInt() == true && b ->isInt() == false)
    //{

    //}

    if(a->getType() == "Rational" && (b->getType() == "pi" || b->getType() == "e"))
    {
        int newNum = a->getValueOne();
        int newDenom = a->getValueTwo();
        Number* firstNum = new Rational(newNum, newDenom);

        ostringstream exception;

        if(b->getType() == "pi")
        {
            exception << "(" << firstNum->toString() << ")" << "^pi";
            Number* ans = new Exception(exception.str());
            return ans;
        }
        else if(b->getType() == "e")
        {
            exception << "(" << firstNum->toString() << ")" << "^e";
            Number* ans = new Exception(exception.str());
            return ans;
        }
        return firstNum;
    }

    /*if((a->getType()=="pi"||a->getType()=="e") && b->getType()=="Rational")
    {
        ostringstream piExp;

        if(b->getValueTwo()==1)
        {
            if(a->getType()=="pi")
            {
                piExp << "pi^" << b->toString();
            }
            else
            {
                piExp << "e^" << b->toString();
            }

            Number* ans = new Exception(piExp.str());
            return ans;
        }
        else
        {
            Number* ans = new Exception("");
            return ans;
        }
    }*/

    if((a->getType()=="pi"||a->getType()=="e") && (b->getType()=="pi"||b->getType()=="e"))
    {
        ostringstream result;
        result << a->toString() << "^" << b->toString();

        Number* ans = new Exception(result.str());

        return ans;
    }

    /*if(a->getType()=="Exception" && b->getType()=="Exception")
    {
        ostringstream newExp;
        newExp << a->toString() << "^" << b->toString();
        queue<string> output = shuntingYardAlgorithm(newExp.str());
        Number* result = evaluate(output);
        return result;
    }*/
    if(a->getType() == "Rational" && b->getType()=="Rational")
    {

        int firstNum = a->getValueOne();
        int firstDenom = a->getValueTwo();

        int secondNum = b->getValueOne();
        int secondDenom = b->getValueTwo();

        if(secondNum < 0 || secondDenom < 0)
        {
        	int temp = firstNum;
        	firstNum = firstDenom;
        	firstDenom = temp;

            if(secondNum < 0)
            {
            	secondNum *= -1;
            }

            if(secondDenom < 0)
            {
            	secondDenom *= -1;
            }
        }

        if(secondDenom == 1)
        {
            int resultNum = pow(firstNum, secondNum);
            int resultDenom = pow(firstDenom, secondNum);

            Number* ans = new Rational(resultNum, resultDenom);
            return ans;
        }
        else
        {
            int resultNum = pow(firstNum, secondNum);
            int resultDenom = pow(firstDenom, secondNum);

            Number* rat = new Rational(resultNum, resultDenom);
            rat->simplify();

            if(rat->isInt()==true)
            {
                int base = rat->getValueOne();
                Number* root = new nth_root(base, secondDenom);
                return root;
            }
            else
            {
            	nth_root* finalNumerator = new nth_root(firstNum, secondDenom);
            	nth_root* finalDenom = new nth_root(firstDenom, secondDenom);
            	Rational* rat2 = new Rational(finalNumerator->getValueOne(), finalDenom->getValueOne());
            	return rat2;
            }
        }
    }
    if((a->getType() == "e" || a->getType() == "pi") && b->getType() == "Rational")
    {
    	return new Pi_or_ePowerRational(b,a);
    }

    Number* num = new Rational(1,1);
	return num;
}

Number* Calculate::root(Number* x, Number* y)
{
	//The following code assumes x and y are ints. This class will need a lot of work in order to be fully functional
	if(x->getType() == "Rational" && y->getType() == "Rational" && x->isInt() && y->isInt())
	{
		bool xNegative = false;
		if(x->getValueOne() < 0)
		{
			xNegative = true;
			x = new Rational(-1*x->getValueOne(), x->getValueTwo());
		}
		if(x->getValueTwo() < 0)
		{
			xNegative = true;
			x = new Rational(x->getValueOne(), -1*x->getValueTwo());
		}

		Number* result;
		if(xNegative)
		{
			Number* resultPartOne = new nth_root(y->getValueOne(),x->getValueOne());
			Number* one = new Rational(1,1);
			result = new Expression(one,resultPartOne,'/') ;
		}
		else
		{
			result = new nth_root(y->getValueOne(),x->getValueOne());
		}
	return result;
	}
	else
	{
		Number* result = new Rational(1,1);
		return result;
	}
}
//jowb63@bellsouth.net


