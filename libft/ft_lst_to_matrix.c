/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:48:17 by emma              #+#    #+#             */
/*   Updated: 2023/11/13 15:35:33 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_matrix(t_list *map)
{
	char	**map_matrix;
	int		i;

	i = 0;
	map_matrix = (char **)ft_calloc(sizeof(char *), ft_lstsize(map) +1);
	while (map)
	{
		map_matrix[i] = ft_strdup(map->data);
		map = map->next;
		i++;
	}
	return (map_matrix);
}
