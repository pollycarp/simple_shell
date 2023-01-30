#include "shell.h"
/**
 * print_env - prints the environment string to stdout
 * @env: environmemnt
 * Return: Always 0
 */
void print_env(char **env)
{
	int x = 0;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
