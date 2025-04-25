#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

// Helper function to trim leading and trailing spaces
char *trim_whitespace(char *str) {
    char *end;

    // Trim leading spaces
    while (*str == ' ') str++;

    // Trim trailing spaces
    if (*str == 0) return str; // If string is empty
    end = str + strlen(str) - 1;
    while (end > str && *end == ' ') end--;

    // Null-terminate
    *(end + 1) = '\0';
    return str;
}

char **split_line(char *line) {
    int bufsize = 64;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;
    int position = 0;

    if (!tokens) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Trim input line before processing
    line = trim_whitespace(line);

    // Tokenize input
    token = strtok(line, " \t\n");
    while (token != NULL) {
        tokens[position++] = token;
        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                perror("Error reallocating memory");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, " \t\n");
    }

    tokens[position] = NULL; // Null-terminate the array
    return tokens;
}
