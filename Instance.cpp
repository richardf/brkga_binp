/*
 * Instance.cpp
 *
 */

#include "Instance.h"

Instance::Instance(std::string instName, float binCap, int bestSol, std::vector<float> objs) {
	instanceName = instName;
	binCapacity = binCap;
	bestKnownSolution = bestSol;
	objects = objs;
}

Instance::~Instance() { }

std::ostream& operator<<(std::ostream &strm, const Instance &inst) {
  return strm << "Instance(" << "instanceName=" << inst.instanceName << ", binCapacity="<< inst.binCapacity
		  << ", bestKnownSol=" << inst.bestKnownSolution << ", numberOfObjects=" << inst.objects.size() << ")";
}

int Instance::getNumberOfObjects() {
	return objects.size();
}

std::string Instance::getInstanceName() {
	return instanceName;
}

float Instance::getBinCapacity() {
	return binCapacity;
}

int Instance::getBestKnownSolution() {
	return bestKnownSolution;
}

std::vector<float> Instance::getObjects() {
	return objects;
}
