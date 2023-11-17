/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:50:46 by emma              #+#    #+#             */
/*   Updated: 2023/11/17 16:35:09 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int     check_map_boundaries(t_game game, char **file_content);
static int     validate_map_characters( t_game *game, char **map);

void    parse_map(t_game *game, char **file_content)
{	printf ("ft_parse_map\n");
	char	**flipped_map;

	validate_map_characters(game, file_content);
	check_map_boundaries(*game, file_content);
	flipped_map = ft_flip_matrix(file_content, ft_matlen(file_content),
		ft_get_matrix_maxlen(file_content));
	check_map_boundaries(*game, flipped_map);
	ft_free_matrix(flipped_map);
	printf ("...\n");
	// game.map.map = file_content;
}

static int save_player(t_game *game, char **map, int i, int j)
{
	if (ft_strchr(PLAYER, map[i][j]))
	{
		printf ("map[i][j]:%c\n", map[i][j]);
		if ((*game).player.start_dir)
			return (1);
		(*game).player.start_dir = map[i][j];
		(*game).player.x = i;
		printf ("(*game).player.x:%f\n", (*game).player.x);
		(*game).player.y = j;
	}
	return (0);
}

static int validate_map_characters( t_game *game, char **map)
{	printf ("ft_check_characters\n");
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (!ft_strchr(PLAYER, map[i][j]) && map[i][j] != '0' &&
				map[i][j] != '1' && map[i][j] != '\n' && map[i][j] != ' ' &&
				map[i][j] != '\0')
				return (1);
			if (save_player(game, map, i, j))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// static char** ft_splut(char *line)
// {
// 	char **split;

// 	split = calloc(1, sizeof(char *));
// 	for (int i = 0; ; ++i)
// 	{
// 		split = realloc(split, sizeof(char *) * (i + 1));
// 		split[i] = strtok_r(line, " ", &line);
// 		if (!split[i])
// 			break;
// 	}
// 	return split;
// }

static int check_map_boundaries(t_game game, char **file_content) 
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
				{
					ft_free_matrix(splitted_line);
					ft_strdel(&trimmed_line);
					return (1);
				}
			j++;
		}
		ft_free_matrix(splitted_line);
		ft_strdel(&trimmed_line);
		j = 0;
		i++;
	}
	return (0);
}

