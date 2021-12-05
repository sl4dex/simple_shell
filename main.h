#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
typedef struct nodep
{
	char *path;
	struct nodep *next;
} nodep;
char **tokenizer(char *, char *, char **);
char *strconcat(char *, char *);
char *_getenv(const char *);
int get_path(char **);
nodep *tokenLinked(char string[], char *separator);
size_t prNodes(const nodep *);
int chkBuiltin(char **, char **, char *);
int chkPath(char **);
void execution(char **);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
void exitpls(void);
void freezeBuff(char *);
void freezeLl(nodep *);
#endif
