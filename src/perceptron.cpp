// C++ file defining the Perceptron Class

#include "perceptron.h"

template <typename T> Perceptron<T>::Perceptron(int numInputs_,                       T (*activationFunc_)(T x)) : numInputs(numInputs_)
{
	weights = new T[numInputs];
	this->randomizeWeights();
	this->setActivationFunc(activationFunc_);
}

template <typename T> Perceptron<T>::Perceptron(int numInputs_, T bias_, T* weights_, T (*activationFunc_)(T x)) : numInputs(numInputs_)
{
	weights = new T[numInputs];
	this->setBias(bias_);
	this->setWeights(weights_);
	this->setActivationFunc(activationFunc_);
}

template <typename T> Perceptron<T>::~Perceptron()
{
	delete []weights;
}

template <typename T> int Perceptron<T>::setBias(T bias_)
{
	bias = bias_;
	return 0;
}

template <typename T> int Perceptron<T>::setWeights(T* weights_)
{
	for(int i=0; i<numInputs; i++)
	{
		weights[i] = weights_[i];
	}
	return 0;
}

template <typename T> int Perceptron<T>::randomizeWeights()
{
	for(int i=0; i<numInputs; i++)
	{
		weights[i] = ((T)rand() / RAND_MAX) - ((T)rand() / RAND_MAX);
	}
	return 0;
}

template <typename T> int Perceptron<T>::setActivationFunc(T (*activationFunc_)(T x))
{
	activationFunc = activationFunc_;
	return 0;
}

template <typename T> T Perceptron<T>::forwardProp(T* inputs)
{
	T sum = bias;
	for(int i=0; i<numInputs; i++)
	{
		sum += inputs[i] * weights[i];
	}
	return activationFunc(sum);
}

template class Perceptron<float>;
