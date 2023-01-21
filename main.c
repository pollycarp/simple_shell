#include "shell.h"
#include <signal.h>

static volatile int keepRunning = 1;
/**
 * handle_signal - prints new line and prompt when CTRL + C is passed as input
 * @signal: name of signal
 */
void handle_signal(int signal)
{
	char *prompt = {"\n(ash)$ "}; /*print prompt on newline*/
	(void) signal;

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	keepRunning = 0;
	fflush(stdout);
}
/**
 * main - creates a prompt reading input, sparses it, executes and waits
 * for another command unless told to exit
 * @ac: number of arguments
 * @av: array of arguments
 * @env: environment variable
 * Return: 0 (success)
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line = NULL;
	char **args, **path;
	int count = 0, status = 0;
	(void) av;
	signal(SIGINT, handle_signal);
	while (keepRunning)
	{	/*printing prompt*/
		prompt_user();
		/*read input and return string*/
		line = read_input();
		if (line == NULL)
			write(1, "", 0);
		/*separates string to get command and arguments*/
		else
		{
			args = sparse_str(line, env);

			if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))
			{
				count += 1;
				path = search_path(env); /*search for PATH in env var*/
				status = _stat(args, path);
				child_process(av, args, env, status, count);
			}
			else
			{
				free(args);
			}
			free(line);
		}
	}
	return (0);
}
