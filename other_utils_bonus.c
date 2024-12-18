/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:52:12 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/18 13:19:29 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	handl_err(int exit_num, char *err_str)
{
	ft_putstr_fd(err_str, 2);
	exit(exit_num);
}

void	execute(int in_out[2], char **parsed_command, char **envp, char **path)
{
	free_2d_arr(path);
	if (in_out[0] < 0 || in_out[1] < 0)
		return (ft_close(in_out[0], in_out[1]), exit(1));
	dup2(in_out[0], 0);
	dup2(in_out[1], 1);
	close(in_out[0]);
	close(in_out[1]);
	set_in_out(NULL, -1, 0, NULL);
	execve(parsed_command[0], parsed_command, envp);
}
