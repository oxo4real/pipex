/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:10:48 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/14 20:06:17 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	char	**path;

	if (argc < 5)
		handle_error(50, "too few arguments to programme\n");
	path = find_path(envp);
	if (ft_strcmp(argv[1], "here_doc") != 0)
		normal_pipe(argc, argv, path, envp);
	else
	{
		if (argc < 6)
			handle_error(50, "too few arguments to programme\n");
		if (!fill_file(open("/tmp/sldkffalkewhfkasdfawe",
					O_WRONLY | O_TRUNC | O_CREAT, 0600), argv[2]))
		{
			unlink("/tmp/sldkffalkewhfkasdfawe");
			handle_error(10, "here_doc failed\n");
		}
		ft_here_doc(argc, argv, path, envp);
	}
}

/* test make_list and lst_clear */
//#include <stdio.h>
//int	main(int argc, char **argv)
//{
//	t_list	*lst = make_list(1 , 100, 200, argv[2]);
//	t_list	*head = lst;
//	while (1)
//	{
//		printf("read:%d,write:%d", head->read_fd, head->write_fd);
//		if (!head->next)
//			break;
//		printf(" -> ");
//		head = head->next;
//	}
//	printf("\n");
//	lst_clear(&lst);
//}

/* see what's in envp */
//#include <stdio.h>
//int	main(int argc, char **argv, char *envp[])
//{
//	int i = 0;
//	while (envp[i])
//		printf("%s\n", envp[i++]);
//}

/* test find_path and get_command_path and free_path*/
//#include <stdio.h>
//int main(int argc, char **argv, char *envp[])
//{
//	char	**path;
//	int i = 0;

//	(void)argc;
//	(void)argv;
//	path = find_path(envp);
//	while (path[i])
//	{
//		printf("%s\n", path[i]);
//		i++;
//	}
//	printf("%s\n", get_command_path("ls", path));
//}

/* see what's in argv */
//#include <stdio.h>
//int main(int argc, char **argv)
//{
//	int i = 0;
//	while (argv[i])
//		printf("%s\n", argv[i++]);
//}

/* test get_next_line */
//int	main(void)
//{
//	char	*line;

//	line = get_next_line(0);
//	if (!line)
//		return (0);
//	while (ft_strcmp(line, "LIMITER") != 0)
//	{
//		write(1, line, ft_strlen(line));
//		line = get_next_line(0);
//	}
//	return (1);
//}
