#pragma once

#include "fileText.h"

class page : public fileText
{
    // directive definitions
    const char delimeter = '#'; // delimeters, i.e. "#"
    std::vector<std::string> directiveTokens; // directive token, i.e. "include"

    // tokenize string helper method
    void tokenizeStr(const std::string &str, std::vector<std::string> &tokens);

    // remove quotation marks
    void stripQuotes(std::string &str);

public:
    page(){directiveTokens.push_back("include");}; // default constructor

    page(const std::string &name) // construct with name of file
    {
        directiveTokens.push_back("include");
        copyFile(name);
    };

	// construct with name of file and directive tokens
    page(const std::string &name, const std::initializer_list<std::string> dirTokens) 
    {
		for(auto d : dirTokens)
        	directiveTokens.push_back(d);

        copyFile(name);
    };

    // directive list methods
    char getDelimeter(){ return delimeter; }
    std::vector<std::string> getDirectiveTokens(){ return directiveTokens; } // get directiveTokens
};
