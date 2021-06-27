#include <string.h>
#include <stdio.h>
#include "UnzipIt.h"

/**
* @file Main.c
* running function Unzip from UnzipIt where the first argument is the path of the zip file,
* in the same directory which the zip file is located it will extract the files inside of it.
*/

int main(size_t argc, char *argv[])
{
    /* Simple unzipping */
    char pathDir[MAX_PATH_SIZE] = "";
    if (argv[1] != NULL)
    {
        GetParentDirectoryPath(argv[1], pathDir);
        printf(UnZipFile(argv[1], pathDir, ""));
    }
    else
    {
        printf("no path found");
    }
}
