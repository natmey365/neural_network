// Header file defining the test for the Perceptron class

#ifndef PERCEPTRONTEST_H
#define PERCEPTRONTEST_H

#include <stdlib.h>
#include <time.h>
#include "neuralNetwork.h"

template <typename T> T forwardProp(int numInputs, T bias, T* inputs, T* weights, T (*activationFunc)(T f));
template <typename T> int   randomizeArray(int size, T* array);
int   main(int argc, char* argv[]);

#endif
