// C++ file defining the Neural Network class

#include "neuralNetwork.h"

NeuralNetwork::NeuralNetwork() : numLayers(0)
{}

//                               Number of layers - size of y - input and output layers included
//                               |                Shape of Network - each element is the size of the corresponding layer
//                               |                |               Activation Function
//                               |                |               |
NeuralNetwork::NeuralNetwork(int _numLayers, int* _shape, float (*func)(float f)) : numLayers(_numLayers)
{
	shape = new int[_numLayers];
	memcpy(shape, _shape, numLayers*sizeof(shape));
	layers = new Layer[numLayers-1];

	for(int i=0; i<numLayers-1; i++)
	{
		layers[i].set(shape[i+1], shape[i], func);
	}
}

NeuralNetwork::~NeuralNetwork()
{
	delete []shape;
	delete []layers;
}

int NeuralNetwork::forwardProp(float* _inputs, float* _outputs)
{
	layers[0].forwardProp(_inputs);
	for(int i=1; i<numLayers-1; i++)
	{
		layers[i].forwardProp(layers[i-1].getOutputs());
	}
	memcpy(_outputs, layers[numLayers-2].getOutputs(), shape[numLayers-1]*sizeof(_outputs));
	return 0;
}
