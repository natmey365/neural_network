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
	std::cout << "numLayers: " << numLayers << std::endl;
	shape = new int[numLayers];
	memcpy(shape, _shape, numLayers*sizeof(shape));
	layers = new Layer[numLayers];

	for(int i=0; i<numLayers-1; i++)
	{
		layers[i].set(shape[i], shape[i+1], func);
	}
	for(int i=0; i<numLayers; i++)
	{
		std::cout << "shape[" << i << "]: " << shape[i] << std::endl;
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

	for(int i=0; i<shape[0]; i++)
	{
		std::cout << "inputs[" << i << "]: " << inputs[i] << std::endl;
	}

	for(int i=0; i<numLayers-2; i++)
	{
		intermediates[i] = new float[shape[i+1]];
	}
	layers[1].forwardProp(inputs, intermediates[0]);

	for(int i=0; i<shape[1]; i++)
	{
		std::cout << "intermediates[0][" << i << "]: " << intermediates[0][i] << std::endl;
	}

	for(int i=2; i<numLayers-1; i++)
	{
		layers[i].forwardProp(intermediates[i-2], intermediates[i-1]);
		for(int j=0; j<shape[i]; j++)
		{
			std::cout << "intermediates[" << i-1 << "][" << j << "]: " << intermediates[i][j] << std::endl;
		}
	}
	layers[numLayers-1].forwardProp(intermediates[numLayers-3], outputs);
	for(int i=0; i<numLayers-2; i++)
	{
		delete []intermediates[i];
	}
	delete []intermediates;
	return 0;
}
