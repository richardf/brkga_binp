#include <iostream>
#include "BinPackingDecoder.h"
#include "ORLibraryInstanceReader.h"
#include "Instance.h"
#include "MTRand.h"
#include "BRKGA.h"

int main(int argc, char* argv[]) {
	const unsigned n = 100;		// size of chromosomes
	const unsigned p = 1000;	// size of population
	const double pe = 0.20;		// fraction of population to be the elite-set
	const double pm = 0.10;		// fraction of population to be replaced by mutants
	const double rhoe = 0.70;	// probability that offspring inherit an allele from elite parent
	const unsigned K = 1;		// number of independent populations
	const unsigned MAXT = 1;	// number of threads for parallel decoding
	
	BinPackingDecoder decoder;			// initialize the decoder
	
	const long unsigned rngSeed = 0;	// seed to the random number generator
	MTRand rng(rngSeed);				// initialize the random number generator
	
	// initialize the BRKGA-based heuristic
	BRKGA< BinPackingDecoder, MTRand > algorithm(n, p, pe, pm, rhoe, decoder, rng, K, MAXT);
	
	unsigned generation = 0;		// current generation
//	const unsigned X_INTVL = 100;	// exchange best individuals at every 100 generations
//	const unsigned X_NUMBER = 2;	// exchange top 2 best
	const unsigned MAX_GENS = 1000;	// run for 1000 gens
//	do {
//		algorithm.evolve();	// evolve the population for one generation
//		generation++;
//		if((++generation) % X_INTVL == 0) {
//			algorithm.exchangeElite(X_NUMBER);	// exchange top individuals
//		}
//	} while (generation < MAX_GENS);
	
//	std::cout << "Best solution found has objective value = "
//	 		<< algorithm.getBestFitness() << std::endl;
	
	Instance instance = ORLibraryInstanceReader::readInstance("inst.txt");
	std::cout << instance << std::endl;
	return 0;
}
