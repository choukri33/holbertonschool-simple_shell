#include "shell.h"

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path, *delimiters = ":";
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	path_copy = strdup(path);
	command_length = strlen(command);
	path_token = strtok(path_copy, delimiters);
}
