#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * strtow - Splits a string into words.
 * @str: The input string to be split.
 *
 * Return: A pointer to an array of strings (words), or NULL if str is NULL or empty.
 * Each element of the array contains a single word, null-terminated.
 * The last element of the array is NULL.
 * If the function fails, it returns NUL
 */

char **strtow(char *str)
{
    int word_count = 0;
    int in_word = 0;
    int i;

    char **words;
    char *token;

    if (str == NULL || *str == '\0')
        return NULL;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            if (!in_word)
            {
                in_word = 1;
                word_count++;
            }
        }
        else
            in_word = 0;
    }

    words = (char **)malloc((word_count + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    token = strtok(str, " ");
    i = 0;
    while (token != NULL)
    {
        words[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    words[word_count] = NULL;

    return words;
}
