// C++ header file defining the Neuron class

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "activations.h"

template <typename T> class Perceptron
{
	public:
		Perceptron(int numInputs_,                       T (*activationFunc_)(T x));
		Perceptron(int numInputs_, T bias_, T* weights_, T (*activationFunc_)(T x));
		~Perceptron();

		int setBias(T bias_);
		int setWeights(T* weights_);
		int randomizeWeights();
		int setActivationFunc(T (*activationFunc_)(T x));
		T   forwardProp(T* inputs_);

	private:
		int numInputs;
		T   bias;
		T*  weights;
		T   (*activationFunc)(T x);
};

#endif
