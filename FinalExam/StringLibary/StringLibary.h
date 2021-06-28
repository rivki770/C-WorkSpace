#ifndef  _SL
#define _SL

#define FALSE 0
#define TRUE 1

#include "pch.h"
#include "framework.h"
#include <stdio.h>

/**
* @brief The stract describe string (= char*).
*/
typedef struct String_t
{
    char *string;
    //size_t pointerString;
    size_t sizeString;
} String;

typedef enum { F, T } BOOL;

/**
* @brief The function that get char* and create string from it.
* @param source is the input char*.
* @return pointer to the String.
*/
String *CreateString(const char *source);

BOOL DeleteString(String *str);

size_t GetStringLength(const String *str);

BOOL IsEmpty(const String *str);

BOOL CompareString(const String *str1, const String *str2);

void CopyString(String *dst, const String *src);

CopyCString(String *dst, const char *src);

#endif // ! _SL

