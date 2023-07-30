#include "Minishell.h"
#include <string.h>

char *value(char **envp, char *value)
{
    int i;

    i  = 0;
    while (envp[i])
    {
        if (!strncmp(envp[i], value, strlen(valu)))
            return ()
    }
}

int main(int argc, char **argv, char **envp)
{
    char *tmp = "hey$USER$HOME";
    int i;

    i = 0;
    while (tmp[i])
    {
        if (tmp[i] == '$')
    }
}
