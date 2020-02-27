// C++ file defining the Layer class

#include "layer.h"

Layer::Layer(int x, int y, float (*func)(float f)) : size(x), prev_layer_size(y)
{
	perceptrons = new Perceptron*[size];
	weights = new float*[size];
	biases = new float[size];
	for(int i = 0; i < size; i++)
	{
		perceptrons[i] = new Perceptron(func);
		weights[i] = new float[prev_layer_size];
		biases[i] = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
		for(int j = 0; j < prev_layer_size; j++)
			weights[i][j] = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
	}
	outputs = new float[size];
}

void Layer::forward_prop(float *inputs)
{
	for(int i=0; i<size; i++)
	{
		outputs[i] = perceptrons[i]->calculate(inputs, weights[i], biases[i], prev_layer_size);
	}
}

float* Layer::get_outputs()
{
	return outputs;
}

int Layer::get_size()
{
	return size;
}
