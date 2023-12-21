#include "shell.h"
/**
 * get_location - Searches for the location of a command in
 * the directories specified by the PATH environment variable.
 * @command: The command to search for.
 *
 * Return: the full path of the command if found, or NULL if not
 * located in any specified directory.
 * Uses dynamic memory allocation and checks existence with the stat function.
 */
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path, *delimiters = ":";
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	path_copy = strdup(path);
	command_length = strlen(command);
	path_token = strtok(path_copy, delimiters);
	while (path_token != NULL)
	{
		directory_length = strlen(path_token);
		file_path = malloc(command_length + directory_length + 2);
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);
		strcat(file_path, "\0");
		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			path_token = strtok(NULL, delimiters);
		}
	}
	free(path_copy);
	return (command);
}
