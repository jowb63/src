//============================================================================
// Name        : ShuntingYardA.cpp
// Author      : Joshua Brownstein/ Medhir Bhargava/ Anthony Ditocco/ Brandon Peterson/ Ben Winninger/
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include "Calculate.h"
#include "Number.h"
#include "Logarithm.h"
#include "Pi_or_e.h"
#include "nthroot.h"
#include "Rational.h"
#include "Exception.h"
using namespace std;

//============================================================================
// Name        : ShuntingYardA.cpp
// Author      : Joshua Brownstein
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <stdexcept>
using namespace std;

int getPrecidence (char input)
{
	if(input == '^')
	{
		return 4;
	}
	if(input == 'l')
	{
		return -2;
	}
	else if(input == '*')
	{
		return 2;
	}
	else if(input == '/')
	{
		return 2;
	}
	else if(input == '+')
	{
		return 1;
	}
	else if(input == '-')
	{
		return 1;
	}
	else if(input == '(')
	{
		return -1;
	}
}

int charToInt(char diget)
{
	if(diget == '0')
	{
		return 0;
	}
	else if(diget == '1')
	{
		return 1;
	}
	else if(diget == '2')
	{
		return 2;
	}
	else if(diget == '3')
	{
		return 3;
	}
	else if(diget == '4')
	{
		return 4;
	}
	else if(diget == '5')
	{
		return 5;
	}
	else if(diget == '6')
	{
		return 6;
	}
	else if(diget == '7')
	{
		return 7;
	}
	else if(diget == '8')
	{
		return 8;
	}
	else if(diget == '9')
	{
		return 9;
	}
	else
	{
		return 10;
	}
}

int vectorToInt(vector<int> digets)
{
	int power = digets.size() - 1;
	int output = 0;
	for(int i = 0; i < digets.size(); i++)
	{
		output = output + digets[i]*(int)(pow(10,power));
		power--;
	}
	return output;
}

Number* createNum(string str)
{
	bool isPiOrE = false;
	int letterIndex = -1;

	for(int i = 0; i < str.size(); i++)
	{
		char check = str.at(i);
		if(check == 'p' || check == 'P' || check == 'e')
		{
			isPiOrE = true;
			letterIndex = i;
		}
	}

	if(str.at(0) == 'l')
	{
		vector<int> base;
		int index = 4;
		char diget = str.at(index);
		do
		{
			base.push_back(charToInt(diget));
			index++;
			diget = str.at(index);
		}while(diget != ':');
		index++;

		vector<int> log;
		for(int i = index; i < str.size(); i++)
		{
			diget = str.at(i);
			log.push_back(charToInt(diget));
		}

		return new Logarithm(vectorToInt(base), vectorToInt(log));
	}
	else if(isPiOrE)
	{
		bool negative = false;
		int start = 0;
		string name;
		if(str.at(start) == '-')
		{
			start++;
			negative = true;
		}
		vector<int> coeffient;
		if(str.at(0) == 'p' || str.at(0) == 'P' || str.at(0) == 'e')
		{
			coeffient.push_back(1);
		}

		if(start > 0 && (str.at(start) == 'p' || str.at(start) == 'e'))
		{
			coeffient.push_back(1);
			start = letterIndex;
		}

		for(int i = start; i < letterIndex; i++)
		{
			coeffient.push_back(charToInt(str.at(i)));
		}

		if(str.at(letterIndex) == 'p' || str.at(letterIndex) == 'P')
		{
			name = "pi";
		}
		else
		{
			name = "e";
		}

		if(negative)
		{
			return new Pi_or_e(-1 * vectorToInt(coeffient), name);
		}
		else
		{
			return new Pi_or_e(vectorToInt(coeffient), name);
		}
	}
	else
	{
		bool negative = false;
		int start = 0;
		if(str.at(start) == '-')
		{
			start++;
			negative = true;
		}
		bool allDigets = true;
		for(int i = start; i < str.size(); i++)
		{
			char diget = str.at(i);
			if(!(diget == '0' || diget == '1' || diget == '2' || diget == '3' || diget == '4' || diget == '5' || diget == '6' || diget == '7' || diget == '8' || diget == '9'))
			{
				allDigets = false;
			}
		}

		if(allDigets)
		{
			vector<int> digets;
			for(int i = start; i < str.size(); i++)
			{
				digets.push_back(charToInt(str.at(i)));
			}

			if(negative)
			{
				Number* output =  new Rational(-1 * vectorToInt(digets), 1);
				return output;
			}
			else
			{
				return new Rational(vectorToInt(digets), 1);
			}
		}

		vector<int> degree;
		int rIndex = 0;
		while(str.at(rIndex) != 'r')
		{
			rIndex++;
		}
		for(int i = start; i < rIndex; i++)
		{
			degree.push_back(charToInt(str.at(i)));
		}

		vector<int> radicand;
		bool negativeRadicand = false;
		for(int i = rIndex + 3; i < str.size(); i++)
		{
			if(i == rIndex + 3 && str.at(i) == '-')
			{
				negativeRadicand = true;
				i++;
			}

			radicand.push_back(charToInt(str.at(i)));
		}

		if(negative && negativeRadicand)
		{
			return new nth_root(-1*vectorToInt(radicand), -1*vectorToInt(degree));
		}
		else if(negative)
		{
			return new nth_root(vectorToInt(radicand), -1*vectorToInt(degree));
		}
		else if(negativeRadicand)
		{
			return new nth_root(-1*vectorToInt(radicand), vectorToInt(degree));
		}
		else
		{
			return new nth_root(vectorToInt(radicand), vectorToInt(degree));
		}

	}
	return new Rational(1,1);
}


