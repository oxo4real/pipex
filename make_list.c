/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:58:08 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/14 18:59:15 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_list	*make_list(int num_of_pipes, int rf, int wf)
{
	int		i;
	int		pipe_fd[2];
	t_list	*lst;
	t_list	*new;

	if (rf < 0 || wf < 0)
		ft_putstr_fd("couldn't open a file", 2);
	lst = lst_new(rf);
	i = 0;
	while (i++ < num_of_pipes)
	{
		if (pipe(pipe_fd) == -1)
			return (lst_clear(&lst));
		lst_last(lst)->write_fd = pipe_fd[1];
		new = lst_new(pipe_fd[0]);
		if (!new)
			return (lst_clear(&lst));
		ft_lstadd_back(&lst, new);
	}
	lst_last(lst)->write_fd = wf;
	return (lst);
}
