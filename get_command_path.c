/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:23:35 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/17 18:19:27 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	*free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	*get_command_path(char *command, char **path)
{
	int		i;
	char	*path_slash;
	char	*command_path;

	if (access(command, X_OK) == 0)
		return (command);
	i = 0;
	while (path[i])
	{
		path_slash = ft_strjoin(path[i++], "/");
		if (!path_slash)
			return (perror("pipex: malloc: "), (NULL));
		command_path = ft_strjoin(path_slash, command);
		if (!command_path)
		{
			free(path_slash);
			return (perror("pipex: malloc: "), (NULL));
		}
		if (access(command_path, X_OK) == 0)
			return (command_path);
	}
	return (ft_putstr_fd("pipex: command not found: ", 2),
		ft_putstr_fd(command, 2), ft_putstr_fd("\n", 2), (NULL));
}
