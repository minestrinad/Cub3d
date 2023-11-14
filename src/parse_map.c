/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:50:46 by emma              #+#    #+#             */
/*   Updated: 2023/11/14 21:16:47 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void     check_map_boundaries(t_game game, char **file_content);
static void     validate_map_characters( t_game game, char **map);

void    parse_map(t_game game, char **file_content)
{	printf ("ft_parse_map\n");
	char	**flipped_map;

	validate_map_characters(game, file_content);
	check_map_boundaries(game, file_content);
	flipped_map = ft_flip_matrix(file_content, ft_matlen(file_content),
		ft_get_matrix_maxlen(file_content));
	check_map_boundaries(game, flipped_map);
	ft_free_matrix(flipped_map);
	// game.map.map = file_content;
}

static void validate_map_characters( t_game game, char **map)
{	printf ("ft_check_characters\n");
	int	i;
	int	j;
	int	player;

	i = 0;
	j = 0;
	player = 0;
	while (i < ft_matlen(map))
	{
		while (map[i][j])
		{
			if (!ft_strchr(PLAYER, map[i][j]) && map[i][j] != EMPTY &&
				map[i][j] != WALL && map[i][j] != '\n' && map[i][j] != ' ' &&
				map[i][j] != '\0' || (player > 1))
				ft_error(game, "invalid character\n");
			if (ft_strchr(PLAYER, map[i][j]))
				player++;
			j++;
		}
		j = 0;
		i++;
	}
	if (player == 0)
		ft_error(game, "invalid character\n");
}


static void check_map_boundaries(t_game game, char **file_content) 
{    printf ("ft_check_bounderies\n");
	int		i;
	int		j;
	char	*trimmed_line;
	char	**splitted_line;

	i = 0;
	j = 0;
	splitted_line = NULL;
	while (i < ft_matlen(file_content) && file_content[i]) 
	{
		trimmed_line = ft_strtrim(file_content[i], " \n");
		splitted_line = ft_split(trimmed_line, ' ');
		while (splitted_line[j] && (ft_strchr(file_content[i], '0') ||
			ft_strchr(file_content[i], '1')))
		{
			if (splitted_line[j][0] != '1' ||
				splitted_line[j][ft_strlen(splitted_line[j]) - 1] != '1')
				ft_error(game, "file_content not properly closed\n");
			j++;
		}
		// ft_free_matrix(splitted_line);
		// ft_strdel(&trimmed_line);
		j = 0;
		i++;
	}
}

