#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fileText.h"

//========================
// for capturing file text
//========================

// check if file exists
void fileText::fileExists(const std::fstream &openFile)
{
    if(!openFile)
    {
        std::cout << "ERROR: File `" << fileName.back() << "`" << " could not be opened. Exiting." << std::endl;
        exit(EXIT_FAILURE);

        return;
    }
}

void fileText::copyFile(const std::string &name)
{
    std::string line; // buffer for lines of file
    fileName.push_back(name);

    inFile.open(fileName.back().c_str());

    fileExists(inFile);

    while(getline(inFile, line))
        lines.push_back(line);

    inFile.close();
}
