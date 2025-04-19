#include "shell.h"

/**
 * find_path - Finds the full path of a command.
 * @command: The command to find the path for.
 * @env: The environment variables.
 *
 * Return: The full path of the command if found, otherwise NULL.
 */
char *find_path(char *command, char **env)
{
	char *path_str = get_path_from_env(env);
	char *full_path = NULL;

	if (is_direct_path(command))
		return (_strdup(command));

	if (!path_str)
		return (NULL);

	full_path = search_command_in_path(command, path_str);
	free(path_str);
	return (full_path);
}

/**
 * is_direct_path - Checks if the command is a direct path.
 * @command: The command to check.
 *
 * Return: 1 if it's a direct path and exists, otherwise 0.
 */
int is_direct_path(char *command)
{
	struct stat st;

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &st) == 0)
			return (1);
	}
	return (0);
}

/**
 * get_path_from_env - Extracts the PATH variable from the environment.
 * @env: The environment variables.
 *
 * Return: A copy of the PATH string or NULL if not found.
 */
char *get_path_from_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		if (_strncmp(env[i], "PATH=", 5) == 0)
			return (_strdup(env[i] + 5));
	}
	return (NULL);
}

/**
 * search_command_in_path - Searches for the command in the PATH directories.
 * @command: The command to search for.
 * @path_str: The PATH string with directories.
 *
 * Return: Full path if command is found, otherwise NULL.
 */
char *search_command_in_path(char *command, char *path_str)
{
	char *token, *full_path;
	struct stat st;

	token = strtok(path_str, ":");
	while (token)
	{
		full_path = malloc(_strlen(token) + _strlen(command) + 2);
		if (!full_path)
			return (NULL);

		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (stat(full_path, &st) == 0)
			return (full_path);

		free(full_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
