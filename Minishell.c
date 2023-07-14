#include "Minishell.h"

t_data  *pipes_cmnds()
{
    t_data *new;

    new = struct_args("env", NULL, NULL, NULL);
    // new->next = struct_args("sort", NULL, NULL, NULL);
    // new->next->next = struct_args("ls", NULL, NULL, NULL);
    return new;
}

void    fuck(void)
{
    system("leaks Minishell");
}

int main(int argc, char **argv, char **envp)
{
    t_data  *new;
    t_env   *new_envp;
    // char    *input;
    
    atexit(fuck);
    (void)argc;
    (void)argv;
    new_envp = envirment(envp);
    // input = readline("$ ");
    new = struct_args("env", NULL, NULL, NULL);
    new->next = struct_args("pwd", NULL, NULL, NULL);
    new->next->next = struct_args("sort", NULL, NULL, NULL);
    execution(new, new_envp);
    free(new);
    ft_lstclear_env(&new_envp);
    return (0);
}
