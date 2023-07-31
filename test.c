#include "Minishell.h"
#include <string.h>

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
		str = readline(">");
	}
	free(end);
	close(outfile);
	open("tmp.txt", O_RDONLY);
}

int heredoc(char *limiter, char *outfile)
{
    int out;
    out = "tmp.txt";
    if (outfile)
        out = outfile;
    if (outfile <= 2)
        out = open(out, O_CREAT | O_RDWR | O_APPEND, 0777);
	heredoc_file(limiter, out);
	dup2(out, STDOUT_FILENO);
    return (out);
}


int main(void)
{
    heredoc("EOF", "")
}
