/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:02:30 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/14 18:59:04 by aaghzal          ###   ########.fr       */
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
	line = get_next_line(0);
	if (!line)
		return (0);
	while (ft_strlen(line) - 1 != ft_strlen(limiter)
		|| ft_strncmp(line, limiter, ft_strlen(line) - 1) != 0)
	{
		write(read_file, line, ft_strlen(line));
		line = get_next_line(0);
	}
	return (1);
}
