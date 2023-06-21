#include "Minishell.h"

t_data    *struct_args(char *cmd, int infile, int outfile)
{
    t_data *new;

    new = malloc(sizeof(t_data));
    new->av = cmd;
    new->infile = infile;
    new->outfile = outfile;
    new->next = NULL;
    return new;
}

int	ft_lstsize(t_data *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void    for_all(t_data  *new, int *pipe, int cmd_num, char **envp)
{
    pid_t   pid;
    int     i;

    i = 0;
    pid = fork();
    if (pid < 0)
        exit(0);
    if (pid == 0)
    {
        if (cmd_num == 0)
        {
            dup2(new->infile, 0);
            dup2(pipe[1], 1);
        }
        else if(cmd_num == ft_lstsize(new) - 1)
        {
            dup2(pipe[2 * cmd_num - 2], 0);
            dup2(new->outfile, 1);
        }
        else
        {
            dup2(pipe[2 * cmd_num - 2], 0);
            dup2(pipe[2 * cmd_num + 1], 1);
        }
        while (i < ft_lstsize(new))
            close(pipe[i++]);
        exec(new->av, envp);
    }
}

void execution(t_data *new, char **envp)
{
    int     *cannel;
    int     i;

    i = 0;
    cannel =  (int *)malloc(sizeof(int) * (2 * ft_lstsize(new) - 1));
    while (i < ft_lstsize(new) - 1)
        if  (pipe(cannel + 2 * i++) < 0)
            exit(0);
    i = 0;
    while (new)
    {
        for_all(new, cannel, i++, envp);
        new = new->next;
    }
}

int main(int argc, char **argv, char **envp)
{
    t_data *new;
    // char    *stock;
    // int main_fork;
    char **new_envp;

    (void)argc;
    (void)argv;
    // while (1)
    // {
        // stock = readline("$ ");
        new_envp = environment(envp);
        new = struct_args("ls", 0, 1);
        // new->next = struct_args("sort", 0, 1);
        // new->next->next = struct_args("top", 0, 1);
        // if (!ft_strncmp(stock, "exit", 5))
        //     exit(1);
        // main_fork = fork();
        // if (!main_fork)
        // {
            execution(new, new_envp);
            // exec(new->av, new_envp);
            // exit(1);
        // }
        // waitpid(0, 0, 0);
    // }
    free(new);
    free(new_envp);
    return 0;
}