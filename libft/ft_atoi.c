/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:57:29 by everonel          #+#    #+#             */
/*   Updated: 2022/10/16 16:24:13 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long int	res;
	size_t		neg;
	size_t		i;

	res = 0;
	neg = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= '\b' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = 1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	if (neg == 1)
		return (-res);
	return (res);
}

//int main()
//{
//	printf("%i", ft_atoi("\n\n\n  -46\b9 \n5d6"));
//}
