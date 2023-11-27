/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:45:16 by emma              #+#    #+#             */
/*   Updated: 2023/11/27 14:45:58 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

	i = 1;
	fd = open(map_file, O_RDONLY);
	map_matrix = ft_calloc(1, sizeof(char *));
	if (fd == -1)
		ft_putstr_fd("Error\nFile not found", 2);
	while (get_next_line(fd, &line))
	{
		map_matrix = ft_realloc(map_matrix, sizeof(char *) * (i + 1));
		map_matrix[i - 1] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	map_matrix[i - 1] = NULL;
	close(fd);
	return (map_matrix);
}
