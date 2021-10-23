// C++ file defining the test for the Layer class

#include "layerTest.h"

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
	srand(time(NULL));
	int size = 10;
	int prevLayerSize = 10;
	float inputs[prevLayerSize];
	float weights[size][prevLayerSize];
	float biases[size];
	for(int i=0; i<prevLayerSize; i++)
	{
		inputs[i] = 1;
		biases[i] = 1;
		for(int j=0; j<size; j++)
		{
			weights[i][j] = 1;
		}
	}
	Layer l(prevLayerSize, size, &sigmoid);

	float outputs[size];
	l.forwardProp(inputs, outputs);

	std::cout << "outputs: " << std::endl;
	for(int i=0; i<size; i++)
	{
		std::cout << outputs[i] << std::endl;
	}
}
