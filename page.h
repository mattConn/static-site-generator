#pragma once

#include "global.h"
#include "fileText.h"


class page : public fileText
{
	// current directory
	std::string currentDir;

    // directive definitions
    const char delimeter = '#'; // delimeters, i.e. "#"
    std::vector<std::string> directiveTokens = {"include"}; // directive token, i.e. "include"

    // tokenize string helper method
	std::vector<std::string> tokenizeStr(const std::string &str); 

    // remove quotation marks
    void stripQuotes(std::string &str);

	// separate file dir from file path
	std::string getFileDir(const std::string &fullPath);

	// separate file name from file path
	std::string getFileName(const std::string &fullPath);

	// unistd chdir wrapper function
	bool changeDir(const std::string &path);

public:

	// default constructor
    page();

	// construct with name of file
    page(const std::string &name);

	// construct with name of file and current dir
    page(const std::string &name, const std::string &curDir);

    // copy file to lines std::vector
    bool copyFile(const std::string &name);

	// handle directives (i.e. include file on #include)
	void handleDirectives(const std::string &line); 

    char getDelimeter(){ return delimeter; } // get delimeter
    std::vector<std::string> getDirectiveTokens(){ return directiveTokens; } // get directiveTokens
};
