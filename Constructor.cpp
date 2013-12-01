/*
 * Constructor.cpp
 */

#include "Constructor.h"

Constructor::Constructor() { }

Constructor::~Constructor() { }

void Constructor::insertObject(int objectNumber, Solution &solution, Instance &instance, int strategy) {
	if(strategy == FIRST_FIT_STRATEGY) {
		insertUsingFirstFit(objectNumber, solution, instance);
	} else if(strategy == BEST_FIT_STRATEGY) {
		insertUsingBestFit(objectNumber, solution, instance);
	} else {
		throw "Unknown insertion strategy";
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

void Constructor::insertUsingBestFit(int objectNumber, Solution &solution, Instance &instance) {
	std::map< int, std::vector<int>* >::iterator iter;
	std::map< int, std::vector<int>* > boxes = solution.getBoxes();
	std::vector< std::pair< double, unsigned > > spacesEachBox;
	int boxToUse = 0;

	bool found = false;

	for(iter = boxes.begin(); iter != boxes.end(); iter++) {
		double availableSpace = solution.amountSpaceInBox(iter->first);
		double weight = instance.getObjects()[objectNumber];

		if(availableSpace >= weight) {
			spacesEachBox.push_back(std::pair< double, unsigned >(availableSpace, iter->first));
			found = true;
		}
	}

	if(!found) {
		boxToUse = solution.createBox();
	} else {
		std::sort(spacesEachBox.begin(), spacesEachBox.end());
		boxToUse = spacesEachBox[0].second;
	}

	solution.addObject(objectNumber, boxToUse);
}
