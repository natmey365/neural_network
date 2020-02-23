// C++ header file defining the Layer class

#ifndef LAYER_H
#define LAYER_H

#include <stdlib.h>
#include <time.h>
#include "perceptron.h"
#include "activations.h"

class Layer
{
	public:
		Layer(int x, int y, float (*func)(float f));
		void forward_prop(float *inputs);
		float* get_outputs();
		int get_size();

	private:
		int size;
		int prev_layer_size;
		float **weights;
		float *biases;
		float *outputs;

		Perceptron **perceptrons;
};

#endif
