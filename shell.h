#ifndef HEADER_H
#define HEADER_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

/** Global Variables **/
extern char **environ;

/* Prototypes*/
char *check_path(char *buff);
char **_divstring(char *string_pathcpy, char *separator);
char *_getenv(const char *name);
char *_strcpy(char *dest, char *src);
char *_strcatfun(char *dest, char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);
void _env(void);

#endif
