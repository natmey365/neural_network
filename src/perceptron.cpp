// C++ file defining the Perceptron Class

#include "perceptron.h"

Perceptron::Perceptron()
{}

Perceptron::Perceptron(int _numInputs,                               float (*_activationFunc)(float f))
{
	this->set(_numInputs, _activationFunc);
}

Perceptron::Perceptron(int _numInputs, float _bias, float* _weights, float (*_activationFunc)(float f)) : numInputs(_numInputs)
{
	this->instantiateWeights();
	this->setBias(_bias);
	this->setWeights(_weights);
	this->setActivationFunc(_activationFunc);
}

Perceptron::~Perceptron()
{
	delete []weights;
}

int Perceptron::instantiateWeights()
{
	weights = new float[numInputs];
	return 0;
}

int Perceptron::set(int _numInputs, float (*_activationFunc)(float f))
{
	numInputs = _numInputs;
	this->instantiateWeights();
	this->setBias((float)rand() / RAND_MAX);
	float tmp[numInputs];
	for(int i=0; i<numInputs; i++)
	{
		tmp[i] = (float)rand() / RAND_MAX;
	}
	this->setWeights(tmp);
	this->setActivationFunc(_activationFunc);
	return 0;
}

int Perceptron::setBias(float _bias)
{
	bias = _bias;
	return 0;
}

int Perceptron::setWeights(float* _weights)
{
	memcpy(weights, _weights, numInputs * sizeof(weights));
	return 0;
}

int Perceptron::setActivationFunc(float (*_activationFunc)(float f))
{
	activationFunc = _activationFunc;
	return 0;
}

float Perceptron::forwardProp(float* inputs, float* output)
{
	float sum = bias;
	for(int i=0; i<numInputs; i++)
	{
		sum += inputs[i] * weights[i];
	}
	*output = activationFunc(sum);
	std::cout << "neuron output: " << *output << std::endl;
	return 0;
}
