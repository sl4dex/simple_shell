#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *buffer, **list;
	size_t bufsize = 1024;
	ssize_t chars;
	int status, success;
	pid_t pd;
	//char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	buffer = malloc(bufsize);
	list = malloc(1024 * sizeof(char *));
	if (!buffer)
		return(-1);
	while (1)
	{
		success = 0;
		printf("  -> ");
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == 1)
			continue;
		buffer[chars - 1] = 0;
		printf("el input fue: %s\n", buffer);
		list = tokenizer(buffer, " ", list);
		/*checkear si es builtin, o si tiene ruta, o si hay que buscarla*/
		success = chkBuiltin(list, env, buffer);
		if (success == 1)
			continue;
		printf("no es builtin.\n");
		success = chkPath(list);
		if (success == 1)
			continue;
		printf("no hay path predefinido.\n");
		get_path(list[0]);
	}
	freezeBuff(list);
	printf("chau c:\n");
	return 0;
}
