#include <iostream>
#include <vector>
#include "page.h"

using namespace std;

int main(int argc, char *argv[])
{
    // get manifest
    std::string manifestFname;
    if(argc != 1)
        manifestFname = argv[1];
    else
        manifestFname = "manifest";

    fileText manifest(manifestFname);

    // storage for pages
    std::vector<page> pageStorage;

    for(int i = 0; i < manifest.getLineCount(); i++)
    {

        page p(manifest.getLine(i));

        std::fstream outFile;
        outFile.open("dist/"+p.getFileName());

        int j = 0;
        while(j < p.getLineCount())
        {
            outFile << p.getLine(j) << std::endl;
            j++;
        }

        std::cout << "Wrote to `dist/" << p.getFileName() << "`." << std::endl;

        outFile.close();
    }



    return 0;
}
