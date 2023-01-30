#include "shell.h"

/**
 * prompt - prints '$$' and waits for a user input
 */

void prompt_user(void)
{
	char *prompt = "(ash)$ ";
	char *buffer = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
	free(buffer);
}
