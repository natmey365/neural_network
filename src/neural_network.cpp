// C++ file defining the Neural Network class

#include "neural_network.h"

Neural_Network::Neural_Network() : num_layers(0), outputs(NULL)
{
	
}

Neural_Network::Neural_Network(int x, int *y, float (*func)(float f)) : num_layers(x-1), shape(y), outputs(NULL)
{	
	layers = new Layer*[num_layers];

	for(int i = 0; i < num_layers; i++)
		layers[i] = new Layer(y[i+1], y[i], func);
}

/*void Neural_Network::addLayer()
{
	num_layers++;
	Layer **temp = new Layer*[num_layers];
	for (int i = 0; i < num_layers - 1; i++)
	{
		temp[i] = new Layer;
	}
	temp[num_layers-1] = new_layer;
	delete [] layers;
	layers = temp;
}*/

void Neural_Network::setInputs(float *x)
{
	inputs = x;
}

float* Neural_Network::forwardProp()
{
	if(outputs != NULL)
		delete outputs;
	outputs = new float[shape[num_layers]];
	layers[0]->forward_prop(inputs);
	for(int i=1; i<num_layers; i++)
	{
		layers[i]->forward_prop(layers[i-1]->get_outputs());
	}
	outputs = layers[num_layers-1]->get_outputs();
	return outputs;
}
