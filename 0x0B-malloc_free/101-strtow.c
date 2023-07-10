#include "main.h"
#include <stdlib.h>
#include <string.h>

int is_space(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

int count_words(char *str)
{
    int count = 0;
    int is_word = 0;
    char ch;

    while ((ch = *str++))
    {
        if (is_space(ch))
        {
            is_word = 0;
        }
        else if (!is_word)
        {
            is_word = 1;
            count++;
        }
    }

    return count;
}

char **strtow(char *str)
{
    int num_words, word_length, word_index, i;
    int is_word = 0;
    char *word_start = NULL;
    char ch;
    char **words;

    if (str == NULL || *str == '\0')
    {
        return NULL;
    }

    num_words = count_words(str);
    if (num_words == 0)
    {
        return NULL;
    }

    words = (char **)malloc((num_words + 1) * sizeof(char *));
    if (words == NULL)
    {
        return NULL;  /* Failed to allocate memory */
    }

    word_index = 0;

    while ((ch = *str++))
    {
        if (is_space(ch))
        {
            is_word = 0;
        }
        else if (!is_word)
        {
            is_word = 1;
            word_start = str - 1;
        }

        if (!is_word && word_start)
        {
            word_length = str - word_start - 1;
            words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
            if (words[word_index] == NULL)
            {
                /* Free memory for previously allocated words */
                for (i = 0; i < word_index; i++)
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
    }

    words[word_index] = NULL;  /* Mark the end of the array with NULL */

    return words;
}

