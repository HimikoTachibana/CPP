#include "calc.hpp"

float calculate(float input1, float input2, string operation, float *result)
{
	if(operation == "+")
	{
		*result=input1+input2;
	}
	else if(operation == "-")
	{
		*result=input1-input2;
	}
	else if(operation == "/")
	{
		*result=input1/input2;
	}
	else if(operation == "*")
	{
		*result=input1*input2;
	}
	else{
		cout << "Illegal operation" << endl;
		return -30.0;
	}
	return *result;
}

void printEquation(float input1, float input2, string operation, float *result)
{
	cout << input1 << " " << operation << " " << input2 << " = " << *result << endl;
}
