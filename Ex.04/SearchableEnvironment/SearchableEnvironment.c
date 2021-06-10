#include <stdio.h>
typedef unsigned int size_t;

int main(int argc, char *argv[], char **envp)
{
    if (argc <= 1)
    {
        printf_s("Environment variables:\n\n");
        size_t count1 = 1;
        while (*envp != NULL)
        {
            char *str = *envp;
            char *next_str;

            strtok_s(str, "=", &next_str);

            printf("No.%d: Environment variable '%s' has the value '%s'\n", count1, str, next_str);
            ++envp;
            ++count1;
        }
        return 0;
    }

    size_t count2 = 1;
    printf_s("Environment variables that contain '%s' is:\n\n", argv[1]); 
    while (*envp != NULL)
    {
        if (strstr(*envp, argv[1]))
        {
            char *str = *envp;
            char *next_str;

            strtok_s(str, "=", &next_str);

            printf("No.%d: Environment variable '%s' has the value '%s'\n", count2, str, next_str);
            ++count2;
        }
        ++envp;
    }
    printf("\n");
    return 0;
}