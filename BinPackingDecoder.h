/*
 * BinPackingDecoder.h
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

#ifndef BINPACKINGDECODER_H
#define BINPACKINGDECODER_H

#include <list>
#include <vector>
#include <algorithm>

class BinPackingDecoder {
public:
	BinPackingDecoder();
	~BinPackingDecoder();

	double decode(const std::vector< double >& chromosome) const;

private:
};

#endif
