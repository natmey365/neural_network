// C++ file defining the Neural Network class

#include "neural_network.h"

Neural_Network::Neural_Network() : num_layers(0)
{
}

void Neural_Network::add_layer(Layer *new_layer)
{
	num_layers++;
	Layer* temp = new Layer[num_layers];
	for (int i = 0; i < num_layers - 1; i++)
	{
		temp[i] = layers[i];
	}
	temp[num_layers-1] = new_layer;
	delete [] layers;
	layers = temp;
}
