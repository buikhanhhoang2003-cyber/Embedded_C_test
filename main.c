#include <stdio.h>

static char *skip_spaces(char *p)
{
    while (*p == ' ') p++;
    return p;
}

static char *read_token(char *p, char **start_out, int *err)
{
    char delim = ' ';

    if (*p == '"') {
        delim = '"';
        p++;
    }

    *start_out = p;

    while (*p != '\0' && *p != delim) p++;

    if (delim == '"' && *p != '"') {
        *err = 1;
        return p;
    }

    if (*p != '\0') {
        *p = '\0';
        p++;
    }
    return p;
}

int parse_args(char *input, char **argv, int max_args)
{
    char *p = input;
    int argc = 0;
    int err = 0;

    while (1) {
        p = skip_spaces(p);
        if (*p == '\0' || argc >= max_args) break;

        p = read_token(p, &argv[argc], &err);
        if (err) return -1;
        argc++;
    }
    return argc;
}
