#include "main.h"

int main(int argc char **argv, **env)
{
	char *buffer;
	size_t bufsize = 1024;
	ssize_t chars;
	int status;
	pid_t pd;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	buffer = malloc(bufsize);
	if (!buffer)
		return(-1);
	while (1)
	{
		printf("  -> ");

		/* getline lee el std input, lo almacena desde &buffer hasta un maximo de tamaño bufsize */
		chars = getline(&buffer, &bufsize, stdin);
		buffer[chars - 1] = 0;
		printf("el input fue: %s\n", buffer);
		pd = fork();
		if (pd == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
 				perror("Error:");
		}
		else
			wait(&status);
	}
	return 0;
}
