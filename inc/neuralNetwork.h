// C++ header file defining the Neural_Network class

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <iostream>
#include "layer.h"
#include "perceptron.h"
#include "activations.h"

class NeuralNetwork
{
	public:
		NeuralNetwork();
		NeuralNetwork(int x, int *shape, float (*func)(float f));
		//void addLayer();
		void setInputs(float *x);
		float* forwardProp();

	private:
		int num_layers;
		int *shape;
		float *inputs;
		float *outputs;
		Layer **layers;
};

#endif
