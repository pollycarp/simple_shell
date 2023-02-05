#include "shell.h"
/**
 * sparse_str - divides a string into array of strings
 * @line: the string to be divided
 * @env: environment variable
 * Return: tokens(array of strings) on succes or EXIT_FAILURE if fails
 */
char **sparse_str(char *line, char **env)
{
	int bufsize = TOK_BUFSIZE, position = 0;/*TOK_BUFSIZE is a macro*/
	char **tokens;
	char *token;

	if (line == NULL)
	{
		return (0);
	}
	tokens = _malloc(sizeof(char *), bufsize);
	if (!tokens)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);/*TOK_DELIM is a  macro*/
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, TOK_DELIM);
	}
	if (tokens[0] == NULL)
		tokens[position] = "\n"; /*if is null that pos is a newline*/
	if ((_strcmp(tokens[0], "exit") == 0) && tokens[1] == NULL)
	{
		free(line); /*free memorry and exit program*/
		free(tokens);
		exit(0);
	}
	if ((_strcmp(tokens[0], "env") == 0) && tokens[1] == NULL)
		print_env(env);     /* find enviroment*/
	return (tokens);
}
