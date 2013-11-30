/*
 * Solution.cpp
 */

#include "Solution.h"

Solution::Solution(Instance& inst) {
	instance = &inst;
}

Solution::~Solution() { }

bool Solution::addObject(int obj, int boxNumber) {
	if(boxes.find(boxNumber) != boxes.end()) {
		if(hasSpaceBox(boxNumber, instance->getObjects()[obj])) {
			assert(std::find(boxes[boxNumber]->begin(), boxes[boxNumber]->end(), obj) == boxes[boxNumber]->end());
			boxes[boxNumber]->push_back(obj);
			return true;
		}
		return false;
	}
	else {
		throw "Box not found";
	}
}

bool Solution::hasSpaceBox(int boxNumber, float weight) {
	float free_weight = amountSpaceInBox(boxNumber);
	if(free_weight >= weight) {
		return true;
	}
	return false;
}

float Solution::amountSpaceInBox(int boxNumber) {
	assert(boxes.find(boxNumber) != boxes.end());
	float used_weight = 0;
	std::vector<int> *objects = boxes[boxNumber];

	for(std::vector<int>::iterator it = objects->begin(); it != objects->end(); it++) {
		used_weight += instance->getObjects()[*it];
	}

	return instance->getBinCapacity() - used_weight;
}

int Solution::createBox() {
	int nextBox = boxes.size();
	boxes.insert(std::pair<int, std::vector<int>* >(nextBox, new std::vector<int>));
	return nextBox;
}
