// C++ header file defining the Neuron class

#include <iostream>
#include "activations.h"

class Neuron
{
	public:
		Neuron(float (*func)(float f));
		float calculate(float *inputs, float *weights, float *biases);

	private:
		float (*activation)(float f);
};
