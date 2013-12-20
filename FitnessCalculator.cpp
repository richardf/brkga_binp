/*
 * FitnessCalculator.cpp
 *
 */

#include "FitnessCalculator.h"

FitnessCalculator::FitnessCalculator() { }
FitnessCalculator::~FitnessCalculator() { }

double FitnessCalculator::calculate(Solution &solution, Instance &instance, int fitnessFunction) {
	if(fitnessFunction == FALKENAUER_FITNESS) {
		return calculateWithFalkenauer(solution, instance);
	} else if(fitnessFunction == NUMBER_BOXES_FITNESS) {
		return calculateWithNumberBoxes(solution);
	} else if (fitnessFunction == BOX_USAGE_FITNESS){
		return calculateWithBoxUsage(solution, instance);
	} else {
		throw "Invalid fitness function";
	}
}

double FitnessCalculator::calculateWithNumberBoxes(Solution &solution) {
	return solution.getBoxes().size();
}

double FitnessCalculator::calculateWithBoxUsage(Solution &solution, Instance &instance) {
	int numberOfBoxes = solution.getBoxes().size();
	float availableSpace = instance.getBinCapacity() * numberOfBoxes;
	std::map< int, std::vector<int>* > boxes = solution.getBoxes();
	std::map< int, std::vector<int>* >::iterator mapIter;

	for (mapIter = boxes.begin(); mapIter != boxes.end(); ++mapIter) {
		std::vector< int >::iterator vectorIter;
		for (vectorIter = mapIter->second->begin(); vectorIter != mapIter->second->end(); ++vectorIter) {
			availableSpace -= instance.getObjects()[*vectorIter];
		}
	}

	return availableSpace;
}

double FitnessCalculator::calculateWithFalkenauer(Solution &solution, Instance &instance) {
	int numberOfBoxes = solution.getBoxes().size();
	float binCap = instance.getBinCapacity();
	std::map< int, std::vector<int>* > boxes = solution.getBoxes();
	std::map< int, std::vector<int>* >::iterator mapIter;
	double sumOfUsageRatio = 0;

	for (mapIter = boxes.begin(); mapIter != boxes.end(); ++mapIter) {
		std::vector< int >::iterator vectorIter;
		double boxUsage = 0;
		for (vectorIter = mapIter->second->begin(); vectorIter != mapIter->second->end(); ++vectorIter) {
			boxUsage += instance.getObjects()[*vectorIter];
		}

		sumOfUsageRatio += pow(boxUsage / binCap, 2);
	}

	return -1 * (sumOfUsageRatio / numberOfBoxes);
}
