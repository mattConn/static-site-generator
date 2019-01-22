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
    std::fstream inFile;
    std::string fileName;
    std::vector<std::string> lines;

public:
    fileText(){}; // default
    fileText(const std::string &name){copyFile(name);}; // construct with name of file

	bool openFile(const std::string &name);

    // copy file to lines std::vector
    bool copyFile(const std::string &name);

    // fileName methods
    std::string getFileName(){return fileName;};

    // get a line by index or last line
    std::string getLine(){return lines.back();};
    std::string getLine(const int &lineIndex){return lines[lineIndex];};

    // get line count
    int getLineCount(){return lines.size();};
};
