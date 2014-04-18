//
//  Pi_or_ePowerRational.h
//  CppProject
//
//  Created by Medhir Bhargava on 4/13/14.
//  Copyright (c) 2014 Medhir Bhargava. All rights reserved.
//

#ifndef __CppProject__Pi_or_ePowerRational__
#define __CppProject__Pi_or_ePowerRational__

#include <iostream>
#include "Exception.h"
#include "Number.h"

using namespace std;

class Pi_or_ePowerRational: public Exception
{
public:
    Pi_or_ePowerRational();
    Pi_or_ePowerRational(Number* ratVal, Number* pi_eVal);
    string getType();
    int getValueOne();
	Number* getNum1();
	Number* getNum2();
    int getValueTwo();
    bool isInt();
    void simplify();
    string toString();
    
private:
    Number* ratVal;
    Number* pi_eVal;
};

#endif /* defined(__CppProject__Pi_or_ePowerRational__) */

