// Header file defining the tests for activation functions

#ifndef ACTIVATIONFUNCSTEST_H
#define ACTIVATIONFUNCSTEST_H

// For random number generation
#include <stdlib.h>
#include <time.h>

#include "neuralNetwork.h"

template <typename T>
int compare(T x, T y);
int testSigmoid();
int main(int argc, char* argv[]);

#endif
