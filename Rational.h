#include <iostream>
#include <string>
#include "Number.h"
using namespace std;

class Rational: public Number
{
    public:
        Rational(int num, int denom){
            this->num = num;
            this->denom = denom;
            this->simplify();
        }
        ~Rational(){};
        string getType();
        int getNumerator();
        int getDenominator();
        void simplify();
        bool isInt();
        string toString();
        int getValueOne();
        int getValueTwo();
        //Rational add(Rational*, Rational*);
        //Rational subtract(Rational*, Rational*);
		Number* getNum1();
		Number* getNum2();
		void reduce(int numerator, int denominator);
   private:
        int num;
        int denom;

};
