#include <unistd.h>
#include <string>
#include "global.h"

// unistd get current working directory
std::string getWorkingDir()
{
   char tmp[260];
   return ( getcwd(tmp, sizeof(tmp)) ? std::string(tmp) : std::string("") );
}

std::string baseDir = getWorkingDir();
