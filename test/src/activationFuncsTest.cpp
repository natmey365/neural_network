// C++ file defining the tests for activation functions

#include "activationFuncsTest.h"

template <typename T> int compare(T x, T y)
{
	if(abs(x - y) < std::numeric_limits<T>::epsilon())
		return 0;
	else if(x > y)
		return 1;
	else
		return -1;
}
template int compare<float>(float x, float y);

int testSigmoid()
{
	int retCode = 0;

	float floatInputs[19] = {-5, -4, -3, -2, -1, -.75, -.5, -.25, -.125, 0, .125, .25, .5, .75, 1, 2, 3, 4, 5};
	float floatOutputs[19] = {	0.006692850924284855559362,	// -5
					0.01798620996209155802679,	// -4
					0.04742587317756678087885,	// -3
					0.1192029220221175559403,	// -2
					0.2689414213699951207488,	// -1
					0.3208213008246070268403,	// -0.75
					0.3775406687981454353611,	// -0.5
					0.4378234991142018959727,	// -0.25
					0.4687906266262437427549,	// -0.125
					0.5,				//  0
					0.5312093733737562572451,	//  0.125
					0.5621765008857981040273,	//  0.25
					0.6224593312018545646389,	//  0.5
					0.6791786991753929731597,	//  0.75
					0.7310585786300048792512,	//  1
					0.8807970779778824440597,	//  2
					0.9525741268224332191212,	//  3
					0.9820137900379084419732,	//  4
					0.9933071490757151444406	//  5
	};
	//float test = sigmoid(floatInputs[10]);
	//std::cout << test << std::endl;
	//std::cout << compare(test, floatOutputs[10]) << std::endl;
	for(int i=0; i<19; i++)
	{
		if(compare(sigmoid(floatInputs[i]), floatOutputs[i]) == 0)
			retCode += 0;
		else
		{
			std::cout << "Sigmoid Fail! i = " << i << ": " << sigmoid(floatInputs[i]) << " != " << floatOutputs[0] << std::endl;
			retCode += 1;
		}
	}
	return retCode;
}

int main(int argc, char* argv[])
{
	int retCode = 0;

	retCode += testSigmoid();

	return retCode;
}
