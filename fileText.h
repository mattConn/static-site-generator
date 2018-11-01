#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

//========================
// for capturing file text
//========================

class fileText
{
	fstream inFile;
    vector<string> fileName;
	vector<string> lines;

	public:
    fileText(){}; // default
    inline fileText(const string &name){copyFile(name);}; // construct with name of file

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

void fileText::copyFile(const string &name)
{
    string line; // buffer for lines of file
    fileName.push_back(name);

    inFile.open(fileName.back().c_str());

    try{assert(inFile);}
    catch(exception &e)
    {
        cout << fileName.back() << " could not be opened." << endl;
        return;
    }

    while(getline(inFile, line))
        lines.push_back(line);

    inFile.close();
}
