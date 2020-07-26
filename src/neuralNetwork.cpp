// C++ file defining the Neural Network class

#include "neuralNetwork.h"

NeuralNetwork::NeuralNetwork() : numLayers(0), outputs(NULL)
{
	
}

//                                 Number of layers - size of y - input and output layers included
//                                 |       Shape of Network - each element is the size of the corresponding layer
//                                 |       |          Activation Function
//                                 |       |          |
NeuralNetwork::NeuralNetwork(int x, int *y, float (*func)(float f)) : numLayers(x-1), shape(y), outputs(NULL)
{	
	layers = new Layer[numLayers];

	for(int i = 0; i < numLayers; i++)
	{
		layers[i].set(y[i+1], y[i], func);
	}
}

void NeuralNetwork::setInputs(float *x)
{
	inputs = x;
}

float* NeuralNetwork::forwardProp()
{
	if(outputs != NULL)
		delete outputs;
	outputs = new float[shape[numLayers]];
	layers[0].forwardProp(inputs);
	for(int i=1; i<numLayers; i++)
	{
		layers[i].forwardProp(layers[i-1].getOutputs());
	}
	outputs = layers[numLayers-1].getOutputs();
	return outputs;
}
