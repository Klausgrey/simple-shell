#ifndef SHELL_H
#define SHELL_H

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

/*PROTOTYPES*/
int execmd(char **argv);
char *get_location(char *cmd);
char **_strtok(char *str, const char *delim);
void _env(void);
void run_non_interactive_mode(const char *filename);
void run_interactive_mode();

/* GLOBAL VAR*/
extern char **environ;


#endif