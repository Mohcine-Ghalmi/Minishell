/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selhilal <selhilal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:31:15 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/17 17:02:29 by selhilal         ###   ########.fr       */
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
		i++;
	}
	return(ptr);
}

int	main(void)
{
	t_lexer	*token;
	char	*text;
	char	*ptr;
	char	**p;

	token = malloc(sizeof(t_lexer));
	text = readline("$ ");
	ft_token(text, token);
	parsing_token(text, token);
	if(qudes(text) == 2)
	{
		printf("Error\n");
		return(0);
	}
	ptr = spaces(text, token);
	p = ft_split(ptr, ' ');
	int i = 0;
	while(p[i])
	{
		printf("%s\n",p[i]);
		i++;
	}
	return (0);
}
