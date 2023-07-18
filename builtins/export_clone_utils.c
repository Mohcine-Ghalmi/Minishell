#include "../Minishell.h"

int    option_replace(char *key, t_env *env)
{
    t_env   *tmp;

    tmp = env;
    while (tmp)
    {
        if (!ft_strncmp(tmp->key, key, ft_strlen1(key)))
        {
            if (key[ft_strlen1(key) - 1] == '=')
            {
                free(tmp->value);
                tmp->value = ft_strdup("-2");
            }
            tmp->option = 1;
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}
