#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Rational.h"
using namespace std;

vector<int> factor(vector<int> &factors,int num, int n = 2)
{
	if(num < 0)
	{
		num *= -1;
	}
        if (num % n == 0) {
                factors.push_back(n);
                factor(factors, num / n, n);
        }

        else if (n <= num) {
                factor(factors, num, n + 1);
        }

            return factors;
}

void Rational::reduce(int numerator, int denominator) {
	bool negative = false;

	if(numerator < 0 || denominator < 0)
	{
		negative = true;
	}
	vector<int> factorNumerator;
    factor(factorNumerator,numerator,2);

	vector<int> factorDenominator;
    factor(factorDenominator,denominator,2);

    for(int i = 0; i < factorNumerator.size(); i++) {
    	for(int j = 0; j < factorDenominator.size(); j++) {
    		if(factorNumerator[i] == factorDenominator[j]) {
    			factorNumerator[i] = 1;
    			factorDenominator[j] = 1;
    		}
    	}
    }

    numerator = 1;
    denominator = 1;

    for (int i = 0; i < factorNumerator.size();i++) {
    	numerator = numerator * factorNumerator[i];
    }

    for (int j = 0; j < factorDenominator.size(); j++) {
    	denominator = denominator * factorDenominator[j];
    }

    if(negative)
    {
        this->num = numerator * -1;
    }
    else
    {
    	this->num = numerator;
    }
    this->denom = denominator;
}

string Rational::getType(){
    string type = "Rational";
    return type;
}
int Rational::getNumerator(){
    return num;
}
int Rational::getDenominator(){
    return denom;
}
void Rational::simplify(){

    if(num==0 && denom !=0){
        num = 0;
        denom = 1;
    }
    else if(num>denom && num%denom==0){
            num = num/denom;
            denom = 1;
    }
    else if(num==denom){
        num = 1;
        denom = 1;
    }
    else{
        if(denom%num==0){
            denom = denom/num;
            num = 1;
        }
        else if(denom == 1)
        {

        }
        else{
        	reduce(num, denom);
                }
            }
        }
bool Rational::isInt(){
    if(denom==1){
        return true;
    }
    else{
        return false;
    }
}
string Rational::toString(){
    ostringstream strBuilder;
    ostringstream integer;
    integer<<num;
    strBuilder<<num<<"/"<<denom;
    if(isInt()==true){
        string i = integer.str();
        return i;
    }
    else{
        string s = strBuilder.str();
        return s;
    }
}

int Rational::getValueOne()
{
	return num;
}

int Rational::getValueTwo()
{
	return denom;
}

Number* Rational::getNum1()
{
	return NULL;
}

Number* Rational::getNum2()
{
	return NULL;
}
