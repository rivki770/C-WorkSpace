#include "StringLib.h"
String *CreateString(const char *source)
{
    if (*source)
    {
        printf("The source is empty\n");
        return NULL;
    }

    size_t sizeSource = strlen(source);

    String stringNew;
    (stringNew).string = (char *) malloc(sizeof(char) * sizeSource + 1);
    (stringNew).string[sizeSource] = '0';
    (stringNew).sizeString = strlen(stringNew.string);

    return &stringNew;

}

BOOL DeleteString(String *str)
{
    if (IsEmpty(str))
    {
        return F;
    }

    for (size_t i = 0; i < str->sizeString; ++i)
    {
        str->string[i] = '0';
    }

    free(str->string);
    return T;
}

size_t GetStringLength(const String *str)
{
    return str->sizeString;
}

BOOL IsEmpty(const String *str)
{
    if (str == NULL)
    {
        return T;
    }
    else
    {
        return F;
    }
}

int CompareString(const String *str1, const String *str2)
{
    if (str1->sizeString != str2->sizeString)
    {
        return F;
    }

    return strcmp(str1->string, str2->string);
}

void CopyString(String *dst, const String *src) {

    size_t sizeSource = src->sizeString;
    dst->sizeString = sizeSource;

    dst->string = (char *) malloc(sizeof(char) * dst->sizeString);

    for (size_t i = 0; i < sizeSource; ++i)
    {
        dst->string[i] = src->string[i];
    }
}

void CopyCString(String *dst, const char *src)
{
    dst = CreateString(src);
}
