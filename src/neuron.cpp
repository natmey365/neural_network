// C++ file defining the Neuron Class

#include "neuron.h"

Neuron::Neuron(float (*func)(float f)) : activation(func)
{
	
}

float Neuron::calculate(float *inputs, float *weights, float *biases)
{
	if ((inputs == NULL) or (weights == NULL) or (biases == NULL))
	{
		std::cout << "One of the input arrays is empty!\n";
		return NULL;
	}
	else if ( (sizeof( inputs) != sizeof(weights)) or
		  (sizeof( inputs) != sizeof( biases)) or
		  (sizeof(weights) != sizeof( biases)) )
	{
		std::cout << "The input arrays are not the same size!\n";
		return NULL;
	}
	else
	{
		float output = 0;
		for 
	}

	return output;
}
