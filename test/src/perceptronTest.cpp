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
	srand(time(NULL));
	int retCode = 0;
	int arrSize = 10;
	float bias;
	float* weights = new float[arrSize];
	float* inputs  = new float[arrSize];
	float  (*activationFunc)(float x) = &sigmoid;

	// Test initialization constructor
	bias = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
	randomizeArray(arrSize, weights);
	randomizeArray(arrSize, inputs);
	Perceptron<float> initializedPerceptron(arrSize, bias, weights, activationFunc);
	if(abs(initializedPerceptron.forwardProp(inputs) - forwardProp(arrSize, bias, inputs, weights, activationFunc)) > std::numeric_limits<float>::epsilon()) // These should be the same
	{
		std::cout << "Initialization Constructor fail!" << std::endl;
		retCode += 1;
	}

	// Test random constructor
	Perceptron<float> randomPerceptron1(arrSize, activationFunc);
	Perceptron<float> randomPerceptron2(arrSize, activationFunc);
	if(abs(randomPerceptron1.forwardProp(inputs) - randomPerceptron2.forwardProp(inputs)) < std::numeric_limits<float>::epsilon()) // These should not be the same
	{
		std::cout << "Random Perceptrons had matching output!" << std::endl;
		std::cout << randomPerceptron1.forwardProp(inputs) << std::endl;
		retCode += 1;
	}

	return retCode;
}
