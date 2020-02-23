// C++ header file defining the Neuron class

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <iostream>
#include "activations.h"

class Perceptron
{
	public:
		Perceptron();
		Perceptron(float (*func)(float f));
		float calculate(float *inputs, float *weights, float bias, int size);

	private:
		float (*activation)(float f);
};

#endif
