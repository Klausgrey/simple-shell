#include "main.h"

/**
 * 
 *
*/

void run_non_interactive_mode(const char *filename) 
{
    size_t n = 0;
    char *lineptr = NULL;
    ssize_t linecount;
    const char *delim = " \n";
    char **cmd_arguments;
    FILE *file;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    while ((linecount = getline(&lineptr, &n, file)) != -1) {
        if (strcmp("env\n", lineptr) == 0) {
            _env();
            continue;
        }
        cmd_arguments = _strtok(lineptr, delim);
        execmd(cmd_arguments);
    }

    free(lineptr);
    fclose(file);
}
