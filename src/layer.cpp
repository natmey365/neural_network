// C++ file defining the Layer class

#include "layer.h"

Layer::Layer()
{}

Layer::Layer(int _prevLayerSize, int _size, float (*func)(float f))
{
	this->set(_prevLayerSize, _size, func);
}

Layer::~Layer()
{
	delete[] perceptrons;
}

int Layer::set(int _prevLayerSize, int _size, float (*func)(float f))
{
	size          = _size;
	prevLayerSize = _prevLayerSize;
	perceptrons   = new Perceptron[size];
	for(int i = 0; i < size; i++)
	{
	        perceptrons[i].set(prevLayerSize, func);
	}
	return 0;
}

int Layer::forwardProp(float* inputs, float* outputs)
{
	for(int i=0; i<size; i++)
	{
		perceptrons[i].forwardProp(inputs, &outputs[i]);
	}
	return 0;
}
