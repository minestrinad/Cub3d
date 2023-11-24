/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:18:54 by everonel          #+#    #+#             */
/*   Updated: 2023/11/24 16:46:28 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	parse_texture_info(t_game game, char *line, t_texture *texture)
{
	char	**str_split;

	str_split = ft_split(line, ' ');
	if (!str_split[1] || str_split[2])
		return (0);
	(*texture).img = mlx_xpm_file_to_image(game.mlx_ptr, \
		str_split[1], \
		&(*texture).width, \
		&(*texture).height);
	ft_free_matrix(str_split);
	if (!(*texture).img)
		return (0);
	(*texture).pixels = mlx_get_data_addr((*texture).img, \
		&(*texture).bits_pixel, \
		&(*texture).line_len, \
		&(*texture).endian);
	return (1);
}

static int	parse_color_info(char *str, int **rgb)
{
	int		i;
	int		k;
	char	*sub_line;

	i = 0;
	k = 0;
	*rgb = (int *)ft_calloc(sizeof(int), 3);
	while (i++ < 3 && *str)
	{
		while (*str && *str == ' ')
			str++;
		while (str[k] && str[k] != ',' && k < 3 && ft_isdigit(str[k]))
			k++;
		sub_line = ft_substr(str, 0, k);
		(*rgb)[i -1] = ft_atoi(sub_line);
		ft_strdel(&sub_line);
		str += k + 1;
		k = 0;
	}
	str -= 1;
	while (*str && *str == ' ')
		str++;
	if (*str)
		return (0);
	return (1);
}

static int	check_ifis_info(t_game *game, char *line, int *check)
{
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
{
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
