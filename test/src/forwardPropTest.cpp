// C++ file defining the forward propogation test

#include "forwardPropTest.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));

	int numLayers = 4;
	int shape[4] = {42*3, 42*3*3, 42*3*3, 1};
	NeuralNetwork nn(numLayers, shape, &sigmoid);

	float output;
	float inputs[42*3];
	for(int i=0; i<42*3; i++)
	{
		inputs[i] = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
		std::cout << inputs[i] << std::endl;
	}
	nn.forwardProp(inputs, &output);
	std::cout << "output: " << output << std::endl;
}

