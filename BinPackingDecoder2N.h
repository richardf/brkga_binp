/*
 * BinPackingDecoder2N.h
 *
 * Decoder that uses a chromosome of size 2N. The fitness function to be utilized (FitnessCalculator)
 * must be provided as a constructor argument. The first N positions of chromosome indicates the
 * insertion order of each element, while the N+1 to 2N positions indicates which constructor algorithm
 * should be used, in the following way:
 *
 *   First Fit Algorithm, if chromossome[i] <= 0.5
 *   Best Fit Algorithm, otherwise
 *
 * Any decoder must have the format below, i.e., implement the method decode(std::vector< double >&)
 * returning a double corresponding to the fitness of that vector. If parallel decoding is to be
 * used in the BRKGA framework, then the decode() method _must_ be thread-safe; the best way to
 * guarantee this is by adding 'const' to the end of decode() so that the property will be checked
 * at compile time.
 *
 * The chromosome inside the BRKGA framework can be changed if desired. To do so, just use the
 * first signature of decode() which allows for modification. Please use double values in the
 * interval [0,1) when updating, thus obeying the BRKGA guidelines.
 *
 */

#ifndef BINPACKINGDECODER2N_H
#define BINPACKINGDECODER2N_H

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "Instance.h"
#include "ORLibraryInstanceReader.h"
#include "Solution.h"
#include "Constructor.h"
#include "FitnessCalculator.h"

class BinPackingDecoder2N {
public:
	BinPackingDecoder2N(int fitness);
	~BinPackingDecoder2N();

	double decode(const std::vector< double >& chromosome) const;
	int boxesUsed(const std::vector< double >& chromosome) const;

private:
	short fitnessFunction;
	Solution* decodeIt(const std::vector< double >& chromosome) const;
};

#endif
