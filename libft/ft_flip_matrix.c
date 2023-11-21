/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flip_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 04:13:50 by emma              #+#    #+#             */
/*   Updated: 2023/11/21 12:56:45 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_flip_matrix(char **mat, int height, int width)
{
	char	**new;
	int		i;
	int		j;

	new = ft_calloc(sizeof(char *), width + 1);
	i = 0;
	j = 0;
	while (i < width)
	{
		new[i] = ft_calloc(sizeof(char), height + 1);
		while (j < height)
		{
			if ((int)ft_strlen(mat[j]) > i && mat[j][i] != '\0' &&
				mat[j][i] != '\n')
				new[i][j] = mat[j][i];
			else if (j < height)
				new[i][j] = ' ';
			j++;
		}
		j = 0;
		i++;
	}
	new[i] = NULL;
	return (new);
}
