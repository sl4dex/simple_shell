#include <unistd.h>
#include <stdio.h>
extern char **environ;

int main(int argc, char **argv, char **env)
{
	int i = 0;
	while (environ[i])
		printf("%s\n", environ[i++]); // prints in form of "variable=value"
	printf("-----------------------------------\n");
	i = 0;
	while (env[i])
		printf("%s\n", env[i++]);
	return (0);
}
