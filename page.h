#pragma once

#include "fileText.h"

class page : public fileText
{
    // directive definitions
    const char delimeter = '#'; // delimeters, i.e. "#"
    std::vector<std::string> directiveTokens = {"include"}; // directive token, i.e. "include"

    // tokenize string helper method
	std::vector<std::string> tokenizeStr(const std::string &str); 

    // remove quotation marks
    void stripQuotes(std::string &str);

public:


    page(){directiveTokens.push_back("include");}; // default constructor

    page(const std::string &name) // construct with name of file
    {
        copyFile(name);
    };

    // copy file to lines std::vector
    bool copyFile(const std::string &name);

	// handle directives (i.e. include file on #include)
	void handleDirectives(const std::string &line); 

    char getDelimeter(){ return delimeter; } // get delimeter
    std::vector<std::string> getDirectiveTokens(){ return directiveTokens; } // get directiveTokens
};
