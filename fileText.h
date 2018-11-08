#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//========================
// for capturing file text
//========================

class fileText
{
protected:
    fstream inFile;
    vector<string> fileName;
    vector<string> lines;

    void fileExists(const fstream &openFile);// check if file exists

public:
    fileText(){}; // default
    fileText(const string &name){copyFile(name);}; // construct with name of file

    // copy file to lines vector
    void copyFile(const string &name);

    // fileName methods
    string getFileName(){return fileName.back();};
    string getFileName(const int &nameIndex){return fileName[nameIndex];};

    // get fileName count
    int getFileNameCount(){return fileName.size();};

    // get a line by index or last line
    string getLine(){return lines.back();};
    string getLine(const int &lineIndex){return lines[lineIndex];};

    // get line count
    int getLineCount(){return lines.size();};
};

// check if file exists
void fileText::fileExists(const fstream &openFile)
{
    if(!openFile)
    {
        cout << "ERROR: File `" << fileName.back() << "`" << " could not be opened. Exiting." << endl;
        exit(EXIT_FAILURE);

        return;
    }
}

void fileText::copyFile(const string &name)
{
    string line; // buffer for lines of file
    fileName.push_back(name);

    inFile.open(fileName.back().c_str());

    fileExists(inFile);

    while(getline(inFile, line))
        lines.push_back(line);

    inFile.close();
}
