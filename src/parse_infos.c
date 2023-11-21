/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:18:54 by everonel          #+#    #+#             */
/*   Updated: 2023/11/21 11:53:04 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int    parse_texture_info(t_game game, char *line, t_texture *texture)
{	printf ("ft_save_texture\n");
	char	**str_split;

	str_split = ft_split(line, ' ');
	if (!str_split[1])
		return (0);
	(*texture).img = mlx_xpm_file_to_image(game.mlx_ptr, 
		str_split[1], 
		&(*texture).width, 
		&(*texture).height);
	ft_free_matrix(str_split);
	if (!(*texture).img)
		return (0);
	(*texture).pixels = mlx_get_data_addr((*texture).img, 
		&(*texture).bits_pixel, 
		&(*texture).line_len, 
		&(*texture).endian);
	return (1);
}

static int parse_color_info (char *str, int **rgb)
{	printf ("ft_save_rgb\n");
	int		i;
	int		j;
	int		k;
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

static int	check_ifis_info(t_game *game, char *line, int *check)
{	printf ("ft_check_ifis_info\n");
	if (ft_strncmp(line, NORTH_PATH, 3) == 0)
		*check += parse_texture_info(*game, line, &(*game).view.north);
	else if (ft_strncmp(line, SOUTH_PATH, 3) == 0)
		*check += parse_texture_info(*game, line, &(*game).view.south);
	else if (ft_strncmp(line, EAST_PATH, 3) == 0)
		*check += parse_texture_info(*game, line, &(*game).view.east);
	else if (ft_strncmp(line, WEST_PATH, 3) == 0)
		*check += parse_texture_info(*game, line, &(*game).view.weast);
	else if (ft_strncmp(line, CEALING, 1) == 0)
		*check += parse_color_info(line + 1, &(*game).view.cealing);
	else if (ft_strncmp(line, FLOOR, 1) == 0)
		*check += parse_color_info(line + 1, &(*game).view.floor);
	return (0);
}

int	parse_infos(t_game *game, char **file_content, int *end)
{   printf ("ft_parse_infos\n");
	int		check;
	char	*trimmed_line;

	check = 0;
	while (file_content[*end] && check < 6)
	{
		trimmed_line = ft_strtrim(file_content[*end], " \n");
		if (check_ifis_info(game, trimmed_line, &check))
			return (1);
		ft_strdel(&trimmed_line);
		*end += 1;
	}
	if (check < 6)
		return (1);
	return (0);
}
