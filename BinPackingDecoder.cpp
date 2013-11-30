/*
 * BinPackingDecoder.cpp
 */

#include "BinPackingDecoder.h"
BinPackingDecoder::BinPackingDecoder() { }

BinPackingDecoder::~BinPackingDecoder() { }

double BinPackingDecoder::decode(const std::vector< double >& chromosome) const {
	std::vector< std::pair< double, unsigned > > ranking(chromosome.size());
	std::vector<unsigned> selectionOrder;
	Instance instance = ORLibraryInstanceReader::getInstance();
	Solution solution = Solution(instance);

	for(unsigned i = 0; i < chromosome.size(); ++i) {
		ranking[i] = std::pair< double, unsigned >(chromosome[i], i);
	}

	// Here we sort 'permutation', which will then produce a permutation of [n] in pair::second:
	std::sort(ranking.begin(), ranking.end());

	for(unsigned i = 0; i < ranking.size(); i++) {
		selectionOrder.push_back(ranking[i].second);
	}


	for( std::vector<unsigned>::const_iterator i = selectionOrder.begin(); i != selectionOrder.end(); ++i) {
	    std::cout << *i << ' ';
		Constructor::insertObject(*i, solution, instance, Constructor::FIRST_FIT_STRATEGY);
	}
	std::cout << std::endl;

	solution.printSolution();

	// sample fitness is the first allele
	return chromosome.front();
}
