#pragma once

#include "fileText.h"

class page : public fileText
{
	// directory of program execution
	std::string baseDir;

	// current directory
	std::string currentDir;

    // directive definitions
    const char delimeter = '#'; // delimeters, i.e. "#"
    std::vector<std::string> directiveTokens = {"include"}; // directive token, i.e. "include"

    // tokenize string helper method
	std::vector<std::string> tokenizeStr(const std::string &str); 

    // remove quotation marks
    void stripQuotes(std::string &str);

	// get location of slash / location from back
	int pathSlashLoc(const std::string &fullPath);

	// separate file name from file path
	std::string * splitPath(const std::string &fullPath);

	// unistd get current working directory
	std::string getWorkingDir();


public:

	// default constructor
    page();

	// construct with name of file
    page(const std::string &name);

    // copy file to lines std::vector
    bool copyFile(const std::string &name);

	// handle directives (i.e. include file on #include)
	void handleDirectives(const std::string &line); 

    char getDelimeter(){ return delimeter; } // get delimeter
    std::vector<std::string> getDirectiveTokens(){ return directiveTokens; } // get directiveTokens
};
