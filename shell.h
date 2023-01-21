#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv: an array of strings generated from arg
 * @argc: the argument count
 * @history: the history node
 * @alias: the alias node
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	int argc;
	list_t *history;
	list_t *alias;
} info_t;

void handle_signal(int signal);
int *_error(char *argv, int count, char *args);

int func_exit(char **args);
void print_env(char **env);

char **_which(char *foundpath);
char *_getenv(char *name, char **env);
char *search_func(char **dir, char *cmd);
int child_process(char **av, char **args, char **environ, int st, int countt);
int _access(char *filename);

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strstr(char *str1, char *str2);
char *_strdup(char *);
char *_itoa(int num, int base);

char *read_input(void);
char **sparse_str(char *line, char **env);
int execute(char **args, char **argv, int count, char *line, char **env);
void prompt_user(void);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _count_point(char *buffer);

void *_malloc(unsigned int nmemb, unsigned int size);
char *_memset(char *, char, unsigned int);
char **search_path(char **environ);
int _stat(char **cmd, char **path);
char *str_concat(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);

size_t print_list(const list_t *h);
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info_t *info);
char *_strdups(const char *str);

/* list */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

#endif
