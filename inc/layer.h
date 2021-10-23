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
		Layer(int _prevLayerSize, int _size, float (*func)(float f));
		~Layer();

		int         forwardProp(float* inputs, float* outputs);
		int         set(int _prevLayerSize, int _size, float (*func)(float f));

	private:
		int         size;
		int         prevLayerSize;
		Perceptron* perceptrons;
};

#endif
