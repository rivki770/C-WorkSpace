#ifndef _STRLIB
#define _STRLIB

#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <string.h>

/**
* @file
* The Final Exam - The StringLibary
*/

/**
* @brief The stract describe string (= char*).
*/
typedef struct String_t
{
    char *string;
    size_t sizeString;
} String;

/**
* @brief Enum of Bool.
*/
typedef enum { F, T } BOOL;

/**
* @brief The function that get char* and create string from it.
* @param source is the input char*.
* @return pointer to the String.
*/
String *CreateString(const char *source);

/**
* @brief The function that get string and delete him.
* @param *str pointer is the string*.
* @return BOOL T or F, if the delete was done.
*/
BOOL DeleteString(String *str);

/**
* @brief The function that get string and his length.
* @param *str pointer is the string*.
* @return the length of the string
*/
size_t GetStringLength(const String *str);

/**
* @brief The function that get string and return if he enpty or not.
* @param *str pointer is the string*.
* @return BOOL false or true
*/
BOOL IsEmpty(const String *str);

/**
* @brief The function that get string and string, compare between them.
* @param *str1 pointer is the string*.
* @param *str2 pointer is the string*.
* @see strcmp(_In_z_ char const* _Str1, _In_z_ char const* _Str2)
* @return int = 0/-1/1
*/
int CompareString(const String *str1, const String *str2);

/**
* @brief The function that get string and string, and copy the string1 to the string2.
* @param src pointer is the input string*.
* @param dst pointer is the output string*.
*/
void CopyString(String *dst, const String *src);

/**
* @brief The function that get char* and string, and copy the char to the string.
* @param src pointer is the input char*.
* @param dst pointer is the output string*.
* @see CreateString(const char *source)
*/
void CopyCString(String *dst, const char *src);

#endif // !_STRLIB