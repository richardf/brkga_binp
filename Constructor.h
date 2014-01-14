/*
 * Constructor.h
 *
 * Classic constructor algorithms for one-dimensional bin packing.
 * Currently it implements: First Fit and Best Fit strategies.
 */

#ifndef CONSTRUCTOR_H_
#define CONSTRUCTOR_H_

#include <algorithm>
#include "Solution.h"
#include "Instance.h"

class Constructor {
public:
	static const short FIRST_FIT_STRATEGY = 0;
	static const short BEST_FIT_STRATEGY = 1;

	static void insertObject(int objectNumber, Solution &solution, Instance &instance, int strategy);

private:
	Constructor();
	~Constructor();
	static void insertUsingFirstFit(int objectNumber, Solution &solution, Instance &instance);
	static void insertUsingBestFit(int objectNumber, Solution &solution, Instance &instance);
};


#endif /* CONSTRUCTOR_H_ */
