#include "calc.hpp"

int main(int argc, char *argv[])
{
	float fParam=10.22;
	float fParamZ = 13.45;
	float fResult;

	float *fResTmp;
	fResTmp=&fResult;

	float fTemp=0.0;
	fTemp=fResult;
	calculate(fParam, fParamZ,"*",&fResult);
	printEquation(fParam, fParamZ, "*",&fResult);
	
	return 0;
}
