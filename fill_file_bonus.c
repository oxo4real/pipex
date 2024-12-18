/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:02:30 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/18 16:06:23 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	fill_file(int read_file, char *limiter)
{
	char	*line;

	if (read_file < 0)
		return (0);
	limiter = ft_strjoin(limiter, "\n");
	if (!limiter)
		return (0);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line || ft_strncmp(line, limiter, ft_strlen(line)) == 0)
			break ;
		write(read_file, line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(limiter);
	return (1);
}
