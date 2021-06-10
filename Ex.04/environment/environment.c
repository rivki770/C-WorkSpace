#include <stdio.h>
typedef unsigned int size_t;

int main(int argc, char *argv[], char **envp)     
{
    printf_s("Environment variables:\n\n");
    size_t count = 1;

    while (*envp != NULL)
    {
        char *str = *envp;
        char *next_str;

        strtok_s(str, "=", &next_str);

        printf("No.%d: Environment variable '%s' has the value '%s'\n", count,  str, next_str);
        ++envp;
        ++count;
    }
    return 0;
}