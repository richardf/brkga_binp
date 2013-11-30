/*
 * Constructor.cpp
 */

#include "Constructor.h"

Constructor::Constructor() { }

Constructor::~Constructor() { }

void Constructor::insertObject(int objectNumber, Solution &solution, Instance &instance, int strategy) {
	if(strategy == FIRST_FIT_STRATEGY) {
		insertUsingFirstFit(objectNumber, solution, instance);
	}
}

void Constructor::insertUsingFirstFit(int objectNumber, Solution &solution, Instance &instance) {
	std::map< int, std::vector<int>* >::iterator iter;
	std::map< int, std::vector<int>* > boxes = solution.getBoxes();
	int boxToUse = 0;

	iter = boxes.begin();
	bool found = false;

	while(!found && iter != boxes.end()) {
		if(solution.hasSpaceBox(iter->first, instance.getObjects()[objectNumber])) {
			boxToUse = iter->first;
			found = true;
		}

		iter++;
	}

	if(!found) {
		boxToUse = solution.createBox();
	}

	solution.addObject(objectNumber, boxToUse);
}
