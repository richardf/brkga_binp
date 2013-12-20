/*
 * FitnessCalculator.h
 *
 */

#ifndef FITNESSCALCULATOR_H_
#define FITNESSCALCULATOR_H_

#include <cmath>
#include "Instance.h"
#include "Solution.h"

class FitnessCalculator {
public:
	static const short NUMBER_BOXES_FITNESS = 0;
	static const short BOX_USAGE_FITNESS = 1;
	static const short FALKENAUER_FITNESS = 2;

	static double calculate(Solution &solution, Instance &instance, int fitnessFunction);

private:
	FitnessCalculator();
	~FitnessCalculator();
	static double calculateWithNumberBoxes(Solution &solution);
	static double calculateWithBoxUsage(Solution &solution, Instance &instance);
	static double calculateWithFalkenauer(Solution &solution, Instance &instance);
};


#endif /* FITNESSCALCULATOR_H_ */
