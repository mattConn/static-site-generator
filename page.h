#pragma once

#include "fileText.h"

class page : public fileText
{
    // directive definitions
    char delimeter = '#';
    std::vector<std::string> directiveTokens; // directive token, i.e. "include"

    // tokenize string helper method
    void tokenizeStr(const std::string &str, std::vector<std::string> &tokens);

    // remove quotation marks
    void stripQuotes(std::string &str);

public:
    page(){directiveTokens.push_back("include");}; //default

    page(const std::string &name) // construct with name of file
    {
        directiveTokens.push_back("include");
        copyFile(name);
    };

    // construct with name of file and delimeter and include dir.
    page(const std::string &name, const char &delim, const std::string &dir) : delimeter(delim)
    {
        directiveTokens.push_back(dir);
        copyFile(name);
    };

    // copy file to lines vector
    bool copyFile(const std::string &name);

    // directive list methods
    char getDelimeter(){return delimeter;}
    std::string getdirectiveTokens(){return directiveTokens.back();} // get last directiveTokens
    std::string getdirectiveTokens(const int &index){return directiveTokens[index];} // get directive label by index
    int getdirectiveTokensLength(){return directiveTokens.size();}; // num of directiveTokenss used

    // append lines from another page obj.
    void appendLines(page &p);
};
