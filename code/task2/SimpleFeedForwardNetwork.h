#pragma once
#include <math.h>
#include <vector>

using namespace std;

class SimpleFeedForwardNetwork
{
public:
	void initialize(int seed);

	void train(const vector< vector< int > >& x,
		const vector< vector<int> >& y, size_t numEpochs);

	SimpleFeedForwardNetwork(double alpha, size_t hiddenLayerSize, size_t inputLayerSize, size_t outputLayerSize, size_t numLayers) :
		alpha(alpha), hiddenLayerSize(hiddenLayerSize), inputLayerSize(inputLayerSize), outputLayerSize(outputLayerSize), numLayers(numLayers) {}

private:
	vector< vector< vector< double > > > hiddenLayerWeights; // [from][to]
	vector< vector< double > > outputLayerWeights;

	double alpha;
	size_t hiddenLayerSize;
	size_t inputLayerSize;
	size_t outputLayerSize;
	size_t numLayers;


	inline double g(double x) {return 1.0 / (1.0 + exp(-x)); }
	inline double gprime(double y) {return y * (1 - y); }
};
