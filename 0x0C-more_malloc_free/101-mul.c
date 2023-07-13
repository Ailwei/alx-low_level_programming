#include <stdio.h>
#include <ctype.h>
#include "main.h"
#include <stdlib.h>

/**
 * is_valid_number - Checks if a string consists of only digits
 * @str: The string to check
 *
 * Return: 1 if the string contains only digits, 0 otherwise
 */
int is_valid_number(char *str)
{
    while (*str != '\0')
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }

    return 1;
}

/**
 * multiply - Multiplies two positive numbers
 * @num1: The first number as a string
 * @num2: The second number as a string
 */
void multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j;
    int *result;
    int carry = 0;

    /* Calculate the length of both numbers */
    while (num1[len1] != '\0')
        len1++;

    while (num2[len2] != '\0')
        len2++;

    /* Allocate memory for the result */
    result = calloc(len1 + len2, sizeof(int));
    if (result == NULL)
    {
        printf("Error\n");
        exit(98);
    }

    /* Perform the multiplication */
    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            int product = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
            result[i + j + 1] = product % 10;
            carry = product / 10;
        }
        result[i] = carry;
    }

    /* Print the result */
    if (result[0] != 0)
        printf("%d", result[0]);
    for (i = 1; i < len1 + len2; i++)
        printf("%d", result[i]);
    printf("\n");

    /* Free allocated memory */
    free(result);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings representing the command-line arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        return 98;
    }

    char *num1 = argv[1];
    char *num2 = argv[2];

    if (!is_valid_number(num1) || !is_valid_number(num2))
    {
        printf("Error\n");
        return 98;
    }

    multiply(num1, num2);

    return 0;
}

