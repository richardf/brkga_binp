/*
 * Instance.h
 */

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include <exception>
#include <vector>
#include <string>
#include <ostream>

class Instance {
public:
	Instance(std::string instName, float binCap, int bestSol, std::vector<float> objs);
	~Instance();
	std::string getInstanceName();
	std::vector<float> getObjects();
	float getBinCapacity();
	int getBestKnownSolution();
	int getNumberOfObjects();

private:
	std::string instanceName;
	std::vector<float> objects;
	float binCapacity;
	int bestKnownSolution;

	friend std::ostream& operator<<(std::ostream&, const Instance&);
};



#endif /* INSTANCE_H_ */
