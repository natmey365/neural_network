// C++ file defining the Perceptron Class

#include "perceptron.h"

Perceptron::Perceptron(float (*func)(float f)) : activation(func)
{
	
}

float Perceptron::calculate(float *inputs, float *weights, float bias, int size)
{
	float output = 0;

	for(int i = 0; i < size; i++)
	{
		output += inputs[i] * weights[i];
	}

	return activation(output + bias);
}
