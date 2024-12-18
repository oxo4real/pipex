/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:32:00 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/18 12:59:42 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	char	**path;

	if (argc != 5)
		handl_err(1, "you must enter 4 arguments\n");
	path = find_path(envp);
	normal_pipe(argc, argv, path, envp);
}
