//
//  RationalPlusPi_or_e.h
//  CppProject
//
//  Created by Medhir Bhargava on 4/13/14.
//  Copyright (c) 2014 Medhir Bhargava. All rights reserved.
//

#ifndef __CppProject__RationalPlusPi_or_e__
#define __CppProject__RationalPlusPi_or_e__

#include <iostream>
#include "Exception.h"
#include "Number.h"

using namespace std;

class RationalPlusPi_or_e: public Exception
{
public:
    RationalPlusPi_or_e();
    RationalPlusPi_or_e(Number* ratVal, Number* pi_eVal);
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

#endif /* defined(__CppProject__RationalPlusPi_or_e__) */
