/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_clone_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:34:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/08/13 19:07:02 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Minishell.h"

int	fail_cd(t_env *env, char *oldpwd)
{
	char	*cd;

	if (!oldpwd)
		return (0);
	if (find_key("PWD=", env))
		if (!find_and_replace(&env, "OLDPWD=", oldpwd))
			ft_lstadd_back_env(&env,
				ft_lstnew_env(ft_strdup("OLDPWD="), ft_strdup(oldpwd), 1));
	free(oldpwd);
	cd = getcwd(NULL, 0);
	if (!find_and_replace(&env, "PWD=", cd))
		ft_lstadd_back_env(&env,
			ft_lstnew_env(ft_strdup("PWD="), ft_strdup(cd), 1));
	free(cd);
	return (0);
}

void	replace_pwd(t_env **envp)
{
	char	*cd;
	int		rep;
	t_env	*tmp;

	tmp = *envp;
	rep = 0;
	cd = ft_strdup(return_value(*envp, "HOME="));
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "PWD=", ft_strlen(tmp->key)))
		{
			free(tmp->value);
			tmp->value = cd;
			rep = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (!rep)
		ft_lstadd_back_env(envp,
			ft_lstnew_env(ft_strdup("PWD="), cd, 1));
}

void	free_tree(char *s1, char *s2, char **s3)
{
	free(s1);
	free(s2);
	free_double(s3);
}
