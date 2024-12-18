/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:20:31 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/18 14:26:00 by aaghzal          ###   ########.fr       */
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
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}

int	set_in_out_(int in_out[2], int i, int ac, char **av)
{
	int			pipe_fd[2];
	static int	next_in;

	if (i == -1)
		return (close(next_in), 1);
	if (i == 3)
		next_in = open("/tmp/sldkffalkewhfkasdfawe", O_RDONLY);
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
		in_out[1] = open(av[ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
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
		perror("pipex: malloc");
		exit(1);
	}
	command_path = get_command_path(parsed_command[0], path);
	if (!command_path)
		exit(127);
	free(parsed_command[0]);
	parsed_command[0] = command_path;
	return (parsed_command);
}

void	ft_here_doc(int ac, char **av, char **path, char **envp)
{
	int	in_out[2];
	int	pid;
	int	i;

	i = 3;
	while (i < ac - 1)
	{
		if (!set_in_out_(in_out, i, ac, av))
			perror("pipex: pipe: ");
		pid = fork();
		if (pid == -1)
			return (free_2d_arr(path),
				handl_err(1, "pipex: fork: Resource temporarily unavailable"));
		if (pid == 0)
			execute_(in_out, parsing(av[i], path), envp, path);
		ft_close(in_out[0], in_out[1]);
		i++;
	}
	free_2d_arr(path);
	i = 0;
	waitpid(pid, &i, 0);
	while (i++ < ac - 3)
		wait(NULL);
	unlink("/tmp/sldkffalkewhfkasdfawe");
	exit(WEXITSTATUS(i));
}
