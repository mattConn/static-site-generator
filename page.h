#include "fileText.h"

class page : public fileText
{
    // directive definitions
    char delimeter = '#';
    vector<string> dirLabel; // directive label, i.e. "include"

    // index of directive found in string,
    // i.e. dirLabel[dirFoundIndex];
    vector<int> dirFoundIndex;


public:
    page(){dirLabel.push_back("include");}; //default

    page(const string &name) // construct with name of file
    {
        dirLabel.push_back("include");
        copyFile(name);
    };

    // construct with name of file and delimeter and include dir.
    page(const string &name, const char &delim, const string &dir) : delimeter(delim)
    {
        dirLabel.push_back(dir);
        copyFile(name);
    };

    // copy file to lines vector
    void copyFile(const string &name);

    // directive list methods
    char getDelimeter(){return delimeter;}
    string getdirLabel(){return dirLabel.back();} // get last dirLabel
    string getdirLabel(const int &index){return dirLabel[index];} // get directive label by index
    int getdirLabelLength(){return dirLabel.size();}; // num of dirLabels used
};

void page::copyFile(const string &name)
{
    string line; // buffer for lines of file
    fileName.push_back(name);
    inFile.open(fileName.back().c_str());
    fileCheck();

    // parse file lines
    while(getline(inFile, line))
    {
        // check for directive
        // ===================
        // 1. Check char. 0 of line to see if it is a delimeter.
        // 2. Get first token in line and check it against list of possible directives (dirLabel)
        // 3. If directive, token line and process directive instructions accordingly

        if(line[0] == delimeter) // if starts with delim., may be directive
        {
            // checking string starting at 1 (ignore delimeter)
            string possibleDirLabel = line.substr(1, line.find(' ')-1);

            // compare with possible directives in dirLabel
            for(int i = 0; i < dirLabel.size(); i++)
            {
                // if directive found in line
                // =======================
                if(dirLabel[i] == possibleDirLabel)
                {
                    // tokenize string: get found directive and following instructions
                    // =========================================================
                    vector<string> lineTokens; // hold directive and following instruction(s)

                    int beg, end; // beginning and end of substr.
                    beg = end = 1; // beg. is 1 to ignore delimeter

                    while(end != -1) // until out of range (like string::npos)
                    {
                        end = line.find(' ',beg);
                        lineTokens.push_back(line.substr(beg, end - beg));
                        beg = end+1;
                    }

                    // ===================
                    // end tokenize string

                    // execute directive instructions
                    // ==============================
                    if(dirLabel[i] == "include")
                    {
                        /*
                        fstream infile;
                        infile.open(lineTokens[1].c_str());

                        string str;
                        while(getline(infile,str))
                            lines.push_back(str);
                        infile.close();
                        */

                        // TODO
                        // successful recursion
                       copyFile(lineTokens[1]);
                    }

                    break; // break out of possible directive comparison loop

                } // end directive found in line
            } // end possible directive comparison
        } // end check when line starts with delimeter

        else // no directive, copy file
            lines.push_back(line); // copy lines

    }

    inFile.close();
};
