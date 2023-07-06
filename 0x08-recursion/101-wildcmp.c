#include "main.h"
#include <stdio.h>
int wildcmp(char *s1, char *s2);

/**
 * wildcmp - Compares two strings considering the special character '*'.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise. */
int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
    {
        return 1; /* Base case: both strings are empty, they are considered identical */
    }

    if (*s1 == *s2 || *s2 == '*')
    {
        return wildcmp(s1 + 1, s2 + 1); /* Case 1: current characters match or s2 has a wildcard '*' */
    }

    if (*s2 == '*')
    {
        return wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1); /* Case 2: s2 has a wildcard '*' */
    }

    return 0; /* Characters don't match and s2 doesn't have a wildcard */
}
