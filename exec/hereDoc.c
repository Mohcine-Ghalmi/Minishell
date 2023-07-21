#include "../Minishell.h"

void	heredoc_file(char *limiter, int outfile)
{
	char	*str;
	char	*end;

	if (outfile < 0)
		exit(1);
	end = ft_strjoin1(limiter, "\n");
	str = readline(">");
	if (!str)
		exit(1);
	while (limiter && ft_strncmp(limiter, str, ft_strlen1(str)))
	{
		ft_putstr_fd(str, outfile);
		free(str);
		str = readline("\n>");
	}
	free(end);
	close(outfile);
	open("tmp.txt", O_RDONLY);
}

void	heredoc(char *limiter, int infile, int outfile)
{
    int out;
    out = outfile;

    if (outfile <= 2)
        out = open("tmp.txt", O_CREAT | O_RDWR | O_APPEND, 0777);
	heredoc_file(limiter, out);
	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	// unlink("tmp.txt");
}

int main(void)
{
    heredoc("hey", 0, 1);
    puts("done 1");
    heredoc("you", 0, 1);
    puts("done 2");
    heredoc("me", 0, 1);
}
