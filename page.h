#include "fileText.h"

class page : public fileText
{
    string delimeter = "#";
    string directive = "include";

public:
    page(){}; //default
    page(const string &name){copyFile(name);}; // construct with name of file

    // construct with name of file and delimeter and include dir.
    page(const string &name, const string &delim, const string &dir) : delimeter(delim), directive(dir)
    {copyFile(name);};

    // copy file to lines vector
    void copyFile(const string &name);

    string getDelimeter(){return delimeter;}
    string getDirective(){return directive;}
};

void page::copyFile(const string &name)
{
    string line; // buffer for lines of file
    fileName.push_back(name);
    inFile.open(fileName.back().c_str());
    fileCheck();

    while(getline(inFile, line))
    {
        /*
        if(INCLUDE DIRECTIVE)
            copyFile(INCLUDE DIRECTIVE)
        else
        */
        lines.push_back(line);
    }

    inFile.close();
}
