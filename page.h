#include "fileText.h"

class page : public fileText
{
    fstream inFile;

    // directive definitions
    char delimeter = '#';
    vector<string> directiveTokens; // directive token, i.e. "include"

    // tokenize string helper method
    void tokenizeStr(const string &str, vector<string> &tokens);

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

void page::copyFile(const string &name)
{
    string line; // buffer for lines of file
    fileName.push_back(name);
    inFile.open(fileName.back().c_str());
    fileExists();

    // parse file lines
    while(getline(inFile, line))
    {
        // check for directive
        // ===================
        // 1. Check char. 0 of line to see if it is a delimeter.
        // 2. Get first token in line and check it against list of possible directives (directiveTokens)
        // 3. If directive, token line and process directive instructions accordingly

        if(line[0] == delimeter) // if starts with delim., may be directive
        {
            // checking string starting at 1 (ignore delimeter)
            string possibledirectiveTokens = line.substr(1, line.find(' ')-1);

            // compare with possible directives in directiveTokens
            for(int i = 0; i < directiveTokens.size(); i++)
            {
                // if directive found in line
                // =======================
                if(directiveTokens[i] == possibledirectiveTokens)
                {
                    // tokenize string: get found directive and following instructions
                    vector<string> lineTokens;
                    tokenizeStr(line, lineTokens);

                    // execute directive instructions
                    // ==============================
                    if(directiveTokens[i] == "include")
                    {
                        // copy included file
                        page p(lineTokens[1]);
                        appendLines(p);
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

void page::tokenizeStr(const string &str, vector<string> &tokens)
{
    int beg, end; // beginning and end of substr.
    beg = end = 1; // beg. is 1 to ignore delimeter

    while(end != -1) // until out of range (like string::npos)
    {
        end = str.find(' ',beg);
        tokens.push_back(str.substr(beg, end - beg));
        beg = end+1;
    }
}

// append lines from another page obj.
void page::appendLines(page &p)
{
    for(int i = 0; i < p.getLineCount(); i++)
        lines.push_back(p.getLine(i));
}