Number* evaluate(queue<string> output)
{
	Calculate* calculate = new Calculate();
    stack<Number*> evaluatedExp;
	while(!output.empty())
	{
		//create a new stack to evaluate Number pointers
		if(output.front() == "+")
		{
			//pop off first Number
			Number* first = evaluatedExp.top();
			evaluatedExp.pop();
			//pop off second numb0er
			Number* second = evaluatedExp.top();
			evaluatedExp.pop();

			//Number* result = first + second;

			//evaluate expression
            Number* result = calculate->add(first, second);

            //push result onto stack
			evaluatedExp.push(result);
			output.pop();
		}
		else if(output.front()=="-")
		{
			Number* first = evaluatedExp.top();
			evaluatedExp.pop();
			Number* second = evaluatedExp.top();
			evaluatedExp.pop();
			//Number* result = second - first;
            Number* result = calculate->subtract(second, first);
			evaluatedExp.push(result);
			output.pop();
		}
		else if(output.front()=="*")
		{
			Number* first = evaluatedExp.top();
			evaluatedExp.pop();
			Number* second = evaluatedExp.top();
			evaluatedExp.pop();
			//Number* result = first * second;
            Number* result = calculate->multiply(first, second);
			evaluatedExp.push(result);
			output.pop();
		}
		else if(output.front()=="/")
		{
			Number* first = evaluatedExp.top();
			evaluatedExp.pop();
			Number* second = evaluatedExp.top();
			evaluatedExp.pop();
			//Number* result = second / first;
            Number* result = calculate->divide(second, first);
			evaluatedExp.push(result);
			output.pop();
		}
		else if(output.front()=="^")
		{
			Number* first = evaluatedExp.top();
			evaluatedExp.pop();
			Number* second = evaluatedExp.top();
			evaluatedExp.pop();
			//Number* result = second ^ first;
            Number* result = calculate->exponentiate(second, first);
			evaluatedExp.push(result);
			output.pop();
		}
		else if(output.front() == "l")
		{
			Number* first = evaluatedExp.top();
			evaluatedExp.pop();
			Number* second = evaluatedExp.top();
			evaluatedExp.pop();
			//Number* result = second ^ first;
            Number* result = calculate->log(second, first);
			evaluatedExp.push(result);
			output.pop();
		}
        else
        {
        	//if the string is not an operator, construct a new Number*
        	//and push it onto the stack
            Number* newNumber = createNum(output.front());
            output.pop();
            evaluatedExp.push(newNumber);
        }
	}

	Number* result = evaluatedExp.top();
	evaluatedExp.pop();

	return result;
}

