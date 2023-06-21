/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/21 18:42:11 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void add_char(char *str, int ch)
{
	int length = strlen(str);
    str[length] = ch;
    str[length + 1] = '\0';
}

char *spaces(char *str,t_lexer *data)
{
	char *ptr;
	int i;
	i = 0;
	ptr = strdup(" ");
	while(str[i])
	{
		if((str[i] == data->pipe || str[i] == data->in || str[i] == data->out) && (i > 0 && str[i - 1] != ' '))
			add_char(ptr, ' ');
		add_char(ptr, str[i]);
		if(str[i] == data->pipe || str[i] == data->in || str[i] == data->out && (str[i + 1] != '\0' && str[i + 1] != ' '))
			add_char(ptr, ' ');			
		// if(str[i] == '\"' || str[i] == '\'' && (i > 0 && str[i - 1] != ' '))
		// 	add_char(ptr, ' ');		
		i++;
	}
	return(ptr);
}

char	*save_qotes(char *text)
{
	int i = 0;
	int j = 0;
	int qotenum = 0;
	char	*new;

	while (text[i])
	{
		j = 0;
		if (text[i] == '"')
		{
			qotenum++;
			if (qotenum < 2)
			{
				j = i + 1;
				while (text[j] != '"')
					j++;
				new = malloc((j - i) + 2);
				j = 0;
				i++;
				while (text[i] != '"')
				{	
					new[j++] = text[i];
					text[i++] = '#';
				}
				new[j] = '\0';
			}
		}
		i++;
	}
	return (new);
}

void	replace(char	*text, char	*toreplace)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (text[i])
	{
		if (text[i] == '#')
		{
			text[i] = toreplace[j];
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_lexer	*token;
	char	*text;
	char	*ptr;
	char 	*save;
	char	**p;

	while (1)
	{
		token = malloc(sizeof(t_lexer));
		text = readline("$ ");
		ft_token(text, token);
		parsing_token(text, token);
		if(qudes(text) == 2)
		{
			printf("Error\n");
			// return(0);
		}
		free(save);
		save = save_qotes(text);
		ptr = spaces(text, token);
		p = ft_split(ptr, ' ');
		int i = 0;
		while(p[i])
		{
			replace(p[i], save);
			printf("%s\n",p[i]);
			i++;
		}
	}
	return (0);
}
