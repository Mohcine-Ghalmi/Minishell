/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:48:53 by mghalmi           #+#    #+#             */
/*   Updated: 2023/07/10 09:22:54 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

char **environment(char **envp)
{
	int size;
	char **new_envp;

	size = 0;
	while (envp[size])
		size++;
	new_envp = ft_calloc(sizeof(char *), size + 1);
	if (!new_envp)
		return (NULL);
	size = 0;
	while (envp[size])
	{
		new_envp[size] = ft_strdup(envp[size]);
		size++;
	}
	return new_envp;
}

void	show_env(char **new_env)
{
	int	i;

	i = 0;
	while (new_env[i])
		printf("%s\n", new_env[i++]);
}

// char	**update_env(char **env)
// {
	
// }