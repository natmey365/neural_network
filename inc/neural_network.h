// C++ header file defining the Neural_Network class

#include <iostream>
#include "layer.h"
#include "node.h"
#include "activations.h"

class Neural_Network
{
	public:
		Neural_Network();
		void add_layer();

	private:
		int num_layers;
		Layer *layers;
};
