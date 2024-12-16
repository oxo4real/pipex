/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:11:47 by aaghzal           #+#    #+#             */
/*   Updated: 2024/12/16 20:11:05 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

const char	*skip_spaces(const char *ptr)
{
	const char	*result;

	result = ptr;
	while (ft_isspace(*result))
		result++;
	return (result);
}

int	count_tokens(const char *input)
{
	int			count;
	const char	*ptr;
	char		quote;

	count = 0;
	ptr = input;
	while (*ptr != '\0')
	{
		ptr = skip_spaces(ptr);
		if (*ptr == '\0')
			break ;
		if (*ptr == '"' || *ptr == '\'')
		{
			quote = *ptr++;
			while (*ptr != '\0' && *ptr != quote && ptr++)
				;
			if (*ptr == quote && ptr++)
				ptr++;
		}
		else
			while (*ptr != '\0' && !ft_isspace(*ptr) && ptr++)
				;
		count++;
	}
	return (count);
}

const char	*extract_quoted_string(const char *ptr, char **token)
{
	char		quote;
	size_t		length;
	const char	*start;

	quote = *ptr++;
	length = 0;
	start = ptr;
	while (*ptr != '\0' && *ptr != quote)
	{
		length++;
		ptr++;
	}
	*token = malloc((length + 1) * sizeof(char));
	if (!*token)
		return (NULL);
	ft_strncpy(*token, start, length);
	(*token)[length] = '\0';
	if (*ptr == quote)
		ptr++;
	return (ptr);
}

const char	*extract_unquoted_string(const char *ptr, char **token)
{
	size_t		length;
	const char	*start;

	length = 0;
	start = ptr;
	while (*ptr != '\0' && !ft_isspace(*ptr))
	{
		length++;
		ptr++;
	}
	*token = malloc((length + 1) * sizeof(char));
	if (!*token)
		return (NULL);
	ft_strncpy(*token, start, length);
	(*token)[length] = '\0';
	return (ptr);
}

char	**split_with_quotes(const char *ptr)
{
	char		**tokens;
	int			index;
	int			count;

	count = count_tokens(ptr);
	tokens = malloc(count * sizeof(char *) + 1);
	if (!tokens)
		return (NULL);
	tokens[count] = NULL;
	index = 0;
	while (*ptr != '\0' && index < count)
	{
		ptr = skip_spaces(ptr);
		if (*ptr == '\0')
			break ;
		if (*ptr == '"' || *ptr == '\'')
			ptr = extract_quoted_string(ptr, &tokens[index]);
		else
			ptr = extract_unquoted_string(ptr, &tokens[index]);
		if (!ptr)
			return (free_2d_arr(tokens));
		index++;
	}
	return (tokens);
}

//void	free_split_result(char **tokens, int count)
//{
//	int	i;

//	i = 0;
//	while (i < count)
//	{
//		free(tokens[i]);
//		i++;
//	}
//	free(tokens);
//}

//#include <printf.h>
//int	main(void)
//{
//	const char	*input;
//	char		**tokens;
//	int			i;
//	int			count;

//	count = 5;
//	input = "Hello \"this is a test\" 'and another' world";
//	tokens = split_with_quotes(input);
//	printf("Tokens:\n");
//	i = 0;
//	while (i < count)
//	{
//		printf("Token %d: '%s'\n", i, tokens[i]);
//		i++;
//	}
//	free_split_result(tokens, count);
//	return (0);
//}
