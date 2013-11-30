/*
 * BinPackingDecoder.cpp
 */

#include "BinPackingDecoder.h"

BinPackingDecoder::BinPackingDecoder() { }

BinPackingDecoder::~BinPackingDecoder() { }

// Runs in \Theta(n \log n):
double BinPackingDecoder::decode(const std::vector< double >& chromosome) const {
	std::vector< std::pair< double, unsigned > > ranking(chromosome.size());

	for(unsigned i = 0; i < chromosome.size(); ++i) {
		ranking[i] = std::pair< double, unsigned >(chromosome[i], i);
	}

	// Here we sort 'permutation', which will then produce a permutation of [n] in pair::second:
	std::sort(ranking.begin(), ranking.end());

	// permutation[i].second is in {0, ..., n - 1}; a permutation can be obtained as follows
	std::list< unsigned > permutation;
	for(std::vector< std::pair< double, unsigned > >::const_iterator i = ranking.begin();
			i != ranking.end(); ++i) {
		permutation.push_back(i->second);
	}

	// sample fitness is the first allele
	return chromosome.front();
}
