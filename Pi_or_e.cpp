#include <iostream>
#include <sstream>
#include "Pi_or_e.h"
using namespace std;

string Pi_or_e::getType(){
    if(name == "pi" || name == "Pi")
    {
        return "pi";
    }
    else if(name == "e")
    {
        return "e";
    }
    else
    {
        return "Not pi or e";
    }
}
string Pi_or_e::getName(){
    return name;
}
int Pi_or_e::getValueOne(){
    return coefficient;
}
int Pi_or_e::getValueTwo(){
    return 0;
}
bool Pi_or_e::isInt(){
    if(getCoefficient()==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Pi_or_e::simplify(){
}
int Pi_or_e::getCoefficient(){
    return coefficient;
}
double Pi_or_e::getValue(){
    if(name=="Pi" || name=="pi")
    {
        double val = coefficient*3.14;
        return val;
    }
    else if(name=="e")
    {
        double val = coefficient*2.71;
        return val;
    }
}
string Pi_or_e::toString()
{
	ostringstream output;
	if(this->name == "pi" || this->name == "Pi")
	{
		output << coefficient << "pi";
		return output.str();;
	}
	else
	{
		output << coefficient << "e";
		return output.str();;
	}

    /*ostringstream s1;
    ostringstream s2;
    ostringstream s3;
    ostringstream s4;
    ostringstream s5;
    ostringstream s6;
    int x = 0;

    s1<<coefficient<<"pi";
    s2<<coefficient<<"e";
    s3<<"pi";
    s4<<x;
    s5<<"e";
    if((getName()== "Pi" || getName() == "pi") && coefficient == 1)
    {
        string a = s3.str();
        return a;
        if(coefficient==0)
        {
            string b = s4.str();
            return b;
        }
        else{
            string c = s1.str();
            return c;
        }
    }
    else
    {
        if(coefficient == 1)
        {
            string d = s5.str();
            return d;
        }
        if(coefficient==0)
        {
            string c = s4.str();
            return c;
        }
        else{
            string e = s2.str();
            return e;
        }
    }*/
}

Number* Pi_or_e::getNum1()
{
	return NULL;
}

Number*  Pi_or_e::getNum2()
{
	return NULL;
}