queue<string> shuntingYardAlgorithm(string input, Number* lastAnswer)
{
	bool doneWhileLoop = false;
	bool negative = false;
	bool firstNegative;
	stack <string> operators;
	queue <string> output;


	for(int i = 0; i < input.size(); i++)
	{
		if(i == 0 && input.at(i) == '-')
		{
			negative = true;
			firstNegative = true;
			i++;
		}

		if(doneWhileLoop == true)
		{
			i--;
			doneWhileLoop = false;
		}

		char currentChar = input.at(i);

		if(currentChar == ':')
		{

		}
		else if(currentChar == '0' || currentChar == '1' || currentChar == '2' || currentChar == '3' || currentChar == '4' || currentChar == '5' || currentChar == '6' || currentChar == '7' || currentChar == '8' || currentChar == '9' || currentChar == 'e' || currentChar == 'p' || currentChar == 'P' || currentChar == 'a')
		{
			doneWhileLoop = true;
			std::ostringstream stringCurrentChar;

			if(negative)
			{
				stringCurrentChar << "-";
				negative = false;
			}

			while(currentChar == '0' || currentChar == '1' || currentChar == '2' || currentChar == '3' || currentChar == '4' || currentChar == '5' || currentChar == '6' || currentChar == '7' || currentChar == '8' || currentChar == '9' || currentChar == 'e'|| currentChar == 'i' || currentChar == 'p' || currentChar == 'P' || currentChar == 'l' || currentChar == 'o' || currentChar == 'g' || currentChar == '_' || currentChar == 'r' || currentChar == 't' || currentChar == 'a' || currentChar == 'n' || currentChar == 's')
			{
				stringCurrentChar << currentChar;
				if(currentChar == 't')
				{
					i++;
					currentChar = input.at(i);
					stringCurrentChar << currentChar;
				}
				i++;
				if(currentChar == ':')
				{
					if(input.at(i) == '-')
					{
						stringCurrentChar << "-";
						i++;
					}
				}
				if(i < input.size())
				{
					currentChar = input.at(i);
				}
				else
				{
					currentChar = 'z';
				}
			}

			bool negativeNthRoot = false;
			/*if(firstNegative)
			{
				string stringOfStringCurrentChar = stringCurrentChar.str();
				for(int i = 0; i < stringOfStringCurrentChar.size()-3; i++)
				{
					if(stringOfStringCurrentChar.at(i) == 'r' && stringOfStringCurrentChar.at(i+1) == 't' && stringOfStringCurrentChar.at(i+2) == ':')
					{
						ostringstream base;
						ostringstream power;

						for(int j = 1; j < i; j++)
						{
							power << stringOfStringCurrentChar.at(j);
						}

						for(int k = i + 3; k < stringOfStringCurrentChar.size(); k++)
						{
							base << stringOfStringCurrentChar.at(k);
						}

						Calculate* calculate = new Calculate();
						Number* rationalPower = calculate->divide(createNum("-1"), createNum(power.str()));
						cout << rationalPower->toString() << endl;
						cout << base.str() << endl;
						Number* negativeFirstChar = calculate->exponentiate(createNum(base.str()), rationalPower);
						output.push(negativeFirstChar->toString());
						negativeNthRoot = true;
					}
				}
			}*/

			if(i == (input.size() - 1))
			{
				i--;
				doneWhileLoop = false;
			}

			/*if(negativeNthRoot)
			{

			}
			else*/ if(stringCurrentChar.str() == "ans")
			{
				if(lastAnswer != NULL)
				{
					output.push(lastAnswer->toString());
				}
			}
			else
			{
				output.push(stringCurrentChar.str());
			}
		}
		else if(currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '^' || currentChar == '(' || currentChar == 'l')
		{
			if(!operators.empty())
			{
				char check = operators.top().at(0);

				int checkPrecidence = getPrecidence(check);
				int currentPrecidence = getPrecidence(currentChar);

				if(currentPrecidence > checkPrecidence || currentChar == '(')
				{
					std::ostringstream stringCurrentChar;
					if(currentChar == 'l')
					{
						stringCurrentChar << currentChar;
						while(input.at(i+1) == 'o' || input.at(i+1) == 'g' || input.at(i+1) == '_')
						{
							currentChar = input.at(i+1);
							i++;
						}
					}
					else
					{
						stringCurrentChar << currentChar;
					}
					operators.push(stringCurrentChar.str());
				}
				else
				{
					if(currentPrecidence == checkPrecidence && check == '^')
					{
						std::ostringstream stringCurrentChar;
						if(currentChar == 'l')
						{
							stringCurrentChar << currentChar;
							while(input.at(i+1) == 'o' || input.at(i+1) == 'g' || input.at(i+1) == '_')
							{
								currentChar = input.at(i+1);
								i++;
							}
						}
						else
						{
							stringCurrentChar << currentChar;
						}
						operators.push(stringCurrentChar.str());
					}
					else
					{
						output.push(operators.top());
						operators.pop();
						std::ostringstream stringCurrentChar;
						if(currentChar == 'l')
						{
							stringCurrentChar << currentChar;
							while(input.at(i+1) == 'o' || input.at(i+1) == 'g' || input.at(i+1) == '_')
							{
								currentChar = input.at(i+1);
								i++;
							}
						}
						else
						{
							stringCurrentChar << currentChar;
						}
						operators.push(stringCurrentChar.str());
					}
				}
			}
			else
			{
				std::ostringstream stringCurrentChar;
				if(currentChar == 'l')
				{
					stringCurrentChar << currentChar;
					while(input.at(i+1) == 'o' || input.at(i+1) == 'g' || input.at(i+1) == '_')
					{
						currentChar = input.at(i+1);
						i++;
					}
				}
				else
				{
					stringCurrentChar << currentChar;
				}
				operators.push(stringCurrentChar.str());
			}

			if((i + 1) < input.size() && input.at(i+1) == '-')
			{
				negative = true;
				i++;
			}
		}
		else
		{
			if(!operators.empty())
			{
				char check = operators.top().at(0);
				while(check != '(')
				{
					output.push(operators.top());
					operators.pop();
					check = operators.top().at(0);
				}
				operators.pop();
			}
		}
	}

	std::ostringstream ossOperand;
	while(!operators.empty())
	{

		output.push(operators.top());
		operators.pop();
	}

	return output;
}

