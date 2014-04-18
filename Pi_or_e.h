#include <iostream>
#include <string>
#include "Number.h"
using namespace std;

class Pi_or_e:public Number{
    public:
        Pi_or_e(int coefficient, string name){
            this->name = name;
            this->coefficient = coefficient;
        }
        string getType();
        string getName();
        int getValueOne();
        int getValueTwo();
        bool isInt();
        int getCoefficient();
        void simplify();
        double getValue();
        string toString();
		Number* getNum1();
		Number* getNum2();

    private:
        string name;
        int coefficient;
};
