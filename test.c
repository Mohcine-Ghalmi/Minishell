#include "Minishell.h"

void    f()
{
    system("leaks a.out");
}

int main(void)
{
    char    *ret;

    atexit(f);
    ret = getcwd(NULL, 0);
    printf("%s\n",  ret);
    free(ret);
}
