/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:05:40 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 17:05:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*ft_strcpy_v2(char *dest, char const *src, char c)
{
	int		i;

	i = 0;
	while (src[i] != c && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static int	c_cnt(int pos, char const *str, char c)
{
	int	len;

	len = 0;
	while (str[pos] != c && str[pos])
	{
		len += 1;
		pos++;
	}
	return (len);
}

static void	ft_free_all(char **arr, int count)
{
	count -= 1;
	while (count >= 0)
	{
		free(arr[count]);
		count--;
	}
	free(arr);
}

static char	**fill_arr(char **arr, char const *str, char c)
{
	int	is_word;
	int	count;
	int	i;

	i = -1;
	is_word = 0;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c)
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			arr[count] = (char *)malloc(sizeof(char) * (c_cnt(i, str, c) + 1));
			if (!arr[count])
			{
				ft_free_all(arr, count);
				return (NULL);
			}
			ft_strcpy_v2(arr[count++], &str[i], c);
		}
	}
	arr[count] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		is_word;
	int		count;
	int		i;

	i = 0;
	is_word = 0;
	count = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			count += 1;
		}
		i++;
	}
	arr = (char **)malloc(sizeof(char **) * (count + 1));
	if (!arr || !fill_arr(arr, s, c))
		return (NULL);
	return (arr);
}
