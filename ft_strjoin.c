/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 04:44:11 by aaghzal           #+#    #+#             */
/*   Updated: 2024/08/08 15:57:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			size;
	size_t		i;
	size_t		j;
	char		*rendu;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	rendu = (char *) malloc(size);
	if (!rendu)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_strlen(s1))
		rendu[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
	{
		rendu[i] = s2[j++];
		i++;
	}
	rendu[i] = 0;
	return (rendu);
}
