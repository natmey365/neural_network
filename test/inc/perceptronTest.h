// Header file defining the test for the Perceptron class

#ifndef PERCEPTRONTEST_H
#define PERCEPTRONTEST_H

#include "neuralNetwork.h"

float forwardProp(int numInputs, float bias, float* inputs, float* weights, float (*activationFunc)(float f));
int   randomizeArray(int size, float* array);
int   main(int argc, char* argv[]);

#endif
