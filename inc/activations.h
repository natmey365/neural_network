// C++ header file defining activation functions

#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H

#include <iostream>
#include <math.h>

// tanh defined in <math.h>

template <typename T>
T sigmoid(T x)
{
	return 1 / ( 1 + exp(-x));
}

#endif
