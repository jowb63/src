/*
 * nth_root.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: Benjamin
 */

#include "nthroot.h"
#include <cmath>
#include <stdexcept>
#include <sstream>
using namespace std;

//valueOne is base, valueTwo is power

nth_root::nth_root() {
	this->base = 1;
	this->power = 1;
	this->coefficient = 1;
}

nth_root::nth_root(int base, int power) {
	this->base = base;
	this->power = power;
	this->coefficient = 1;
	this->simplify();
}

string nth_root::getType() {
  return "nth_root";
}

int nth_root::getValueOne() {
	if(isInt() == true) {
		return coefficient;
	}
	else {
	return base;
	}
}

int nth_root::getValueTwo() {
	return power;
}

double nth_root::getValue() {
	double value;
	value = pow(((double)base),(1/((double)power)));
	return value;
}

vector<int> nth_root::factorization(vector<int> &factors,int num, int n = 2)
{
	if(num < 0) {
		num = -1 * num;
	}
        if (num % n == 0) {
                factors.push_back(n);
                factorization(factors, num / n, n);
        }

        else if (n <= num) {
                factorization(factors, num, n + 1);
        }

        return factors;
}




void nth_root::simplify() {
	vector<int> factors;
	factorization(factors,base,2);

	int outside_root = 1;
	int inside_root = 1;;
	vector<int> unusedFactors;
	vector<int> usedFactors;

//	int tempPower = power;
//	if(power < 0) {
//		power = power * -1;
//	}


	try {

		if(base < 0 && power % 2 == 0) {
			throw invalid_argument("Invalid argument");
		}

	int numCount = 1;

	for(int i = 0; i < factors.size(); i++) {

		if(factors[i] != 1) {

	for(int j = i+1; j < factors.size(); j++) {

		if(factors[i] == factors[j]) {
			  numCount = numCount + 1;
			  factors[j] = 1;
		  }
	  }

	 if (numCount % power == 0) {
			   int a;
			   a = pow(factors[i],numCount/power);
			   usedFactors.push_back(a);
		   }
		   else {
			   int a,b;
			   a = pow(factors[i],numCount/power);
			   b = pow(factors[i],numCount%power);
			   usedFactors.push_back(a);
			   unusedFactors.push_back(b);
		   }
		   numCount = 1;
	   }
	}
              for(int i = 0; i < usedFactors.size(); i++) {
            	  outside_root = outside_root * usedFactors[i];
              }


				for (int j = 0; j < unusedFactors.size(); j++) {
					inside_root  = inside_root * unusedFactors[j];
				}

//	 if (tempPower < 1) {
//		 outside_root = (1/outside_root);
//	 }

	 if (base < 1 && (power % 2 == 1)) {
	   outside_root = -1 * outside_root;
	 }
	 base = inside_root;
	 coefficient = outside_root;
	}
	catch (invalid_argument e) {
		cout<<"Can't take the even root of a negative number "<<endl;
		cout<<"Source: " <<base<<endl;
	}
}



bool nth_root::isInt() {
	if(base == 1){
		return true;
	}
	else {
		return false;
	}
}


string nth_root::toString() {
	ostringstream s;
	if(isInt() == true) {
		s<<coefficient;
		return s.str();
	}
	else if (coefficient == 1) {
        s<<power<<"rt:"<<base;
		return s.str();
	}
	else {
		s<<coefficient<<" * "<<power<<"rt:"<<base;
		return s.str();
	}
}

Number* nth_root::getNum1()
{
	return NULL;
}

Number* nth_root::getNum2()
{
	return NULL;
}
