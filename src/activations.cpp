// C++ file defining activation functions from activations.h

#include "activations.h"

float sigmoid (float x)
{
	return 1 / ( 1 + exp(-x));
}
