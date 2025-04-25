#include "shell.h"

char **split_line(char *line)
{
    char **tokens = malloc(2 * sizeof(char *));
    if (!tokens)
        return NULL;
    
    tokens[0] = strtok(line, "\n");
    tokens[1] = NULL;
    return tokens;
}
