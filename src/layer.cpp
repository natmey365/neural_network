// C++ file defining the Layer class

#include "layer.h"

Layer::Layer()
{}

Layer::Layer(int x, int y, float (*func)(float f)) : size(x), prevLayerSize(y)
{
	perceptrons = new Perceptron[size];
	weights     = new float*[size];
	biases      = new float[size];
	for(int i = 0; i < size; i++)
	{
		perceptrons[i].setActFunc(func);
		weights[i] = new float[prevLayerSize];
		biases[i]  = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
		for(int j  = 0; j < prevLayerSize; j++)
			weights[i][j] = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
	}
	outputs = new float[size];
}

int Layer::set(int x, int y, float (*func)(float f))
{
	size          = x;
	prevLayerSize = y;
	perceptrons   = new Perceptron[size];
	weights       = new float*[size];
	biases        = new float[size];
	for(int i = 0; i < size; i++)
	{
	        perceptrons[i].setActFunc(func);
	        weights[i] = new float[prevLayerSize];
	        biases[i]  = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
	        for(int j  = 0; j < prevLayerSize; j++)
	                weights[i][j] = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
	}
	outputs = new float[size];
}

void Layer::forwardProp(float *inputs)
{
	for(int i=0; i<size; i++)
	{
		outputs[i] = perceptrons[i].calculate(inputs, weights[i], biases[i], prevLayerSize);
	}
}

float* Layer::getOutputs()
{
	return outputs;
}

int Layer::getSize()
{
	return size;
}
