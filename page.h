#pragma once

#include "fileText.h"

class page : public fileText
{
    fstream inFile;

    // directive definitions
    char delimeter = '#';
    vector<string> directiveTokens; // directive token, i.e. "include"

    // tokenize string helper method
    void tokenizeStr(const string &str, vector<string> &tokens);

    // remove quotation marks
    void stripQuotes(string &str);

public:
    page(){directiveTokens.push_back("include");}; //default

    page(const string &name) // construct with name of file
    {
        directiveTokens.push_back("include");
        copyFile(name);
    };

    // construct with name of file and delimeter and include dir.
    page(const string &name, const char &delim, const string &dir) : delimeter(delim)
    {
        directiveTokens.push_back(dir);
        copyFile(name);
    };

    // copy file to lines vector
    void copyFile(const string &name);

    // directive list methods
    char getDelimeter(){return delimeter;}
    string getdirectiveTokens(){return directiveTokens.back();} // get last directiveTokens
    string getdirectiveTokens(const int &index){return directiveTokens[index];} // get directive label by index
    int getdirectiveTokensLength(){return directiveTokens.size();}; // num of directiveTokenss used

    // append lines from another page obj.
    void appendLines(page &p);
};
