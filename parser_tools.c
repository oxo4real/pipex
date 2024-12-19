/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:29:09 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/19 12:33:36 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || 
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

const char	*skip_quoted_string(const char *ptr)
{
	char	quote;

	quote = *ptr++;
	while (*ptr && *ptr != quote)
		ptr++;
	if (*ptr == quote)
		ptr++;
	return (ptr);
}
//void	*free_2d_arr(char **arr)
//{
//	int	i;

//	i = 0;
//	while (arr[i])
//	{
//		free(arr[i]);
//		i++;
//	}
//	free(arr);
//	return (NULL);
//}
