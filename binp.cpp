#include <iostream>
#include <unistd.h>

#include "BinPackingDecoder.h"
#include "ORLibraryInstanceReader.h"
#include "Instance.h"
#include "MTRand.h"
#include "BRKGA.h"

void printUsage() {
	std::cout << "Usage:" << std::endl
		 << "\t-i\tInput file" << std::endl
		 << "\t-p\tSize of population (default: 1000)" << std::endl
		 << "\t-e\tFraction of population to be elite (default: 0.2)" << std::endl
		 << "\t-m\tFraction of population to be replaced by mutants (default: 0.1)" << std::endl
		 << "\t-n\tProbability that offspring inherit an allele from elite parent (default: 0.7)" << std::endl
		 << "\t-k\tNumber of independent populations (default: 1)" << std::endl
		 << "\t-s\tRandom seed (default: 0)" << std::endl
		 << "\t-g\tNumber of generations (default: 100)" << std::endl
		 << "\t-t\tNumber of threads (default: 1)" << std::endl;
}

struct Config {
	Config() : population(1000), frac_elite(0.2), frac_mutants(0.1), prob_elite(0.7), independent_pop(1), seed(0), generations(100), threads(1) {}
	std::string filename;		// instance file
	unsigned population;		// size of population
	float frac_elite;			// fraction of population to be the elite-set
	float frac_mutants;			// fraction of population to be replaced by mutants
	float prob_elite;			// probability that offspring inherit an allele from elite parent
	unsigned independent_pop;	// number of independent populations
	unsigned seed;				// seed for random number generator
	unsigned generations;		// number of generations
	unsigned threads;			// number of threads (for parallel processing)
};

Config parseCommandLine(int argc, char** argv) {
	/* show usage */
	if ( argc == 1 ) {
		printUsage();
		exit(0);
	}

	Config config;

	int opt;
	while ((opt = getopt(argc, argv, "i:p:e:m:n:k:s:g:t:")) != -1)
		switch(opt) {
			case 'i':
				config.filename = optarg;
				break;
			case 'p':
				config.population = atoi(optarg);
				break;
			case 'e':
				config.frac_elite = atof(optarg);
				break;
			case 'm':
				config.frac_mutants = atof(optarg);
				break;
			case 'n':
				config.prob_elite = atof(optarg);
				break;
			case 'k':
				config.independent_pop = atoi(optarg);
				break;
			case 's':
				config.seed = atoi(optarg);
				break;
			case 'g':
				config.generations = atoi(optarg);
				break;
			case 't':
				config.threads = atoi(optarg);
				break;
			case '?':
				std::cout << "Syntax error" << std::endl;
				exit(1);
		}

	return config;
}


int main(int argc, char* argv[]) {
	Config config = parseCommandLine(argc, argv);

	BinPackingDecoder decoder(FitnessCalculator::BOX_USAGE_FITNESS, Constructor::FIRST_FIT_STRATEGY);	// initialize the decoder
	MTRand rng(config.seed);			// initialize the random number generator
	Instance instance = ORLibraryInstanceReader::readInstance(config.filename);

	// initialize the BRKGA-based heuristic
	BRKGA< BinPackingDecoder, MTRand > algorithm(instance.getNumberOfObjects(), config.population, config.frac_elite,
			config.frac_mutants, config.prob_elite, decoder, rng, config.independent_pop, config.threads);
	
	unsigned generation = 0;		// current generation
//	const unsigned X_INTVL = 100;	// exchange best individuals at every 100 generations
//	const unsigned X_NUMBER = 2;	// exchange top 2 best
	do {
		algorithm.evolve();	// evolve the population for one generation
		generation++;
//		if((++generation) % X_INTVL == 0) {
//			algorithm.exchangeElite(X_NUMBER);	// exchange top individuals
//		}
	} while (generation < config.generations);
	

	std::cout << instance << std::endl;
	std::cout << decoder.boxesUsed(algorithm.getBestChromosome()) << std::endl;
	std::cout << algorithm.getBestFitness() << std::endl;
	return 0;
}
