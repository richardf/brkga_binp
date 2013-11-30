/*
 * ORLibraryInstanceReader.cpp
 */

#include "ORLibraryInstanceReader.h"

ORLibraryInstanceReader::ORLibraryInstanceReader() { }
ORLibraryInstanceReader::~ORLibraryInstanceReader() { }

Instance& ORLibraryInstanceReader::readInstance(std::string filename) {
	std::ifstream file;
	std::string instanceName;
	float binCapacity;
	int numberOfItens;
	int bestSolSize;
	std::vector<float> objects;

	openInstanceFile(filename, file);
	file >> instanceName;
	file >> binCapacity >> numberOfItens >> bestSolSize;

	for(int i=0; i < numberOfItens; i++) {
		float data;
		file >> data;
		objects.push_back(data);
	}

	return *new Instance(instanceName, binCapacity, bestSolSize, objects);
}

int ORLibraryInstanceReader::openInstanceFile(std::string filename, std::ifstream& stream) {
	stream.open(filename);

	if(stream.good()) {
		return 1;
	} else {
		throw std::invalid_argument("File not found.");
	}
}
