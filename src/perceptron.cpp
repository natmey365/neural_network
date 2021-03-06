// C++ file defining the Perceptron Class

#include "perceptron.h"

Perceptron::Perceptron()
{}

Perceptron::Perceptron(int numInputs_,                              float (*activationFunc_)(float f)) : numInputs(numInputs_)
{
	this->instantiateWeights();
	this->setActivationFunc(activationFunc_);
}

Perceptron::Perceptron(int numInputs_, float bias_,float* weights_, float (*activationFunc_)(float f)) : numInputs(numInputs_)
{
	this->instantiateWeights();
	this->setBias(bias_);
	this->setWeights(weights_);
	this->setActivationFunc(activationFunc_);
}

int Perceptron::instantiateWeights()
{
	weights = new float[numInputs];
}

int Perceptron::setBias(float bias_)
{
	bias = bias_;
}

int Perceptron::setWeights(float* weights_)
{
	for(int i=0; i<numInputs; i++)
	{
		weights[i] = weights_[i];
	}
	return 0;
}

int Perceptron::setActivationFunc(float (*activationFunc_)(float f))
{
	activationFunc = activationFunc_;
}

float Perceptron::forwardProp(float* inputs)
{
	float sum = bias;
	for(int i=0; i<numInputs; i++)
	{
		sum += inputs[i] * weights[i];
	}
	return activationFunc(sum);
}
