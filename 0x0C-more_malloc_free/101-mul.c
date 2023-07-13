#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * validate_input - Validates if the given strings represent valid positive numbers.
 * The strings should only contain digits.
 *
 * @num1: The first number string to validate.
 * @num2: The second number string to validate.
 *
 * Return: true if both strings are valid positive numbers, false otherwise.
 */
bool validate_input(const char *num1, const char *num2)
{
    for (int i = 0; num1[i] != '\0'; i++)
    {
        if (!isdigit(num1[i]))
        {
            return false;
        }
    }

    for (int i = 0; num2[i] != '\0'; i++)
    {
        if (!isdigit(num2[i]))
        {
            return false;
        }
    }

    return true;
}

/**
 * print_error - Prints an error message and exits the program with status code 98.
 */
void print_error(void)
{
    printf("Error\n");
    exit(98);
}

/**
 * main - The entry point of the program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: The exit status of the program.
 */
int main(int argc, char *argv[])
{
    /* Check if the correct number of arguments is provided */
    if (argc != 3)
    {
        print_error();
    }

    /* Get the number strings from the command-line arguments */
    const char *num1 = argv[1];
    const char *num2 = argv[2];

    /* Validate the number strings */
    if (!validate_input(num1, num2))
    {
        print_error();
    }

    /* Create a pipe for communication between parent and child processes */
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        print_error();
    }

    /* Fork a child process */
    pid_t pid = fork();
    if (pid == -1)
    {
        print_error();
    }
    else if (pid == 0)
    {
        /* Child process */

        /* Close the unused read end of the pipe */
        close(pipefd[0]);

        /* Redirect the stdout to the write end of the pipe */
        dup2(pipefd[1], STDOUT_FILENO);

        /* Execute bc command to perform the multiplication */
        execlp("bc", "bc", "-q", "-l", "-e", "scale=10", "-e", "a=10", "-e", num1, "*", num2, NULL);

        /* If execlp fails, print an error and exit */
        print_error();
    }
    else
    {
        /* Parent process */

        /* Close the unused write end of the pipe */
        close(pipefd[1]);

        char result[100];

        /* Read the result from the read end of the pipe */
        ssize_t bytesRead = read(pipefd[0], result, sizeof(result) - 1);

        /* Close the read end of the pipe */
        close(pipefd[0]);

        if (bytesRead > 0)
        {
            /* Null-terminate the result string */
            result[bytesRead] = '\0';

            /* Print the result */
            printf("%s", result);
        }
        else
        {
            /* If no data is read, print an error */
            print_error();
        }

        /* Wait for the child process to complete */
        int status;
        waitpid(pid, &status, 0);

        /* Check if the child process exited successfully */
        if (WEXITSTATUS(status) != 0)
        {
            print_error();
        }
    }

    return 0;
}

