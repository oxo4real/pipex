/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:19:48 by marvin            #+#    #+#             */
/*   Updated: 2024/08/08 22:19:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_cmp1(const char *haystack, const char *needle, int i)
{
	int	k;

	k = 0;
	while (needle[k] != 0)
	{
		if (needle[k] != haystack[i])
			return (0);
		i++;
		k++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	ft_strlen(haystack);
	if (*needle == 0)
		return ((char *) haystack);
	if (len < (size_t)ft_strlen(needle))
		return (NULL);
	i = 0;
	while (haystack[i] && i <= len - ft_strlen(needle))
	{
		if (haystack[i] == needle[0])
		{
			if (ft_cmp1(haystack, needle, i))
			{
				return ((char *) &haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
