#include "Minishell.h"

int main(int argc, char **argv, char **envp)
{
    t_data *new;
    char **new_envp;

    (void)argc;
    (void)argv;
    new_envp = environment(envp);
    new = struct_args("ls", NULL, NULL, "a");
    // new->next = struct_args("sort", NULL, NULL, NULL);
    // new->next->next = struct_args("cat", NULL, NULL, NULL);
    execution(new, new_envp);
    free(new);
    free(new_envp);
    return 0;
}