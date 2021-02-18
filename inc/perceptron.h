// C++ header file defining the Neuron class

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "activations.h"

class Perceptron
{
	public:
		Perceptron();
		Perceptron(int numInputs_,                               float (*activationFunc_)(float f));
		Perceptron(int numInputs_, float bias_, float* weights_, float (*activationFunc_)(float f));

		int   setBias(float bias_);
		int   setWeights(float* weights_);
		int   setActivationFunc(float (*activationFunc_)(float f));
		float forwardProp(float* inputs);

	private:
		int    numInputs;
		float  bias;
		float* weights;
		float  (*activationFunc)(float f);
};

#endif
