/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:48:17 by emma              #+#    #+#             */
/*   Updated: 2023/11/24 16:50:22 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_dellist(t_list **slt)
{
	t_list	*tmp;

	while (*slt)
	{
		tmp = *slt;
		*slt = (*slt)->next;
		ft_lstdelone(tmp, free);
	}
}

char	**ft_lst_to_matrix(t_list *map)
{
	char	**map_matrix;
	char	*tmp;
	int		i;

	i = 0;
	map_matrix = (char **)ft_calloc(sizeof(char *), ft_lstsize(map) + 1);
	while (map)
	{
		tmp = ft_strdup(map->data);
		map_matrix[i] = tmp;
		map = map->next;
		i++;
		ft_strdel (&tmp);
	}
	ft_dellist(&map);
	return (map_matrix);
}
