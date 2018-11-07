#include <iostream>
#include<vector>
#include "page.h"

using namespace std;

int main(int argc, char *argv[])
{
    // get manifest
    string manifestFname;
    if(argc != 1)
        manifestFname = argv[1];
    else
        manifestFname = "manifest";

    fileText manifest(manifestFname);

    // storage for pages
    vector<page> pages;
    page p("manifest");
    p.getLine(0);

//    pages.push_back(p);

    /*
    page *p;
    for(int i = 0; i < manifest.getLineCount(); i++)
    {
        p = new page;
        p->copyFile(manifest.getLine(i));

        pages.push_back(p);
    }
    */



    return 0;
}
