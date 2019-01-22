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
    std::vector<std::string> fileName;
    std::vector<std::string> lines;

    void fileExists(const std::fstream &openFile);// check if file exists

public:
    fileText(){}; // default
    fileText(const std::string &name){copyFile(name);}; // construct with name of file

    // copy file to lines std::vector
    void copyFile(const std::string &name);

    // fileName methods
    std::string getFileName(){return fileName.back();};
    std::string getFileName(const int &nameIndex){return fileName[nameIndex];};

    // get fileName count
    int getFileNameCount(){return fileName.size();};

    // get a line by index or last line
    std::string getLine(){return lines.back();};
    std::string getLine(const int &lineIndex){return lines[lineIndex];};

    // get line count
    int getLineCount(){return lines.size();};
};
