// C++ file defining the Neural Network class

#include "neuralNetwork.h"

NeuralNetwork::NeuralNetwork() : numLayers(0)
{}

//                                 Number of layers - size of y - input and output layers included
//                                 |       Shape of Network - each element is the size of the corresponding layer
//                                 |       |          Activation Function
//                                 |       |          |
NeuralNetwork::NeuralNetwork(int x, int *y, float (*func)(float f)) : numLayers(x)
{
	shape = new int[numLayers];
	memcpy(shape, y, numLayers);
	layers = new Layer[numLayers-1];

	for(int i = 0; i < numLayers-1; i++)
	{
		layers[i].set(y[i+1], y[i], func);
	}
}

NeuralNetwork::~NeuralNetwork()
{
	delete []shape;
	delete []layers;
}

int NeuralNetwork::forwardProp(float* inputs, float* outputs)
{
	layers[0].forwardProp(inputs);
	for(int i=1; i<numLayers; i++)
	{
		layers[i].forwardProp(layers[i-1].getOutputs());
	}
	memcpy(outputs, layers[numLayers-1].getOutputs(), shape[numLayers-1]);
	return 0;
}
