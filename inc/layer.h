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
		Layer();
		Layer(int x, int y, float (*func)(float f));

		void        forwardProp(float* inputs);
		float*      getOutputs();
		int         getSize();
		int         set(int x, int y, float (*func)(float f));

	private:
		int         size;
		int         prevLayerSize;
		float**     weights;
		float*      biases;
		float*      outputs;
		Perceptron* perceptrons;
};

#endif
