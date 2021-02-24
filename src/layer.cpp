// C++ file defining the Layer class

#include "layer.h"

template <typename T> Layer<T>::Layer(int size_, int prevLayerSize_, T (*activationFunc)(T x)) : size(size_), prevLayerSize(prevLayerSize_)
{
	Perceptron<T> temp(size, activationFunc);
	perceptrons = new Perceptron<T>[size];
	for(int i=0; i<size; i++)
	{
		memcpy(&perceptrons[i], &temp, sizeof(temp));
	}
}

template <typename T> Layer<T>::~Layer()
{
	delete[] perceptrons;
}

template <typename T> int Layer<T>::forwardProp(int prevLayerSize_, T* inputs, T* outputs)
{
	if(prevLayerSize != prevLayerSize_)
		return 1;
	else
	{
		for(int i=0; i<size; i++)
		{
			outputs[i] = perceptrons[i].forwardProp(inputs);
		}
		return 0;
	}
}

template <typename T> int Layer<T>::setWeights(int prevLayerSize_, int size_, T** weights)
{
	if(prevLayerSize != prevLayerSize_ || size != size_)
		return 1;
	else
	{
		for(int i=0; i<size; i++)
		{
			perceptrons[i].setWeights(prevLayerSize, weights[i]);
		}
		return 0;
	}
}

template <typename T> int Layer<T>::setBiases(int prevLayerSize_, T* biases)
{
	if(prevLayerSize != prevLayerSize_)
		return 1;
	else
	{
		for(int i=0; i<size; i++)
		{
			perceptrons[i].setBias(biases[i]);
		}
		return 0;
	}
}

template <typename T> int Layer<T>::reset()
{
	for(int i=0; i<size; i++)
	{
		perceptrons[i].reset();
	}
}

template class Layer<float>;
