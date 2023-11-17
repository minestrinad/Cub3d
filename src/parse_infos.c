/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:18:54 by everonel          #+#    #+#             */
/*   Updated: 2023/11/17 16:27:13 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	parse_color_info (t_game game, char *str, int **rgb);
static int	parse_texture_info(t_game game, char *line, t_texture *texture, void *mlx);

int	parse_infos(t_game *game, char **map, int *end)
{   printf ("ft_parse_infos\n");
	int		check;
	char	*trimmed_line;

	check = 0;
	while (map[*end] && check < 6)
	{
		trimmed_line = ft_strtrim(map[*end], " ");
		if (ft_strncmp(trimmed_line, NORTH_PATH, 3) == 0)
			check += parse_texture_info(*game, map[*end], &(*game).view.north, (*game).mlx_ptr);
		else if (ft_strncmp(trimmed_line, SOUTH_PATH, 3) == 0)
			check += parse_texture_info(*game, map[*end], &(*game).view.south, (*game).mlx_ptr);
		else if (ft_strncmp(trimmed_line, EAST_PATH, 3) == 0)
			check += parse_texture_info(*game, map[*end], &(*game).view.east, (*game).mlx_ptr);
		else if (ft_strncmp(trimmed_line, WEST_PATH, 3) == 0)
			check += parse_texture_info(*game, map[*end], &(*game).view.weast, (*game).mlx_ptr);
		else if (ft_strncmp(trimmed_line, CEALING, 1) == 0)
			check += parse_color_info(*game, map[*end] + 1, &(*game).view.cealing);
		else if (ft_strncmp(trimmed_line, FLOOR, 1) == 0)
			check += parse_color_info(*game, map[*end] + 1, &(*game).view.floor);
		ft_strdel(&trimmed_line);
		*end += 1;
	}
	if (check < 6)
		return (1);
	return (0);
}

static int    parse_texture_info(t_game game, char *line, t_texture *texture, void *mlx)
{	printf ("ft_save_texture\n");
	char	**str_split;
	int		i;
	char	*trimmed_line;

	i = 0;
	str_split = ft_split(line, ' ');
	while (str_split[i])
		i++;
	if (i != 2)
		return (0);
	trimmed_line = ft_strtrim(str_split[1], " \n");
	(*texture).img = mlx_xpm_file_to_image(mlx, trimmed_line, &(*texture).width, &(*texture).height);
	ft_strdel(&trimmed_line);
	ft_free_matrix(str_split);
	(*texture).pixels = mlx_get_data_addr((*texture).img, &(*texture).bits_pixel, &(*texture).line_len, &(*texture).endian);
	return (1);
}

static int parse_color_info (t_game game, char *str, int **rgb)
{	printf ("ft_save_rgb\n");
	int	i = 0;
	int	j = 0;
	int	k = 0;
	char	*sub_line;

	i = 0;
	j = 0;
	k = 0;
	*rgb = (int *)ft_calloc(sizeof(int), 3);
	while ( i < 3 )
	{
		while (str[j] && str[j] == ' ')
			j++;
		while (str[j + k] && str[j + k] != ',' && k < 3)
		{
			if (!ft_isdigit(str[j]))
				return (0);
			k++;
		}
		sub_line = ft_substr(str, j, j + k);
		(*rgb)[i] = ft_atoi(sub_line);
		ft_strdel(&sub_line);
		i++;
		j += (k + 1);
		k = 0;
	}
	return (1); //non controlla se la stringa e' pulita dopo i dati ottenuti
}
