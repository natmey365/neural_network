// C++ header file defining the Neural_Network class

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <iostream>
#include "layer.h"
#include "perceptron.h"
#include "activations.h"

class Neural_Network
{
	public:
		Neural_Network();
		Neural_Network(int x, int *shape, float (*func)(float f));
		//void add_layer();
		float* forward_prop(float *inputs);

	private:
		int num_layers;
		int *shape;
		float *outputs;
		Layer **layers;
};

#endif
