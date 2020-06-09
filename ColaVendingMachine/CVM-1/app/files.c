#include "files.h"
#include "devConsole.h"

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <direct.h>
#define getCurrentDirectory _getcwd
#endif
#ifdef __linux__
#include <unistd.h>
#define getCurrentDirectory getcwd
#endif

static char currentDir[FILENAME_MAX + 20] = "";

const char *getCurrentDir(void)
{
   getCurrentDirectory(currentDir, FILENAME_MAX);

   return currentDir;
}

const char *getFullFilePath(const char *relativePath, const char *fname)
{
   getCurrentDirectory(currentDir, FILENAME_MAX);
   strcat(strcat(currentDir, relativePath), fname);

   return currentDir;
}
