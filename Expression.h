#include <iostream>
#include <string>
#include "Number.h"
using namespace std;

class Expression: public Number
{
    public:
        Expression(Number* num1, Number* num2, char op){
            this->num1 = num1;
            this->num2 = num2;
            this->op = op;
        }
        ~Expression(){};
        string getType();
        Number* getNum1();
        Number* getNum2();
        char getOperator();
        void simplify();
        bool isInt();
        string toString();
        int getValueOne();
        int getValueTwo();
        //Rational add(Rational*, Rational*);
        //Rational subtract(Rational*, Rational*);
   private:
        Number* num1;
        Number* num2;
        char op;

};
