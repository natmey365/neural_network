// Top level C++ file

#include "main.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));

	int numLayers = 4;
	int shape[4] = {42*3, 42*3*3, 42*3*3, 1};
	float* inputs  = new float[shape[0]];
	float* outputs = new float[shape[numLayers-1]];
	for(int i = 0; i < shape[0]; i++)
		inputs[i] = (float)rand() / RAND_MAX;

	NeuralNetwork nn(numLayers, shape, &sigmoid);

	auto start = std::chrono::high_resolution_clock::now();
	nn.forwardProp(inputs, outputs);
	auto stop = std::chrono::high_resolution_clock::now();
 	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 	std::cout << duration.count() << " uSeconds" << std::endl;
	for(int i=0; i<shape[numLayers-1]; i++)
	{
		std::cout << outputs[i] << std::endl;
	}

	delete[] inputs;
	delete[] outputs;
}
