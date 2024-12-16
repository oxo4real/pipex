/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:52:32 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/16 19:47:10 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				read_fd;
	int				write_fd;
	struct s_list	*next;
}				t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*custom_strjoin(char *s1, char *s2);
int		find_chr(char *str, char c);
char	*get_next_line(int fd);
t_list	*make_list(int num_of_pipes, int read_file, int write_file);
t_list	*lst_last(t_list *lst);
t_list	*lst_new(int read_fd);
size_t	ft_strlen(const char *s);
void	*lst_clear(t_list **lst);
void	*free_2d_arr(char **arr);
void	handle_error(int exit_num, char *err_str);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new_element);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**find_path(char **envp);
char	*get_command_path(char *command, char **path);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		fill_file(int read_file, char *limiter);
void	ft_here_doc(int ac, char **av, char **path, char **envp);
void	normal_pipe(int ac, char **av, char **path, char **envp);
void	execute(t_list *lst_hd[2], char *command,
			char **path, char **envp);
void	ft_close(int fd1, int fd2);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		ft_isspace(char c);
char	**split_with_quotes(const char *ptr);

#endif
