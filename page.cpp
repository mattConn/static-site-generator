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

void page::handleDirectives()
{
	// iterate over lines to find directive
	for(auto l : lines)
	{
		for(auto t : directiveTokens) // iterate over directive tokens
		{
			if( l.find( delimeter + t ) != -1 ) // if directive found
			{
				if(t == "include") std::cout << l << std::endl;
			}
		}
	}
	
}
