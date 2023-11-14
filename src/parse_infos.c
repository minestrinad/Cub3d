/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:18:54 by everonel          #+#    #+#             */
/*   Updated: 2023/11/14 21:23:14 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	parse_color_info (t_game game, char *str, char ***rgb);
static int	parse_texture_info(t_game game, char *line, t_texture *texture, void *mlx);

void	parse_infos(t_game *game, char **map, int *end)
{   printf ("ft_parse_infos\n");
	int		check;
	char	*trimmed_line;

	check = 0;
	while (*end < ft_matlen(map) && check < 6)
	{
		trimmed_line = ft_strtrim(map[*end], " ");
		if (ft_strncmp(trimmed_line, NORTH_PATH, 3) == 0){
			check += parse_texture_info(*game, map[*end], &(*game).view.north, (*game).window.mlx);
			printf ("%p\n", (*game).view.north.img);}
		else if (ft_strncmp(trimmed_line, SOUTH_PATH, 3) == 0)
			check += parse_texture_info(*game, map[*end], &(*game).view.south, (*game).window.mlx);
		else if (ft_strncmp(trimmed_line, EAST_PATH, 3) == 0)
			check += parse_texture_info(*game, map[*end], &(*game).view.east, (*game).window.mlx);
		else if (ft_strncmp(trimmed_line, WEST_PATH, 3) == 0)
			check += parse_texture_info(*game, map[*end], &(*game).view.weast, (*game).window.mlx);
		else if (ft_strncmp(trimmed_line, CEALING, 1) == 0){
			check += parse_color_info(*game, map[*end] + 1, &(*game).view.cealing);
			printf ("%s\n", (*game).view.cealing[0]);}
		else if (ft_strncmp(trimmed_line, FLOOR, 1) == 0)
			check += parse_color_info(*game, map[*end] + 1, &(*game).view.floor);
		ft_strdel(&trimmed_line);
		*end += 1;
	}
	if (check < 6)
		ft_error(*game, "Invalid header\n");
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
		ft_error(game, "Invalid header\n");
	trimmed_line = ft_strtrim(str_split[1], " \n");
	(*texture).img = mlx_xpm_file_to_image(mlx, trimmed_line, &(*texture).width, &(*texture).height);
	ft_strdel(&trimmed_line);
	ft_free_matrix(str_split);
	// printf ("questo e' il puntatore:%p, %i, %i\n", (*texture).img, (*texture).height, (*texture).width);
	// texture.addr = mlx_get_data_addr(texture.img, &texture.bpp, &texture.line_len, &texture.endian);
	return (1);
}

static int parse_color_info (t_game game, char *str, char ***rgb)
{	printf ("ft_save_rgb\n");
	int	i = 0;
	int	j = 0;
	int	k = 0;

	i = 0;
	j = 0;
	k = 0;
	*rgb = (char **)ft_calloc(sizeof(char *), 4);
	while ( i < 3 )
	{
		(*rgb)[i] = (char *)ft_calloc(sizeof(char), 4);
		while (str[j] == ' ')
			j++;
		while (str[j] != ',' && k < 3)
		{
			if (!ft_isdigit(str[j]))
				ft_error(game, "Invalid header\n");
			(*rgb)[i][k] = str[j];
			k++;
			j++;
		}
		i++;
		k = 0;
	}
	return (1); //non controlla se la stringa e' pulita dopo i dati ottenuti
}
