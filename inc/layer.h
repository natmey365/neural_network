// C++ header file defining the Layer class

#ifndef LAYER_H
#define LAYER_H

#include <stdlib.h>
#include <time.h>
#include "perceptron.h"
#include "activations.h"

template <typename T> class Layer
{
	public:
		Layer(int x, int y, T (*activationFunc)(T x));
		~Layer();

		int  forwardProp(int prevLayerSize_, T* inputs, T* outputs);
		int  getSize()
			{return size;}
		int setWeights(int prevLayerSize_, int size_, T** weights);
		int setBiases(int prevLayerSize_, T* biases);
		
	private:
		int size;
		int prevLayerSize;
		Perceptron<T>* perceptrons;
};

#endif
