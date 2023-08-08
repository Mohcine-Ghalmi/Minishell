/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:45:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/08/08 06:31:05 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	option_echo(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-')
		i++;
	if (i == ft_strlen1(str))
		return (0);
	while (str[i] && i > 0)
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	if (i < ft_strlen1(str))
		return (0);
	return (1);
}

int	double_size(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*r_value(t_env *env, char *key)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen1(tmp->key)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int	echo_clone(char **cmd, t_env *env)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!cmd[i])
		return (printf("\n"), 0);
	while (cmd[i] && option_echo(cmd[i]))
	{
		i++;
		flag = 1;
	}
	while (cmd[i])
	{
		if (!ft_strncmp(cmd[i], "~", 2))
			printf("%s", r_value(env, "HOME="));
		else
			printf("%s", cmd[i]);
		if (i < double_size(cmd) - 1)
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
	return (0);
}
