// C++ file defining the Neural Network class

#include "neuralNetwork.h"

NeuralNetwork::NeuralNetwork()
{}

//                               Number of layers - input layer included
//                               |                Shape of Network - each element is the size of the corresponding layer
//                               |                |               Activation Function
//                               |                |               |
NeuralNetwork::NeuralNetwork(int _numLayers, int* _shape, float (*func)(float f)) : numLayers(_numLayers)
{
	shape = new int[numLayers];
	memcpy(shape, _shape, numLayers*sizeof(shape));
	layers = new Layer[numLayers];

	for(int i=0; i<numLayers-1; i++)
	{
		layers[i].set(shape[i], shape[i+1], func);
	}
}

NeuralNetwork::~NeuralNetwork()
{
	delete []shape;
	delete []layers;
}

int NeuralNetwork::forwardProp(float* inputs, float* outputs)
{
	float** intermediates = new float*[numLayers-2]; // input and output layers do not produce intermediates - input layer is not a computation and output layer outputs the output
	for(int i=0; i<numLayers-2; i++)
	{
		intermediates[i] = new float[shape[i+1]];
	}
	layers[0].forwardProp(inputs, intermediates[0]);
	for(int i=1; i<numLayers-1; i++)
	{
		layers[i].forwardProp(intermediates[i-1], intermediates[i]);
	}
	layers[numLayers-1].forwardProp(intermediates[numLayers-3], outputs);
	for(int i=0; i<numLayers-2; i++)
	{
		delete []intermediates[i];
	}
	delete []intermediates;
	return 0;
}
