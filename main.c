#include "shell.h"
/**
 *
 */
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **args;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "($) ", 4);
        
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }

        args = split_line(line);
        if (args[0] != NULL)
            execute_command(args);

        free(args);
    }
    free(line);
    return 0;
}
/**
 *
 */
int main(void)
{
    /* Copy /bin/ls to hbtn_ls in the parent’s parent directory */
    copy_file("/bin/ls", "../../hbtn_ls");

    /* Execute ./.././../hbtn_ls with /var as argument */
    execute_command((char *[]){"./.././../hbtn_ls", "/var", NULL});

    return 0;
}
