// C++ header file defining the Neural_Network class

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <iostream>
#include <string.h>
#include "layer.h"
#include "perceptron.h"
#include "activations.h"

class NeuralNetwork
{
	public:
		NeuralNetwork();
		NeuralNetwork(int x, int *shape, float (*func)(float f));
		~NeuralNetwork();

		int   forwardProp(float* inputs, float* outputs);

	private:
		int      numLayers;
		int*     shape;
		Layer*   layers;
};

#endif
