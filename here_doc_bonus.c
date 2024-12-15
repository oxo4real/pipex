/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:20:31 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/14 18:58:59 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(int ac, char **av, char **path, char **envp)
{
	int		i;
	int		pid;
	t_list	*lst_hd[2];

	lst_hd[0] = make_list(ac - 5, open("/tmp/sldkffalkewhfkasdfawe", O_RDONLY),
			open(av[ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644));
	if (!lst_hd[0])
		handle_error(53, "an error happened while opening pipes\n");
	lst_hd[1] = lst_hd[0];
	i = 3;
	while (i < ac - 1)
	{
		pid = fork();
		if (pid == 0)
			execute(lst_hd, av[i], path, envp);
		ft_close(lst_hd[1]->read_fd, lst_hd[1]->write_fd);
		lst_hd[1] = lst_hd[1]->next;
		i++;
	}
	i = 0;
	while (i++ < ac - 2)
		wait(NULL);
	lst_clear(lst_hd);
	unlink("/tmp/sldkffalkewhfkasdfawe");
}
