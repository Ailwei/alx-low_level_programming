#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int multiply(const char *num1, const char *num2)
{
    int result = atoi(num1) * atoi(num2);
    return result;
}

void validate_arguments(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        exit(98);
    }

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 0; j < strlen(argv[i]); j++)
        {
            if (!isdigit(argv[i][j]))
            {
                printf("Error\n");
                exit(98);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    validate_arguments(argc, argv);
    int result = multiply(argv[1], argv[2]);
    printf("%d\n", result);
    return 0;
}

