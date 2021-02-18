// C++ file defining the forward propogation test

#include "forwardPropTest.h"

int main(int argc, char* argv[])
{       
	int numLayers = 4;
	int shape[4] = {42*3, 42*3*3, 42*3*3, 1};
	NeuralNetwork nn(numLayers, shape, &sigmoid);

	float nn_output;
	float nn_inputs[42*3];
	for(int i=0; i<42*3; i++)
	{
		nn_inputs[i] = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
		std::cout << nn_inputs[i] << std::endl;
	}
	nn.forwardProp(nn_inputs, &nn_output);
	std::cout << "output: " << nn_output << std::endl;
	for(int i=0; i<42*3; i++)
        {
                nn_inputs[i] = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
        	std::cout << nn_inputs[i] << std::endl;
	}
	nn.forwardProp(nn_inputs, &nn_output);
        std::cout << "output: " << nn_output << std::endl;
}

