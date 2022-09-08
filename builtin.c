#include "header.h"

/**
 * _myexit - check command line to exit shell
 * @line: command line
 * Return: 0 (Success) 1 (Fail)
 **/
int _myexit(char *line)
{
	char *exit_line = "exit";
	int i = 0;
	int len = _strlen(line);

	if (len == 4)
	{
		while (exit_line[i])
		{
			if (exit_line[i] != line[i])
				return (1);
			i++;
		}
		free(line);
		return (0);
	}
	return (1);
}
/**
 * signal_c - Ignore input signal Ctrl + C
 * @sign: siganal parameter
 **/
void signal_c(int sign)
{
	signal(sign, SIG_IGN);
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
	signal(SIGINT, signal_c);
}
/**
 * _myenv - print the environment variables separated.
 * @line: The command line.
 * @counter: number of entry arguments
 * @argv: entry arguments from main
 * @env: enviroment variables
 * Return: 0 if succes or 1 if fails. 127 if env not found
 **/
int _myenv(char *line, int counter, char **argv, char **env)
{
	char *env_line = "env";
	int i = 0;
	int len = _strlen(line);

	if (len == 3)
	{
		while (env_line[i])
		{
			if (env_line[i] != line[i])
				return (1);
			i++;
		}
		if (env)
		{
			for (i = 0; env[i] != NULL; i++)
				_printf("%s\n", env[i]);
			free(line);
			return (0);
		}
		else
		{
			_printf("%s: %d: env: not found\n", argv[0], counter);
			return (127);
		}
	}
	return (1);
}

/**
 * builtin_helper - Displays information about builtin commands.
 * @args: An array of arguments.
 * @front: A pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int builtin_helper(char **args, char __attribute__((__unused__)) **front)
{
	if (!args[0])
		help_all();
	else if (_strcmp(args[0], "alias") == 0)
		help_alias();
	else if (_strcmp(args[0], "cd") == 0)
		help_cd();
	else if (_strcmp(args[0], "exit") == 0)
		help_exit();
	else if (_strcmp(args[0], "env") == 0)
		help_env();
	else if (_strcmp(args[0], "setenv") == 0)
		help_setenv();
	else if (_strcmp(args[0], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(args[0], "help") == 0)
		help_help();
	else
		write(STDERR_FILENO, name, _strlen(name));

	return (0);
}
