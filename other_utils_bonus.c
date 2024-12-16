/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:52:12 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/16 19:48:30 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	handle_error(int exit_num, char *err_str)
{
	ft_putstr_fd(err_str, 2);
	exit(exit_num);
}

void	ft_close_fd(t_list *lst)
{
	while (lst)
	{
		ft_close(lst->read_fd, lst->write_fd);
		lst = lst->next;
	}
}

void	execute(t_list *lst_hd[2], char *command,
				char **path, char **envp)
{
	char	**parsed_command;
	char	*command_path;

	if (lst_hd[1]->read_fd < 0 || lst_hd[1]->write_fd < 0)
		return (lst_clear(lst_hd), ft_close_fd(lst_hd[1]),
			handle_error(2, "couldn't find a file\n"));
	parsed_command = split_with_quotes(command);
	if (!parsed_command)
		handle_error(53, "ran out of memory in heap\n");
	command_path = get_command_path(parsed_command[0], path);
	if (!command_path)
	{
		ft_putstr_fd("command not found :", 2);
		ft_putstr_fd(parsed_command[0], 2);
		free_2d_arr(parsed_command);
		handle_error(44, "\n");
	}
	free(parsed_command[0]);
	parsed_command[0] = command_path;
	dup2(lst_hd[1]->read_fd, 0);
	dup2(lst_hd[1]->write_fd, 1);
	ft_close_fd(lst_hd[1]);
	lst_clear(lst_hd);
	execve(command_path, parsed_command, envp);
}

void	normal_pipe(int ac, char **av, char **path, char **envp)
{
	int		i;
	int		pid;
	t_list	*lst_and_head[2];

	lst_and_head[0] = make_list(ac - 4, open(av[1], O_RDONLY),
			open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644));
	if (!lst_and_head[0])
		handle_error(53, "an error happened while opening pipes\n");
	lst_and_head[1] = lst_and_head[0];
	i = 2;
	while (i < ac - 1)
	{
		pid = fork();
		if (pid == 0)
			execute(lst_and_head, av[i], path, envp);
		ft_close(lst_and_head[1]->read_fd, lst_and_head[1]->write_fd);
		lst_and_head[1] = lst_and_head[1]->next;
		i++;
	}
	i = 0;
	while (i++ < ac - 2)
		wait(NULL);
	lst_clear(lst_and_head);
}
