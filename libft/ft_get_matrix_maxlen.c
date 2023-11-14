/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matrix_maxlen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:11:27 by everonel          #+#    #+#             */
/*   Updated: 2023/11/13 15:28:08 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_matrix_maxlen(char **mat)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i++ < ft_matlen(mat))
	{
		if ((int)ft_strlen(mat[i - 1]) > max)
			max = ft_strlen(mat[i - 1]);
	}
	return (max);
}
