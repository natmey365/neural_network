// C++ file defining the test for the Perceptron class

#include <stdlib.h>
#include <time.h>
#include "perceptronTest.h"

float forwardProp(int numInputs, float bias, float* inputs, float* weights, float (*activationFunc)(float f))
{
	
}

int randomizeArray(int size, float* array)
{
	
}

int main(int argc, char* argv[])
{
	int retCode = 0;
	float  (*activationFunc)(float f) = &sigmoid;
	
	// Test constructors
	Perceptron emptyPerceptron;
	Perceptron randomPerceptron(10, activationFunc);
	float bias = 0.5;
	float* weights = new float[10];
	float* inputs  = new float[10];
	for(int i=0; i<10; i++)
	{
		weights[i] = 0.5;
		inputs[i]  = 0.5;
	}
	Perceptron initializedPerceptron(10, bias, weights, activationFunc);
	
	// Test forward propogation
	float output = initializedPerceptron.forwardProp(inputs);
	std::cout << "Output (should be 0.9525741): " << output << std::endl;
}
