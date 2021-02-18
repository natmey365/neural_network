// C++ file defining activation functions

#include "activations.h"

template <typename T>
T sigmoid(T x)
{
	return 1 / ( 1 + exp(-x));
}
template float sigmoid<float>(float x);
