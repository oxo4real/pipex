/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:52:32 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/18 17:12:37 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*custom_strjoin(char *s1, char *s2);
int			find_chr(char *str, char c);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
void		*free_2d_arr(char **arr);
void		handl_err(int exit_num, char *err_str);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putchar_fd(char c, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**find_path(char **envp);
char		*get_command_path(char *command, char **path);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			fill_file(int read_file, char *limiter);
void		ft_here_doc(int ac, char **av, char **path, char **envp);
void		normal_pipe(int ac, char **av, char **path, char **envp);
void		execute(int in_out[2], char **parsed_command,
				char **envp, char **path);
void		ft_close(int fd1, int fd2);
char		*ft_strncpy(char *dest, const char *src, size_t n);
int			ft_isspace(char c);
char		**split_with_quotes(const char *ptr);
const char	*skip_quoted_string(const char *ptr);
int			set_in_out(int in_out[2], int i, int ac, char **av);
int			set_in_out_(int in_out[2], int i, int ac, char **av);
void		execute_(int in_out[2], char **parsed_command,
				char **envp, char **path);

#endif
