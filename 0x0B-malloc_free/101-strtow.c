#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * is_space - Checks if a character is a whitespace character.
 * @c: The character to check.
 *
 * Return: 1 if @c is a whitespace character, 0 otherwise.
 */
int is_space(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count the words in.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
    int count = 0;
    int is_word = 0;

    while (*str)
    {
        if (is_space(*str))
        {
            is_word = 0;
        }
        else if (!is_word)
        {
            is_word = 1;
            count++;
        }

        str++;
    }

    return count;
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split into words.
 *
 * Return: A pointer to an array of strings (words), or NULL if @str is NULL or empty.
 *         Each element of the array contains a single word, null-terminated.
 *         The last element of the array is set to NULL.
 *         If the function fails, it returns NULL.
 */
char **strtow(char *str)
{
    if (str == NULL || *str == '\0')
    {
        return NULL;
    }

    int num_words = count_words(str);
    if (num_words == 0)
    {
        return NULL;
    }

    char **words = (char **)malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
    {
        return NULL;  /* Failed to allocate memory */
    }

    int word_index = 0;
    int is_word = 0;
    char *word_start = NULL;

    while (*str)
    {
        if (is_space(*str))
        {
            is_word = 0;
        }
        else if (!is_word)
        {
            is_word = 1;
            word_start = str;
        }

        if (!is_word && word_start)
        {
            int word_length = str - word_start;
            words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
            if (words[word_index] == NULL)
            {
                /* Free memory for previously allocated words */
                for (int i = 0; i < word_index; i++)
                {
                    free(words[i]);
                }
                free(words);
                return NULL;  /* Failed to allocate memory */
            }
            strncpy(words[word_index], word_start, word_length);
            words[word_index][word_length] = '\0';
            word_index++;
            word_start = NULL;
        }

        str++;
    }

    words[word_index] = NULL;  /* Mark the end of the array with NULL */

    return words;
}

