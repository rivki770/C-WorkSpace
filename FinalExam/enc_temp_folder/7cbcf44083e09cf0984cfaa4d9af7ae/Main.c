#include <stdio.h>
#include <limits.h>
#include <C:\rivki\studies\YearC\semesterB\C-WorkSpace\FinalExam\StringLib\StringLib.h>
//#include "StringLB.h"

int main(void)
{
    const char *string = "GOOD LUCK in final exam";
    String *stringCopy = NULL;
    stringCopy = CreateString(&string);

    if (stringCopy != NULL)
    {
        printf("String is created\n");
        printf("%s", stringCopy->string);
    }

    if (DeleteString(stringCopy))
    {
        printf("String is deleted\n");
    }

    const String *string1 = NULL;
    string1 = CreateString(string);

    const String *string2 = NULL;
    string2 = CreateString(string);

    if (!CompareString(string1, string2))
    {
        printf("The strings is equls\n");
    }
    else
    {
        printf("The strings is not\n");
    }

    String str;
    CopyString(&str, string1);
    printf("%s", str.string);

    const char stringGB[50] = "GOOD BYE";
    String goodBye;
    CopyCString(&goodBye, stringGB);
    printf("%s", goodBye.string);

    return 0;
}