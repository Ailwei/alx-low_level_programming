/**
 * _strlen_recursion - Returns the length of a string.
 * @s: The string to calculate the length of.
 *
 * Description: This function recursively counts the number
 *              of characters in the string 's' until it
 *              reaches the null terminator.
 *
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
	/* Base case: null terminator */

	if (*s == '\0')
		return (0);

	/* Recursive call with the next character */

	return (1 + _strlen_recursion(s + 1));
}
