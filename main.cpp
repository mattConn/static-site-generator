#include <iostream>
#include <vector>
#include "page.h"

using namespace std;

int main(int argc, char *argv[])
{
	// check if missing file name cli arg
    if(argc < 2)
	{
		std::cout << "Missing file name argument" << std::endl;
		return 1;
	}

	// list of pages
	std::vector<page*> pageList;

	// store files listed in argv
	for(int i = 1; i < argc; i++)
	{
		pageList.push_back(new page(argv[i]));
	}

	// print content of pages
	for(auto p : pageList)
		for(auto l: p->getLines())
			std::cout << l << std::endl;

    return 0;
}
