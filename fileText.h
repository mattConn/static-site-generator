#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//========================
// for capturing file text
//========================

class fileText
{
protected:
    std::string fileName;
    std::vector<std::string> lines;

public:
    fileText(){}; // default
    fileText(const fileText &f){*this = f;}; // copy constructor: uses default assignment
    fileText(const std::string &name){copyFile(name);}; // construct with name of file

	bool openFile(std::fstream &inFile, const std::string &name);

    // copy file to lines std::vector
    bool copyFile(const std::string &name);

    // fileName methods
    std::string getFileName(){return fileName;};

    // get lines
    std::vector<std::string> getLines(){return lines;};

	// print lines
	void printLines(){ for(auto l : lines) std::cout << l << std::endl;};

	// overloaded operators
	//=====================
	// +=
	fileText &operator+=(const fileText &rhs);
};
