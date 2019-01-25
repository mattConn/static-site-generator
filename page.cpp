#include "page.h"

std::vector<std::string> page::tokenizeStr(const std::string &str)
{
	std::vector<std::string> tokens; // store tokens

    int beg, end; // beginning and end of substr.
    beg = end = 1; // beg. is 1 to ignore delimeter

    while(end != -1) // until out of range (like std::string::npos)
    {
        end = str.find(' ',beg);
        tokens.push_back(str.substr(beg, end - beg));
        beg = end+1;
    }

	return tokens;
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

// copy file text to lines vector
bool page::copyFile(const std::string &name)
{
    if(!lines.empty()) lines.clear(); // clear lines vector (to prevent appending lines)

    std::string line; // buffer for lines of file
    fileName = name; // store file's name

    std::fstream inFile; // file stream

    if(!openFile(inFile, fileName)) return false;

    // store file lines
    while(getline(inFile, line)) handleDirectives(line);

    inFile.close();

    return true;
}

void page::handleDirectives(const std::string &line)
{
	// iterate over lines to find directive
	for(auto t : directiveTokens) // iterate over directive tokens
	{
		if( line.find( delimeter + t ) != -1 ) // if directive found
		{
			if(t == "include") lines.push_back(">"+line);
		}
		else
			lines.push_back(line); // no directive, store line
	}
	
}
