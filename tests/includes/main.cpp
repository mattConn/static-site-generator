#include <iostream>
#include "../../page.h"

using namespace std;

int main()
{
    page p("main.txt");

    for(int i = 0; i < p.getLineCount(); i++)
	    cout << p.getLine(i) << endl;

    return 0;
}
