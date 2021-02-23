// C++ header file defining the perceptron class

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "activations.h"

template <typename T> class Perceptron
{
	public:
		Perceptron() {}
		Perceptron(int numInputs_,                       T (*activationFunc_)(T x));
		Perceptron(int numInputs_, T bias_, T* weights_, T (*activationFunc_)(T x));
		~Perceptron();

		void setBias(T bias_) {bias = bias_;}
		int  setWeights(int numInputs_, T* weights_);
		int  reset();
		void setActivationFunc(T (*activationFunc_)(T x)) {activationFunc = activationFunc_;}
		T    forwardProp(T* inputs_);

	private:
		int numInputs;
		T   bias;
		T*  weights;
		T   (*activationFunc)(T x);
};

#endif