string AddSubtract(string input)
{
	vector<string> betweenAddAndSubtract;
	vector<Number*> betweenAddAndSubtractSYA;
	vector<Number*> rationals;
	Number* rationalsAnswer;
	vector<Number*> pi;
	Number* piAnswer;
	vector<Number*> e;
	Number* eAnswer;
	vector<Number*> logs;
	Number* logsAnswer;
	vector<Number*> nth_roots;
	Number* nth_rootsAnswer;
	ostringstream currentString;
	ostringstream outputString;
	bool parentheses= false;
	for(int i = 0; i < input.size(); i++)
	{
		if(input.at(i) != '+' && input.at(i) != '-')
		{
			currentString << input.at(i);
			if(i == input.size() - 1)
			{
				betweenAddAndSubtract.push_back(currentString.str());
				currentString.str("");
				currentString.clear();
			}
		}
		else if(input.at(i) == '-')
		{
			betweenAddAndSubtract.push_back(currentString.str());
			currentString.str("");
			currentString.clear();
			currentString << "-1*";
		}
		else
		{
			betweenAddAndSubtract.push_back(currentString.str());
			currentString.str("");
			currentString.clear();
		}
	}

	for(int i = 0; i < betweenAddAndSubtract.size(); i++)
	{
		cout << "between add and subtract index " << i << ": " << betweenAddAndSubtract[i] << endl;
		betweenAddAndSubtractSYA.push_back(evaluate(shuntingYardAlgorithm(betweenAddAndSubtract[i], NULL)));
		cout << "between add and subtract sya index " << i << ": " << betweenAddAndSubtractSYA[i]->toString() << endl;
	}

	for(int i = 0; i < betweenAddAndSubtractSYA.size(); i++)
	{
		string check =  betweenAddAndSubtractSYA[i]->getType();
		if(check == "Rational")
		{
			rationals.push_back(betweenAddAndSubtractSYA[i]);
		}
		else if(check == "pi")
		{
			pi.push_back(betweenAddAndSubtractSYA[i]);
		}
		else if(check == "e")
		{
			e.push_back(betweenAddAndSubtractSYA[i]);
		}
		else if(check == "Logarithm")
		{
			logs.push_back(betweenAddAndSubtractSYA[i]);
		}
		else if(check == "nth_root")
		{
			nth_roots.push_back(betweenAddAndSubtractSYA[i]);
		}
	}

	if(!rationals.empty())
	{
		for(int i = 0; i < rationals.size(); i++)
		{
			if(i != rationals.size() - 1)
			{
				currentString << rationals[i]->toString() << "+";
			}
			else
			{
				currentString << rationals[i]->toString();
			}
		}

		rationalsAnswer = evaluate(shuntingYardAlgorithm(currentString.str(), NULL));
		currentString.str("");
		currentString.clear();
	}

	if(!pi.empty())
	{
		for(int i = 0; i < pi.size(); i++)
		{
			if(i != pi.size() - 1)
			{
				currentString << pi[i]->toString() << "+";
			}
			else
			{
				currentString << pi[i]->toString();
			}
		}

		piAnswer = evaluate(shuntingYardAlgorithm(currentString.str(), NULL));
		currentString.str("");
		currentString.clear();
	}

	if(!e.empty())
	{
		for(int i = 0; i < e.size(); i++)
		{
			if(i != e.size() - 1)
			{
				currentString << e[i]->toString() << "+";
			}
			else
			{
				currentString << e[i]->toString();
			}
		}

		eAnswer = evaluate(shuntingYardAlgorithm(currentString.str(), NULL));
		currentString.str("");
		currentString.clear();
	}

	if(!logs.empty())
	{
		for(int i = 0; i < logs.size(); i++)
		{
			if(i != logs.size() - 1)
			{
				currentString << logs[i]->toString() << "+";
			}
			else
			{
				currentString << logs[i]->toString();
			}
		}

		logsAnswer = evaluate(shuntingYardAlgorithm(currentString.str(), NULL));
		currentString.str("");
		currentString.clear();
	}

	if(!nth_roots.empty())
	{
		for(int i = 0; i < nth_roots.size(); i++)
		{
			if(i != nth_roots.size() - 1)
			{
				currentString << nth_roots[i]->toString() << "+";
			}
			else
			{
				currentString << nth_roots[i]->toString();
			}
		}

		nth_rootsAnswer = evaluate(shuntingYardAlgorithm(currentString.str(), NULL));
		currentString.str("");
		currentString.clear();
	}
}

