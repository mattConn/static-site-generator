#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "fileText.h"

//========================
// for capturing file text
//========================

bool fileText::openFile(const std::string &name)
{
	inFile.open(name);

	if(!inFile)
	{
		std::cout << "** WARNING: could not open file " << fileName << " **" << std::endl;
		return false;
	}

	return true;
}

// copy file text to lines vector
bool fileText::copyFile(const std::string &name)
{
    std::string line; // buffer for lines of file
    fileName = name;

	if(!openFile(fileName)) return false;

	// store file lines
    while(getline(inFile, line)) lines.push_back(line);

    inFile.close();

	return true;
}
