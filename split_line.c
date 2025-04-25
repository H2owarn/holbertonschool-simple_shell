#include "shell.h"

char **split_line(char *line)
{
    char **tokens = malloc(64 * sizeof(char *));
    char *token;
    int position = 0;

    if (!tokens)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\n");
    while (token != NULL)
    {
        tokens[position++] = token;
        token = strtok(NULL, " \t\n");
    }
    tokens[position] = NULL;
    return tokens;
}
