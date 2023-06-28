#include "main.h"
/**
 */
char *_strncpy(char *dest, const char *src, int n)
{
    int i;

    /* Copy characters from src to dest */
    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    /* If src has fewer than n characters, pad dest with null bytes */
    for (; i < n; i++)
    {
        dest[i] = '\0';
    }

    return (des)t;
}
