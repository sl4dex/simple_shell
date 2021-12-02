#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *buffer, **list;
	size_t bufsize = 1024;
	ssize_t chars;
	int status;
	pid_t pd;
	//char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	buffer = malloc(bufsize);
	list = malloc(1024 * sizeof(char *));
	if (!buffer)
		return(-1);
	while (1)
	{
		printf("  -> ");
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == 1)
			continue;
		buffer[chars - 1] = 0;
		printf("el input fue: %s\n", buffer);
		list = tokenizer(buffer, " ", list);
		if (list)
		{
			/*checkear si es builtin, o si tiene ruta, o si hay que buscarla*/
			chkBuiltin(list, env);
		
			/*pd = fork();
			if (pd == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
 				perror("Error:");
			}
			else
				wait(&status);*/
		}
	}
	return 0;
}