int main() {
	char selection1, selection2, selection3;
	vector<Number*> answers;
	bool hasChoosenAns = false;
	Number* choosenAns;

	do {
		cout << "a) Compute new expression." << endl;
		cout << "b) Help." << endl;
		cout << "c) Review previous expressions and answers." << endl;
		cout << "d) Quit." << endl;
		cout << endl;
		cout << "Please make a selection: ";

		cin >> selection1;
		if (selection1 == 'a')
		{
			string input;
			bool hasAnsInInputAndNoPreviousAns = false;

			cout <<"Enter an expression without spaces: ";
			cin >> input;

			bool success = true;
			try{
			for(int i=0; i<input.size(); i++)
			{
			if(input.at(i)!= '1' && input.at(i)!='2' && input.at(i)!= '3'&& input.at(i)!='4'&& input.at(i)!='5'&&input.at(i)!='6' &&input.at(i)!='7'&&input.at(i)!='8'&&input.at(i)!='9'&&input.at(i)!='0'&&input.at(i)!='l'&&input.at(i)!='o'&&input.at(i)!='g'&&input.at(i)!='p'&&input.at(i)!='P'&&input.at(i)!='i'&&input.at(i)!='e'&&input.at(i)!='r'&&input.at(i)!='t'&&input.at(i)!=':'&&input.at(i)!='_'&&input.at(i)!='-'&&input.at(i)!='+'&&input.at(i)!='/'&&input.at(i)!='*'&&input.at(i)!='('&&input.at(i)!=')'&&input.at(i)!='a'&&input.at(i)!='n'&&input.at(i)!='s' && input.at(i)!='^')
			{
			ostringstream s;
			s<<"Character "<<input.at(i)<<" not supported";
			throw invalid_argument(s.str());
			}
			}
			}
			catch(const std::invalid_argument& e)
			{
			cout<<e.what()<<endl;
			success = false;
			}

			if(success)
			{
			queue<string> output;

			if(answers.empty())
			{
				for(int i = 0; i < input.size(); i++)
				{
					if(input.at(i) == 'a')
					{
						hasAnsInInputAndNoPreviousAns = true;
					}
				}

				if(!hasAnsInInputAndNoPreviousAns)
				{
					output = shuntingYardAlgorithm(input, NULL);
				}
				else
				{
					cout << "No previous answers." << endl;
				}
			}
			else
			{
				if(hasChoosenAns)
				{
					output = shuntingYardAlgorithm(input, choosenAns);
					hasChoosenAns = false;
				}
				else
				{
					output = shuntingYardAlgorithm(input, answers[answers.size() - 1]);
				}
			}

			if(!hasAnsInInputAndNoPreviousAns)
			{
				Number* result = evaluate(output);
				answers.push_back(result);
				cout << "Result: " << result->toString() << endl << endl;
			}
		}
		}
		else if (selection1 == 'b')
		{
			cout<<endl;
			cout<<" The calculator supports the following functions: "<<endl<<endl<<endl;
			cout<<"1)Addition/Subtraction. Enter two or more expressions along with + or -"<<endl;
			cout<<"2)Multiplication/Division. Enter two or more expressions along with * or /"<<endl;
			cout<<"3)Pi/e. To use pi or e enter the word \"pi\" or \"e\" preceded by a coefficient if desired."<<endl;
			cout<<"4)Logarithm. Enter a logarithm in the form log_X:Y where x is base and y is the log."<<endl;
			cout<<"5)NthRoot. Enter an nthroot in the form Xrt:Y where x is the degree and y is the number."<<endl;
			cout<<"-Please enter your expression without spaces. Parentheses are also supported by our calculator for separating expressions."<<endl<<endl<<endl;
		}
		else if (selection1 == 'c')
		{
			do {
				cout << "1. Show floating-point representation of previous expressions." << endl;
				cout << "2. Set \"ans\" to previous expression's answer." << endl;
				cout << "3. Return to main menu." << endl;
				cout << endl;
				cout << "Please make a selection: ";

				cin >> selection3;
				if (selection3 == '1')
				{
					if(answers.empty())
					{
						cout << "There are no previous answers." << endl;
					}
					else
					{
						for(int i = 0; i < answers.size(); i++)
						{
							cout << "The previous answer with index " << i << " has a value of " << answers[i]->toString() << endl;
						}
						/*cout << "What is the value of index of the answer that you want displayed? ";
						int index;
						cin >> index;
						if(index >= 0 && index < answers.size())
						{
							cout << "The value of that answer is: " << answers[index]->toString() << endl;
						}
						else
						{
							cout << "That is not a valid index. Please choose an index between 0 and " << answers.size() - 1 << endl;
						}*/
					}
				}
				else if (selection3 == '2')
				{
					if(answers.empty())
					{
						cout << "There are no previous answers." << endl << endl;
					}
					else
					{
						for(int i = 0; i < answers.size(); i++)
						{
							cout << "The previous answer with index " << i << " has a value of " << answers[i]->toString() << endl;
						}
						cout << "What is the value of index of the answer that you want \"ans\" to be? ";
						int index;
						cin >> index;
						if(index >= 0 && index < answers.size())
						{
							cout << "ans is now: " << answers[index]->toString() << endl;
							hasChoosenAns = true;
							choosenAns = answers[index];
						}
						else
						{
							cout << "That is not a valid index. Please choose an index between 0 and " << answers.size() - 1 << endl;
						}
					}
				}
			} while (selection3 != '3');
			cout << endl;
		}

		if(selection1 != 'a' && selection1 != 'b' && selection1 != 'c' && selection1 != 'd')
		{
			cout << "Not an option" << endl;
		}
	} while (selection1 != 'd');

	//return 0;
}

//pi*pi*pi
//3+pi
//3*pi^1




