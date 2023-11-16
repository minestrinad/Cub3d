/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:45:16 by emma              #+#    #+#             */
/*   Updated: 2023/11/16 00:14:03 by everonel         ###   ########.fr       */
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
	t_list	*map;
	//t_list	*tmp;
	char	**map_matrix;
	int i = 1;	

	map = NULL;
	fd = open(map_file, O_RDONLY);
	map_matrix = calloc(1, sizeof(char *));
	if (fd == -1)
		ft_putstr_fd("Error\nFile not found", 2);
	while (get_next_line(fd, &line))
	{
		map_matrix = realloc(map_matrix, sizeof(char *) * (i + 1));
		map_matrix[i] = ft_strdup(line);
		printf ("%s\n", map_matrix[i]);
		// tmp = ft_lstnew(line);
		// ft_lstadd_back(&map, tmp);
		ft_strdel(&line);
		i++;
	}
	close(fd);
		// ft_lstdelone(tmp, free);
	// ft_lstdel(map, free);
	// map_matrix = ft_lst_to_matrix(map);
	printf ("map_matrix[0]:%s\n", map_matrix[0]);
	return (map_matrix);
}
