/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jointoken.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 21:18:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/23 15:13:57 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2 && s1)
		return (s1);
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
	free(s1);
	return (str);
}

void	jointok(t_jointok	**join, t_token *token)
{
	t_token	*tmp;
	char	*table;
	char 	*backup;

	table = ft_strdup("");
	backup = ft_strdup("");
	tmp = token;
	while (tmp)
	{
		if (tmp->type != 5 && tmp->type != 6 && tmp->type != 1)
		{
			ft_lstadd_back1(join, ft_lstnew1(tmp->cmd, tmp->type));
		}
		else
		{
			table = ft_strjoin(backup, tmp->cmd);
			backup = table;
			if (!tmp->next || (tmp->next && tmp->next->type != 5
					&& tmp->next->type != 6 && tmp->next->type != 1))
			{
				ft_lstadd_back1(join, ft_lstnew1(table, 1));
				table = ft_strdup("");
				backup = ft_strdup("");
			}
		}
		tmp = tmp->next;
	}
}
