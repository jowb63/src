#ifndef NTH_ROOT_H_
#define NTH_ROOT_H_

#include <string>
#include "Number.h"
#include <vector>
using namespace std;


class nth_root: public Number {

public:
	nth_root();
	nth_root(int base, int power);
	void simplify();
	string getType();
	double getValue();
	int getValueOne(); //base
	int getValueTwo(); //power
	vector<int> factorization(vector<int> &factors, int number, int n);
	bool isPrime(int inside_root);
	bool isInt();
	void simplifyTest();
	string toString();
	Number* getNum1();
	Number* getNum2();

private:
	int base;
	int power;
	int coefficient;



};

#endif /* NTH_ROOT_H_ */
