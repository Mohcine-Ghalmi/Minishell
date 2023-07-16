#include "Minishell.h"
#include <string.h>

int main(int argc, char **argv, char **envp)
{
    printf("%lu\n",  strlen(envp));
}
