// C++ file defining the test for the Perceptron class

#include <stdlib.h>
#include <time.h>
#include "perceptronTest.h"

template <typename T>
T forwardProp(int numInputs, T bias, T* inputs, T* weights, T (*activationFunc)(T f))
{
	T sum = bias;
	for(int i=0; i<numInputs; i++)
	{
		sum += inputs[i] * weights[i];
	}
	return activationFunc(sum);
}
template float forwardProp<float>(int numInputs, float bias, float* inputs, float* weights, float (*activationFunc)(float f));

template <typename T>
int randomizeArray(int size, T* array)
{
	for(int i=0; i<size; i++)
	{
		array[i] = ((T)rand() / RAND_MAX) - ((T)rand() / RAND_MAX);
	}
	return 0;
}
template int randomizeArray<float>(int size, float* array);

int main(int argc, char* argv[])
{
	int retCode = 0;
	int arrSize = 10;
	float bias;
	float* weights = new float[arrSize];
	float* inputs  = new float[arrSize];
	float  (*activationFunc)(float x) = &sigmoid;
	float output;

	// Test initialization constructor
	bias = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
	randomizeArray(arrSize, weights);
	randomizeArray(arrSize, inputs);
	Perceptron<float> initializedPerceptron(arrSize, bias, weights, activationFunc);
	if(abs(initializedPerceptron.forwardProp(inputs) - forwardProp(arrSize, bias, inputs, weights, activationFunc)) > std::numeric_limits<float>::epsilon())
	{
		std::cout << "Initialization Constructor fail!" << std::endl;
		retCode += 1;
	}

	// Test random constructor
	randomizeArray(arrSize, inputs);
	Perceptron<float> randomPerceptron1(arrSize, activationFunc);
	output = randomPerceptron1.forwardProp(inputs);
	std::cout << "Random Output 1: " << output << std::endl;
	randomizeArray(arrSize, inputs);
	Perceptron<float> randomPerceptron2(arrSize, activationFunc);
	output = randomPerceptron2.forwardProp(inputs);
	std::cout << "Random Output 2: " << output << std::endl;

	return retCode;
}
