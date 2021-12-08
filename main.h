#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * struct nodep - linked list of nodes
 * @path: string content of node
 * @next: pointer to next node
 *
 * Description: linked list of nodes used to get all PATH env variable routes
 */
typedef struct nodep
{
	char *path;
	struct nodep *next;
} nodep;
char **tokenizer(char *, char *, char **);
char *strconcat(char *, char *);
char *_getenv(char *, char **);
void get_path(char **, char **, char **);
nodep *tokenLinked(char string[], char *separator);
int chkBuiltin(char **, char **, char *);
int chkPath(char **, char **);
void execution(char **, char **);
int _strlen(char *);
char *_strdup(char *);
int _strcmp(char *, char *);
int _strncmp(char *, char *, unsigned int);
void exitpls(void);
void freezeLl(nodep *);
#endif
