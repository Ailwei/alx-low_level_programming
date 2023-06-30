#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * infinite_add - Adds two numbers.
 * @n1: Pointer to the first number.
 * @n2: Pointer to the second number.
 * @r: Buffer to store the result.
 * @size_r: Size of the result buffer.
 *
 * The function adds the two numbers represented as strings, n1 and n2, and stores the result in the buffer r.
 * It returns a pointer to the result.
 * If the result cannot be stored in r, the function returns 0.
 * The function assumes that n1 and n2 are positive numbers or 0, and that they only contain digits.
 * n1 and n2 will never be empty.
 */
#include <stdio.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r)

int main(void)
{
	char n1[] = "123456789";
	char n2[] = "987654321";
	int size_r = 20;
	char r[size_r];
	char *res;

	res = infinite_add(n1, n2, r, size_r);

	if (res != NULL)
	{
		printf("Result: %s\n", res);
	}
	else
	{
		printf("The result cannot be stored in the buffer.\n");
	}

	return 0;
}

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int max_len = size_r - 1;  /* Leave space for null terminator */
	int carry = 0;
	int i, j, k;

	if (len1 + len2 > max_len)
	{
		return NULL;  /* Result cannot be stored in r*/
	}

	i = len1 - 1;
	j = len2 - 1;
	k = max_len - 1;

	r[max_len] = '\0';  /* Null terminator*/

	while (i >= 0 || j >= 0 || carry != 0)
	{
		int sum = carry;

		if (i >= 0)
		{
			sum += n1[i] - '0';
			i--;
		}

		if (j >= 0)
		{
			sum += n2[j] - '0';
			j--;
		}

		carry = sum / 10;
		r[k] = (sum % 10) + '0';
		k--;
	}

	return &r[k + 1];
}
