#include "Minishell.h"

typedef struct data
{
    char *av;
    int infile;
    int outfile;
    struct data *next;
}       t_data;

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

void	wl(int argc, char **env, char **av, int outfile)
{
	int	i;

	i = 3;
	while (i < argc - 2)
		pipex(av[i++], env);
	dup2(outfile, STDOUT_FILENO);
	exec(av[i], env);
	exit(1);
}

void execution(t_data *new, char **envp)
{
    dup2(new->infile, STDIN_FILENO);
    if (!new->next)
    {
        dup2(new->outfile, STDOUT_FILENO);
        exec(new->av, envp);
        return ;
    }
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

    (void)argc;
    (void)argv;
    // stock = readline("$ ");
    new = struct_args(stock, 0, 1);
    // new->next = struct_args("pwd", 0, 1);
    // new->next->next = struct_args("top", 0, 1);
    execution(new, envp);
    free(new);
    return 0;
}