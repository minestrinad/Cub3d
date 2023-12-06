/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:45:16 by emma              #+#    #+#             */
/*   Updated: 2023/12/06 13:03:44 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!(lst) || !(del))
		return ;
	while (lst)
	{
		tmp = lst -> next;
		ft_lstdelone(lst, del);
		lst = tmp;
	}
}

char	**ft_read_file(char *map_file)
{
	int		fd;
	char	*line;
	char	**map_matrix;
	int		i;	

	i = 0;
	fd = open(map_file, O_RDONLY);
	map_matrix = NULL;
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		map_matrix = ft_realloc(map_matrix, sizeof(char *) * (i + 2));
		map_matrix[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	close(fd);
	return (map_matrix);
}
