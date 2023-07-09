#include "Minishell.h"

t_data  *pipes_cmnds()
{
    t_data *new;

    new = struct_args("ls", NULL, NULL, NULL);
    // new->next = struct_args("cat", NULL, NULL, NULL);
    // new->next->next = struct_args("ls", NULL, NULL, NULL);
    return new;
}

void    fuck(void)
{
    system("leaks Minishell");
}

void    my_free(char **to_free)
{
    int     i;

    i = 0;
    while(to_free[i])
        free(to_free[i++]);
    free(to_free);
}

int main(int argc, char **argv, char **envp)
{
    t_data *new;
    char **new_envp;
    
    // atexit(fuck);
    (void)argc;
    (void)argv;
    chdir("builtin");
    new_envp = environment(envp);
    new = pipes_cmnds();
    execution(new, new_envp);
    free(new);
    my_free(new_envp);
    return 0;
}
