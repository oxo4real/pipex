/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_pipe_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:51:00 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/19 08:06:05 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	no_such_file_or_directory(char *file)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

static void	permission_denied(char *file)
{
	ft_putstr_fd("pipex: ", 2);
	perror(file);
}

int	set_in_out(int in_out[2], int i, int ac, char **av)
{
	int			pipe_fd[2];
	static int	next_in;

	if (i == -1)
		return (close(next_in), 1);
	if (i == 2)
		next_in = open(av[1], O_RDONLY);
	if (next_in < 0)
		no_such_file_or_directory(av[1]);
	in_out[0] = next_in;
	if (i != ac - 2)
	{
		if (pipe(pipe_fd) == -1)
			return (0);
		in_out[1] = pipe_fd[1];
		next_in = pipe_fd[0];
	}
	else
	{
		in_out[1] = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (in_out[1] < 0)
			permission_denied(av[ac - 1]);
	}
	return (1);
}

static char	**parsing(char *command, char **path)
{
	char	**parsed_command;
	char	*command_path;

	parsed_command = split_with_quotes(command);
	if (!parsed_command)
	{
		free_2d_arr(path);
		perror("pipex: malloc");
		exit(1);
	}
	command_path = get_command_path(parsed_command[0], path);
	if (!command_path)
	{
		free_2d_arr(path);
		exit(127);
	}
	free(parsed_command[0]);
	parsed_command[0] = command_path;
	return (parsed_command);
}

void	normal_pipe(int ac, char **av, char **path, char **envp)
{
	int	in_out[2];
	int	pid;
	int	i;

	i = 2;
	while (i < ac - 1)
	{
		if (!set_in_out(in_out, i, ac, av))
			perror("pipex: pipe");
		pid = fork();
		if (pid == -1)
			return (free_2d_arr(path),
				handl_err(1, "pipex: fork: Resource temporarily unavailable\n"));
		if (pid == 0)
			execute(in_out, parsing(av[i], path), envp, path);
		ft_close(in_out[0], in_out[1]);
		i++;
	}
	ft_close(in_out[0], in_out[1]);
	free_2d_arr(path);
	i = 0;
	waitpid(pid, &in_out[0], 0);
	while (i++ < ac - 3)
		wait(NULL);
	exit(WEXITSTATUS(in_out[0]));
}
