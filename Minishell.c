#include "Minishell.h"

t_data  *pipes_cmnds()
{
    t_data *new;

    new = struct_args("env", NULL, NULL, NULL);
    // new->next = struct_args("cat", NULL, NULL, NULL);
    // new->next->next = struct_args("ls", NULL, NULL, NULL);
    return new;
}

int main(int argc, char **argv, char **envp)
{
    t_data *new;
    char **new_envp;

    (void)argc;
    (void)argv;
    new_envp = environment(envp);
    new = pipes_cmnds();
    execution(new, new_envp);
    free(new);
    free(new_envp);
    return 0;
}
