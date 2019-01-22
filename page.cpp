#include "page.h"

void page::copyFile(const std::string &name)
{
    std::string line; // buffer for lines of file
    fileName.push_back(name);
    inFile.open(fileName.back().c_str());
    fileExists(inFile);

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
            // checking std::string starting at 1 (ignore delimeter)
            std::string possibleDirectiveTokens = line.substr(1, line.find(' ')-1);

            // compare with possible directives in directiveTokens
            for(int i = 0; i < directiveTokens.size(); i++)
            {
                // if directive found in line
                // =======================
                if(directiveTokens[i] == possibleDirectiveTokens)
                {
                    // tokenize string: get found directive and following instructions
                    std::vector<std::string> lineTokens;
                    tokenizeStr(line, lineTokens);

                    // execute directive instructions
                    // ==============================
                    if(lineTokens[0] == "include")
                    {
                        // remove quotation marks if present
                        stripQuotes(lineTokens[1]);

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

void page::tokenizeStr(const std::string &str, std::vector<std::string> &tokens)
{
    int beg, end; // beginning and end of substr.
    beg = end = 1; // beg. is 1 to ignore delimeter

    while(end != -1) // until out of range (like std::string::npos)
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

void page::stripQuotes(std::string &str)
{
    // quotation at front
    if(str.front() == '"')
        str.erase(0,1);
    // quotation at back
    if(str.back() == '"')
        str.pop_back();
}
