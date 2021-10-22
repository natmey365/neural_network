// C++ file defining the test for the Perceptron class

#include "perceptronTest.h"

template <typename T>
int compare(T x, T y)
{
	if(abs(x - y) < std::numeric_limits<T>::epsilon())
		return 0;
	else if(x > y)
		return 1;
	else
		return -1;
}
template int compare<float>(float x, float y);

int main(int argc, char* argv[])
{
	// Weights and bias of 0 always give 0 output

	int numInputs = 10;
	float inputs[numInputs];
	float weights[numInputs];
	for(int i=0; i<numInputs; i++)
	{
		inputs[i] = 1;
		weights[i] = 1;
	}
	float bias = 1;
	Perceptron p(numInputs, bias, weights, &sigmoid);

	float output;
	p.forwardProp(inputs, &output);

        std::cout << "output: " << output << std::endl;
}
