/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qudes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:07:10 by selhilal          #+#    #+#             */
/*   Updated: 2023/07/29 22:47:10 by selhilal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	single_qudes(char *text, int *t, int i, t_token **token)
{
	char	*exet;
	int		m;

	m = 0;
	while (text[*t] && text[*t] != '\'')
		*t += 1;
	m = *t;
	ft_back(token, ft_lstnew(6, ft_substr(text, i, m - i)));
}

char	*double_qudes(char *text, int *t, int i, t_token **token, char **evp)
{
	//char	*tex;
	//int		m;
	//char	*table;
	//int		flag;

	//tex = ft_strdup("");
	//table = ft_strdup("");
	//flag = 0;
	//m = 0;
	//while (text[*t] && text[*t] != '\"')
	//{
	//	if (text[*t] == '$')
	//	{
	//		flag = 1;
	//		tex = ft_strjoin(tex , dollar(text, t, token, evp));
	//	}
	//	else
	//		*t += 1; 
	//}
	//if (!flag)
	//	m = *t;
	//printf("m = %d || i = %d\n", m, i);
	//table = ft_substr(text, i, m - i);
	//puts(table);
	//return (ft_strjoin(table, tex));
	char *table;
	char *globel;

	table = NULL;
	globel = NULL;
	while(text[*t] && text[*t] != '\"')
	{
		if(text[*t] == '$')
		{
			char *tmp = ft_substr(text, i, *t - 1);
			printf("tmp = %s\n", tmp);
			table = ft_strjoin(table, tmp);
			globel = dollar(text, t, token, evp);
			i = *t;
			// printf("glebel = %s\n", globel);
			table = ft_strjoin(table, globel);
			printf("table = %s, %s\n", table, globel);
			// printf("table = %s\n", table);
			free(globel);
		}
		else
		{
			*t += 1;
		}
	}
	// *t += 1;
	table = ft_strjoin(table, ft_substr(text, i, *t - 1));
	printf("table = %s\n", table);
	return (table);
}

void	qudes(char *text, int *i, t_token **token, char **envp)
{
	int		q;
	int		t;

	q = text[*i];
	*i += 1;
	t = *i;
	if (q == '\'')
		single_qudes(text, &t, *i, token);
	else if (q == '\"')
		ft_back(token, ft_lstnew(5, double_qudes(text, &t, *i, token, envp)));
	t += 1;
	*i = t;
}
