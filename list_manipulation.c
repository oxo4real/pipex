/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:58:08 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/14 18:59:16 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_list	*lst_new(int read_fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->read_fd = read_fd;
	new->write_fd = -1;
	new->next = NULL;
	return (new);
}

t_list	*lst_last(t_list *lst)
{
	if (lst)
	{
		while (lst -> next)
			lst = lst -> next;
		return (lst);
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **lst, t_list *new_element)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = lst_last((*lst));
			last -> next = new_element;
		}
		else
			(*lst) = new_element;
	}
}

void	*lst_clear(t_list **lst)
{
	t_list	*next;

	if (lst)
	{
		while (*lst)
		{
			next = (*lst)->next;
			free(*lst);
			(*lst) = next; 
		}
		(*lst) = NULL;
	}
	return (NULL);
}
