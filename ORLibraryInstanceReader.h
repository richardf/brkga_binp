/*
 * ORLibraryInstanceReader.h
 */

#ifndef ORLIBRARYINSTANCEREADER_H_
#define ORLIBRARYINSTANCEREADER_H_

#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <stdexcept>
#include "Instance.h"

class ORLibraryInstanceReader {
public:
	~ORLibraryInstanceReader();
	static Instance& readInstance(std::string filename);
	static Instance& getInstance();

private:
	ORLibraryInstanceReader();
	static int openInstanceFile(std::string filename, std::ifstream& stream);
	static Instance *instance;

};


#endif /* ORLIBRARYINSTANCEREADER_H_ */
