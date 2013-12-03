/*
 * BinPackingDecoder.cpp
 */

#include "BinPackingDecoder.h"
BinPackingDecoder::BinPackingDecoder(int fitness, int constructor) {
	fitnessFunction = fitness;
	constructorStrategy = constructor;
	instance = ORLibraryInstanceReader::getInstance();
}

BinPackingDecoder::~BinPackingDecoder() { }

double BinPackingDecoder::decode(const std::vector< double >& chromosome) const {
	std::vector< std::pair< double, unsigned > > ranking(chromosome.size());
	std::vector<unsigned> selectionOrder;

	Solution *solution = decodeIt(chromosome);
	double fitness = FitnessCalculator::calculate(*solution, *instance, fitnessFunction);
	delete solution;

	return fitness;
}

int BinPackingDecoder::boxesUsed(const std::vector< double >& chromosome) const {
	Solution *sol = decodeIt(chromosome);
	int size = sol->getBoxes().size();
	delete sol;
	return size;
}

Solution* BinPackingDecoder::decodeIt(const std::vector< double >& chromosome) const {
	std::vector< std::pair< double, unsigned > > ranking(chromosome.size());
	std::vector<unsigned> selectionOrder;
	Solution *solution = new Solution(*instance);

	for(unsigned i = 0; i < chromosome.size(); ++i) {
		ranking[i] = std::pair< double, unsigned >(chromosome[i], i);
	}

	std::sort(ranking.begin(), ranking.end());

	for(unsigned i = 0; i < ranking.size(); i++) {
		selectionOrder.push_back(ranking[i].second);
	}

	for( std::vector<unsigned>::const_iterator i = selectionOrder.begin(); i != selectionOrder.end(); ++i) {
		Constructor::insertObject(*i, *solution, *instance, constructorStrategy);
	}

	return solution;
}
