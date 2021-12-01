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
char **tokenizer(char *, char *);
char *strconcat(char *, char *);
nodep *_getenv(const char *name);
int get_path(char *);
nodep *tokenLinked(char string[], char *separator);
size_t prNodes(const nodep *h);
#endif
