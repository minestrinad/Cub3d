/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:45:16 by emma              #+#    #+#             */
/*   Updated: 2023/11/13 15:34:57 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_read_file(char *map_file)
{
	int		fd;
	char	*line;
	t_list	*map;
	t_list	*tmp;
	char	**map_matrix;

	map = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Error\nFile not found", 2);
	while (get_next_line(fd, &line))
	{
		tmp = ft_lstnew(ft_strdup(line));
		ft_lstadd_back(&map, tmp);
	}
	close(fd);
	map_matrix = ft_lst_to_matrix(map);
	return (map_matrix);
}
