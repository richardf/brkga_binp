/*
 * BinPackingDecoder2N.cpp
 */

#include "BinPackingDecoder2N.h"
BinPackingDecoder2N::BinPackingDecoder2N(int fitness) {
	fitnessFunction = fitness;
}

BinPackingDecoder2N::~BinPackingDecoder2N() { }

double BinPackingDecoder2N::decode(const std::vector< double >& chromosome) const {
	Instance instance = ORLibraryInstanceReader::getInstance();

	Solution *solution = decodeIt(chromosome);
	double fitness = FitnessCalculator::calculate(*solution, instance, fitnessFunction);
	delete solution;

	return fitness;
}

int BinPackingDecoder2N::boxesUsed(const std::vector< double >& chromosome) const {
	Solution *sol = decodeIt(chromosome);
	int size = sol->getBoxes().size();
	delete sol;
	return size;
}

Solution* BinPackingDecoder2N::decodeIt(const std::vector< double >& chromosome) const {
	std::vector< std::pair< double, unsigned > > ranking(chromosome.size() / 2);
	std::vector<unsigned> selectionOrder;
	std::vector<int> constructorToUse;
	Instance instance = ORLibraryInstanceReader::getInstance();
	Solution *solution = new Solution(instance);

	for(unsigned i = 0; i < chromosome.size() / 2; ++i) {
		ranking[i] = std::pair< double, unsigned >(chromosome[i], i);
	}

	std::sort(ranking.begin(), ranking.end());

	for(unsigned i = 0; i < ranking.size(); ++i) {
		selectionOrder.push_back(ranking[i].second);
	}

	for(unsigned i = 0; i < ranking.size(); ++i) {
		int constructor;
		unsigned beginOfConstructors = chromosome.size() / 2;

		if(chromosome[selectionOrder[i] + beginOfConstructors] <= 0.50) {
			constructor = Constructor::FIRST_FIT_STRATEGY;
		} else {
			constructor = Constructor::BEST_FIT_STRATEGY;
		}
		constructorToUse.push_back(constructor);
	}

	int idx = 0;
	for( std::vector<unsigned>::const_iterator i = selectionOrder.begin(); i != selectionOrder.end(); ++i) {
		Constructor::insertObject(*i, *solution, instance, constructorToUse[idx++]);
	}

	return solution;
}
