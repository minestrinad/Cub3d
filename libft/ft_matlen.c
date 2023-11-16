/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:49:14 by emma              #+#    #+#             */
/*   Updated: 2023/11/13 15:35:07 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matlen(char **mat)
{
	int	i;

	i = 0;
	if (!mat)
		return (0);
	while (mat[i])
	{
		i++;
	}
	return (i);
}