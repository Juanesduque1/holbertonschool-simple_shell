#ifndef HEADER_H
#define HEADER_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

/* Prototypes*/
char **_divstring(char *string_pathcpy, char *separator);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_getenv(const char *name);
char *_strcatfun(char *dest, char *str);
char *check_path(char *buff);

#endif
