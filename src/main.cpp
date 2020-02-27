#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "neural_network.h"
#include "layer.h"
#include "perceptron.h"
#include "activations.h"

int main(void)
{
	srand(time(NULL));

	int num_layers = 4;
	int shape[4] = {42*3, 42*3*3, 42*3*3, 1};
	float *inputs  = new float[shape[0]];
	for(int i = 0; i < shape[0]; i++)
		inputs[i] = (float)rand() / RAND_MAX;

	//auto start = std::chrono::high_resolution_clock::now();
	Neural_Network nn(num_layers, shape, &sigmoid);
	//auto stop = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	//std::cout << duration.count() << std::endl;

	auto start = std::chrono::high_resolution_clock::now();
	//std::cout << nn.forward_prop(inputs)[0] << std::endl;
	nn.forward_prop(inputs)[0];
	auto stop = std::chrono::high_resolution_clock::now();
 	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 	std::cout << duration.count() << std::endl;
}
