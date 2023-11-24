/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:42:20 by everonel          #+#    #+#             */
/*   Updated: 2023/11/24 16:51:26 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_matrix_first_len(char const *str, char c);
static size_t	get_matrix_second_len(char const *str, size_t start, char c);

char	**ft_split(char const *str, char c)
{
	char	**new;
	size_t	start;
	size_t	i;
	size_t	first_len;
	size_t	second_len;

	i = 0;
	start = 0;
	first_len = get_matrix_first_len(str, c);
	new = (char **)malloc(sizeof(char *) * (first_len + 1));
	if (!new)
		return (NULL);
	while (i < first_len)
	{
		while (str[start] == c)
			start++;
		second_len = get_matrix_second_len(str, start, c);
		new[i] = ft_substr(str, start, second_len);
		if (!new[i])
			return (NULL);
		start += second_len;
		i++;
	}
	new[i] = NULL;
	return (new);
}

static size_t	get_matrix_first_len(char const *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	get_matrix_second_len(char const *str, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (str[start] && str[start] != c)
	{
		start++;
		i++;
	}
	return (i);
}
