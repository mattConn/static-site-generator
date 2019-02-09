#include "page.h"
#include <unistd.h>

// default constructor
page::page(){ currentDir = getWorkingDir(); };

// construct with name of file
page::page(const std::string &name) : page()
{ 
	if(getFileName(name).length() > 0)
		copyFile(currentDir + '/' + getFileName(name));
	else
		copyFile(getFileName(name));
};

// unistd get current directory
std::string page::getWorkingDir()
{
   char tmp[260];
   return ( getcwd(tmp, sizeof(tmp)) ? std::string( tmp ) : std::string("") );
}

// separate file name from file path
std::string page::getFileDir(const std::string &fullPath)
{
	int slashLoc = fullPath.rfind("/");

	return ( slashLoc < 0 ? "" : fullPath.substr(0, slashLoc) );
}

std::string page::getFileName(const std::string &fullPath)
{
	int slashLoc = fullPath.rfind("/");

	return ( slashLoc < 0 ? fullPath : fullPath.substr(slashLoc+1, fullPath.length() - slashLoc+1) );
}

// unistd chdir wrapper function
bool page::changeDir(const std::string &path)
{
	if( chdir(path.c_str()) < 0 ) // failure
		return false;
	else
		currentDir = path; // success; update current dir

	return true;
}

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
    if(str.front() == '"') str.erase(0,1);
    // quotation at back
    if(str.back() == '"') str.pop_back();
}

// copy file text to lines vector
bool page::copyFile(const std::string &name)
{
    if(!lines.empty()) lines.clear(); // clear lines vector (to prevent appending lines)

    std::string line; // buffer for lines of file
    fileName = name; // store file's name

    std::fstream inFile; // file stream

    if(!openFile(inFile, name)) return false;

    // store file lines
    while(getline(inFile, line)) handleDirectives(line);

    inFile.close();

    return true;
}

void page::handleDirectives(const std::string &line)
{
	// iterate over lines to find directive
	for(auto token : directiveTokens) // iterate over directive tokens
	{
		if( line.find( delimeter + token ) != -1 ) // if directive found
		{
			std::string filePath = tokenizeStr(line)[1];
			stripQuotes(filePath);

			changeDir(getFileDir(filePath));	

			if(token == "include") // include directive
			{
				*this += page(getFileName(filePath)); // append new file's lines
			}
		}
		else
			lines.push_back(line); // no directive, store line
	}
	
}
