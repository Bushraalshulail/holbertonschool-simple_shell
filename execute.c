#include "main.h"

/**
 * handle_execution_errors - Handle errors if execve fails.
 * @full_path: The resolved path to the command.
 * @argv: Argument list.
 */
void handle_execution_errors(char *full_path, char **argv)
{
	perror(argv[0]);
	free(full_path);
	free(argv);
	exit(EXIT_FAILURE);
}

/**
 * run_child_process - Fork and execute the command.
 * @full_path: Resolved full path.
 * @argv: Argument list.
 * @env: Environment variables.
 */
void run_child_process(char *full_path, char **argv, char **env)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(full_path, argv, env) == -1)
			handle_execution_errors(full_path, argv);
	}
	else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);
	}
	else
	{
		perror("fork");
	}
	free(full_path);
	free(argv);
}

/**
 * run_command - Resolve the command path and execute it.
 * @cmd: Command entered by user.
 * @env: Environment variables.
 */
void run_command(char *cmd, char **env)
{
	char **argv = split_string(cmd);
	char *full_path;

	if (argv == NULL || argv[0] == NULL)
	{
		free(argv);
		return;
	}

	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		exit(EXIT_SUCCESS);
	}

	full_path = resolve_command_path(argv[0], env);
	if (full_path == NULL)
	{
		perror(argv[0]);
		free(argv);
		return;
	}
	run_child_process(full_path, argv, env);
}
