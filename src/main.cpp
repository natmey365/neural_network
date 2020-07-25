#include "main.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));

	int num_layers = 4;
	int shape[4] = {42*3, 42*3*3, 42*3*3, 1};
	float *inputs  = new float[shape[0]];
	for(int i = 0; i < shape[0]; i++)
		inputs[i] = (float)rand() / RAND_MAX;

	//auto start = std::chrono::high_resolution_clock::now();
	NeuralNetwork nn(num_layers, shape, &sigmoid);
	//auto stop = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	//std::cout << duration.count() << std::endl;

	nn.setInputs(inputs);

	auto start = std::chrono::high_resolution_clock::now();
	//std::cout << nn.forward_prop(inputs)[0] << std::endl;
	nn.forwardProp()[0];
	auto stop = std::chrono::high_resolution_clock::now();
 	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
 	std::cout << duration.count() << std::endl;
}
