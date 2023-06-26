#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword()
{
	char password[7];
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int i;
	srand(time(NULL));
	for (i = 0; i < 6; i++)
	{
		password[i] = charset[rand() % (sizeof(charset) - 1)];
	}
	password[6] = '\0';
	printf("Random Password: %s\n", password);
}
