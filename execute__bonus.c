/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute__bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:46:27 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/18 13:01:49 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_(int in_out[2], char **parsed_command, char **envp, char **path)
{
	free_2d_arr(path);
	if (in_out[0] < 0 || in_out[1] < 0)
		return (ft_close(in_out[0], in_out[1]), exit(1));
	dup2(in_out[0], 0);
	dup2(in_out[1], 1);
	close(in_out[0]);
	close(in_out[1]);
	set_in_out_(NULL, -1, 0, NULL);
	execve(parsed_command[0], parsed_command, envp);
}
