#pragma once
#define MAX_PATH_SIZE 400
#include "miniz.h"
#include <string.h>
#include <stdio.h>

/**
* @file UnzipIt.h
* running functions that requiring unzipping a zip file from UnzipIt module.
* this module using minizip functions.
*/


/**
 * @brief function that gets a path of the zip file and a path to destination folder,
     and extract the data of the zip file into that folder
 * @param zipFilePath the path to the zip file
 * @param destPath the destination folder
 * @return a string that says if succeed or failed and if so then why.
*/
char *UnZipFile(char *zipFilePath, char *path);


/**
 * @brief function that gets a path and fix it, which means, replace the backslashes to simple slashes
 * example: c:\\nbarc\\dir -> c:/nbar/dir
 * @param path a char* string (terminated by nullbyte)
*/
void FixedPath(char *path);


/**
 * @brief function that gets a string of non-existing path (contains only directories) and creates all the directories for that non-existing path
    so after this function the path exists, the function returns if it succeed or not.
 * @param fullPath non-existing path (contains only directories)
 * @return 1 if succeed, 0 if failed.
*/
_Bool CreateDirectoryRecursive(char *fullPath);


/**
 * @brief a function that gets a path of a file and returns the path of it's parent directory
 * @param fullPath including the file
 * @param dirPath without the file
 * @return
*/
char *GetParentDirectoryPath(char *fullPath, char *dirPath);