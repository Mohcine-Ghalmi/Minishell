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

void execution(t_data *new, char **envp)
{
    dup2(new->infile, STDIN_FILENO);
    if (!new->next)
    {
        dup2(new->outfile, STDOUT_FILENO);
        exec(new->av, envp);
        return ;
    }else if (ft_lstsize(new) == 2)
        pipex1(new->av, new->next->av, envp);
    else
    {
        while (new->next)
        {
            pipex(new->av, envp);
            new = new->next;
        }
        exec(new->av, envp);
    }
}

int main(int argc, char **argv, char **envp)
{
    t_data *new;
    char    *stock;
    // int main_fork;
    char **new_envp;

    (void)argc;
    (void)argv;
    // while (1)
    // {
        // stock = readline("$ ");
        new_envp = environment(envp);
        new = struct_args("ls", 0, 1);
        // new->next = struct_args("ls", 0, open("a", O_RDONLY));
        // new->next->next = struct_args("top", 0, 1);
        // if (!ft_strncmp(stock, "exit", 5))
        //     exit(1);
        // main_fork = fork();
        // if (!main_fork)
        // {
            execution(new, new_envp);
            // exit(1);
        // }
        // waitpid(main_fork, NULL, 0);
    // }
    free(new);
    free(new_envp);
    return 0;
}