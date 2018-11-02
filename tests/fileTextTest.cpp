#include <iostream>
#include "../fileText.h"

using namespace std;

int main()
{

    fileText file; // default constructor
    file.copyFile("test.txt");

    // get file name (no name)
    cout << file.getFileName() << endl;

    // output lines
    for(int i = 0; i < file.getLineCount(); i++)
        cout << file.getLine(i) << endl;

    // testing file copying (copying file twice)
    file.copyFile("test.txt");

    // testing line vector
    for(int i = 0; i < file.getLineCount(); i++)
        cout << file.getLine(i) << endl;

    // testing file name vector
    for(int i = 0; i < file.getFileNameCount(); i++)
        cout << file.getFileName(i) << endl;

    return 0;
}
