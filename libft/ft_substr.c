/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:26:56 by everonel          #+#    #+#             */
/*   Updated: 2022/10/16 16:26:59 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_str)
	{
		return (0);
	}
	while (i < len && start + i <= ft_strlen(s))
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

//int main()
//{
//	printf("%s", ft_substr("lorem ipsum dolor sit amet", 400, 20));
//}
