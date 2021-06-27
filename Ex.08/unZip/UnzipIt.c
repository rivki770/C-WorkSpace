#include "UnzipIt.h"
#include "miniz.h"


char *UnZipFile(char *zipFilePath, char *destPath)
{
    mz_zip_archive archive;
    memset(&archive, 0, sizeof(archive));

    auto status = mz_zip_reader_init_file(&archive, zipFilePath, 0);
    if (!status) return "zip file appears invalid...\n";

    int fileCount = (int) mz_zip_reader_get_num_files(&archive);
    if (fileCount == 0)
    {
        mz_zip_reader_end(&archive);
        return "the files in the zip file are not found.. ";
    }
    mz_zip_archive_file_stat file_stat;
    if (!mz_zip_reader_file_stat(&archive, 0, &file_stat))
    {
        mz_zip_reader_end(&archive);
        return "zip file read error...\n";
    }

    char base[MAX_PATH_SIZE] = "";
    char dirPath[MAX_PATH_SIZE] = "";
    char *lastExtractPath = "";
    char *newExtractPath = "";
    strcpy_s(base, sizeof(base), destPath);
    /* turns \\ to / in path string */
    FixedPath(base);
    for (int i = 0; i < fileCount; i++)
    {
        if (!mz_zip_reader_file_stat(&archive, i, &file_stat)) continue;
        /* skip directories for now */
        if (mz_zip_reader_is_file_a_directory(&archive, i)) continue;
        /* make path relative, example:   puppies\0.png */
        char *fileName = file_stat.m_filename;
        char destFile[MAX_PATH_SIZE] = "";
        strcpy_s(destFile, sizeof(destFile), base);
        /* make full dest path, example: C:\Users\naorb\Desktop\puppies\0.png */
        strcat_s(destFile, sizeof(destFile), file_stat.m_filename);
        GetParentDirectoryPath(destFile, dirPath);
        /* get the file's directory path, example: C:\Users\naorb\Desktop\ */
        newExtractPath = dirPath;
        if (strcmp(newExtractPath, lastExtractPath) != 0)
        {
            CreateDirectoryRecursive(dirPath);
        }
        lastExtractPath = dirPath;
        if (!mz_zip_reader_extract_to_file(&archive, i, destFile, 0))
        {
            return "something went wrong when unzipping..";
        }
    }
    /* Close the archive, freeing any resources it was using */
    mz_zip_reader_end(&archive);
    return "success";
}


void FixedPath(char *path)
{
    size_t index = 0;
    while (path[index])
    {
        if (path[index] == '\\')
            path[index] = '/';
        index++;
    }
}


char *GetParentDirectoryPath(char *fullPath, char *dirPath)
{
    strcpy_s(dirPath, strlen(fullPath) + 1, fullPath);
    char *pch;
    pch = strrchr(dirPath, '/');
    if (pch != NULL)
    {
        dirPath[pch - dirPath + 1] = '\0';
    }
    pch = strrchr(dirPath, '\\');
    if (pch != NULL)
    {
        dirPath[pch - dirPath + 1] = '\0';
    }
    return dirPath;
}


_Bool CreateDirectoryRecursive(char *fullPath)
{
    if (strcmp(fullPath, "") == 0)
    {
        return 0;
    }
    char *dirPath;
    int result = mkdir(fullPath, 0777);
    if (result == EEXIST || result == 0)
    {
        return 1;
    }
    dirPath = malloc(strlen(fullPath) + 1); // +nullbyte
    if (dirPath == NULL)
        return 0;
    strcpy_s(dirPath, strlen(fullPath) + 1, fullPath);
    char *pch;
    pch = strrchr(dirPath, '/');
    if (pch == NULL)
        return 0;
    dirPath[pch - dirPath] = '\0';
    _Bool success = CreateDirectoryRecursive(dirPath);
    free(dirPath);
    if (!success)
    {
        return 0;
    }
    mkdir(fullPath, 0777);
    return 1;
}
