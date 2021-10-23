// C++ header file defining the Perceptron class

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
		Perceptron(int _numInputs,                               float (*_activationFunc)(float f));
		Perceptron(int _numInputs, float _bias, float* _weights, float (*_activationFunc)(float f));
		~Perceptron();
	
		int   instantiateWeights();
		int   set(int _numInputs, float (*_activationFunc)(float f));
		int   setBias(float _bias);
		int   setWeights(float* _weights);
		int   setActivationFunc(float (*_activationFunc)(float f));
		float forwardProp(float* inputs, float* output);

	private:
		int    numInputs;
		float  bias;
		float* weights;
		float  (*activationFunc)(float f);
};

#endif
