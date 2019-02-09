#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fileText.h"

//========================
// for capturing file text
//========================

// ** note: constructors defined inline

bool fileText::openFile(std::fstream &inFile, const std::string &name)
{
	inFile.open(name);

	if(!inFile)
	{
		std::cerr << "** WARNING: could not open file " << name << " **" << std::endl;
		return false;
	}

	return true;
}

// copy file text to lines vector
bool fileText::copyFile(const std::string &name)
{
	if(!lines.empty()) lines.clear(); // clear lines vector (to prevent appending lines)

    std::string line; // buffer for lines of file
    fileName = name; // store file's name

	std::fstream inFile; // file stream

	if(!openFile(inFile, fileName)) return false;

	// store file lines
    while(getline(inFile, line)) lines.push_back(line);

    inFile.close();

	return true;
}

// overloaded +=
fileText &fileText::operator+=(const fileText &rhs)
{
	for(auto l : rhs.lines)
		lines.push_back(l);

	return *this;
}

