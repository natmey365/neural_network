// C++ file defining the Layer class

#include "layer.h"

Layer::Layer()
{}

Layer::Layer(int x, int y, float (*func)(float f))
{
	this->set(x, y, func);
}

Layer::~Layer()
{
	for(int i=0; i<size; i++)
	{
		delete[] weights[i];
	}
	delete[] weights;
	delete[] biases;
	delete[] outputs;
	delete[] perceptrons;
}

int Layer::set(int x, int y, float (*func)(float f))
{
	srand(time(NULL));
	size          = x;
	prevLayerSize = y;
	perceptrons   = new Perceptron[size];
	weights       = new float*[size];
	biases        = new float[size];
	for(int i = 0; i < size; i++)
	{
	        perceptrons[i].set(func);
	        weights[i] = new float[prevLayerSize];
	        biases[i]  = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
	        for(int j  = 0; j < prevLayerSize; j++)
	                weights[i][j] = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
	}
	outputs = new float[size];
	return 0;
}

int Layer::forwardProp(float *inputs)
{
	for(int i=0; i<size; i++)
	{
		outputs[i] = perceptrons[i].calculate(inputs, weights[i], biases[i], prevLayerSize);
	}
	return 0;
}

float* Layer::getOutputs()
{
	return outputs;
}

int Layer::getSize()
{
	return size;
}
