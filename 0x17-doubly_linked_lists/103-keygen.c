#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * findLargest - finds the biggest number
 *
 * @username: user's username
 * @length: length of the username
 * Return: the biggest number
 */
int findLargest(char *username, int length)
{
    int largestChar;
    int index;
    unsigned int randomNum;

    largestChar = *username;
    index = 0;

    while (index < length)
    {
        if (largestChar < username[index])
            largestChar = username[index];
        index += 1;
    }

    srand(largestChar ^ 14);
    randomNum = rand();

    return (randomNum & 63);
}

/**
 * multiplyChars - multiplies each character of the username
 *
 * @username: user's username
 * @length: length of the username
 * Return: multiplied character
 */
int multiplyChars(char *username, int length)
{
    int result;
    int index;

    result = index = 0;

    while (index < length)
    {
        result = result + username[index] * username[index];
        index += 1;
    }

    return (((unsigned int)result ^ 239) & 63);
}

/**
 * generateRandomChar - generates a random character
 *
 * @username: user's username
 * Return: a random character
 */
int generateRandomChar(char *username)
{
    int randomChar;
    int index;

    randomChar = index = 0;

    while (index < *username)
    {
        randomChar = rand();
        index += 1;
    }

    return (((unsigned int)randomChar ^ 229) & 63);
}

/**
 * main - Entry point
 *
 * @argc: arguments count
 * @argv: arguments vector
 * Return: Always 0
 */
int main(int argc, char **argv)
{
    char key[7];
    int usernameLength, ch, index;
    long alphabet[] = {
        0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
        0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
        0x723161513346655a, 0x6b756f494b646850
    };
    (void) argc;

    for (usernameLength = 0; argv[1][usernameLength]; usernameLength++)
        ;

    /* ----------- Function 1 ----------- */
    key[0] = ((char *)alphabet)[(usernameLength ^ 59) & 63];

    /* ----------- Function 2 ----------- */
    ch = index = 0;
    while (index < usernameLength)
    {
        ch = ch + argv[1][index];
        index = index + 1;
    }
    key[1] = ((char *)alphabet)[(ch ^ 79) & 63];

    /* ----------- Function 3 ----------- */
    ch = 1;
    index = 0;
    while (index < usernameLength)
    {
        ch = argv[1][index] * ch;
        index = index + 1;
    }
    key[2] = ((char *)alphabet)[(ch ^ 85) & 63];

    /* ----------- Function 4 ----------- */
    key[3] = ((char *)alphabet)[findLargest(argv[1], usernameLength)];

    /* ----------- Function 5 ----------- */
    key[4] = ((char *)alphabet)[multiplyChars(argv[1], usernameLength)];

    /* ----------- Function 6 ----------- */
    key[5] = ((char *)alphabet)[generateRandomChar(argv[1])];
    key[6] = '\0';

    /* Print the generated key*/
    for (ch = 0; key[ch]; ch++)
        printf("%c", key[ch]);

    return (0);
}

