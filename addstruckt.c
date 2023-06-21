/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addstruckt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:21:16 by selhilal          #+#    #+#             */
/*   Updated: 2023/06/21 18:41:39 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

t_data	*ft_lstnew(char *arv,int infile, int outfile)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->av = arv;
	data->infile = infile;
	data->outfile = outfile;
	data ->next = NULL;
	return (data);
}


void	ft_lstadd_front(t_data	**lst, t_data	*new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new -> next = *lst;
	*lst = new;
}

