/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:50:46 by emma              #+#    #+#             */
/*   Updated: 2023/12/06 14:31:08 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	**save_map(char **mat, int len)
{
	int		i;
	int		j;
	char	**map;
	char	*trimmed_line;

	i = 0;
	while (!stris_empty(mat[i]))
		i++;
	mat += i;
	i = 0;
	map = (char **)ft_calloc(sizeof(char *), len + 1);
	while (mat[i] && ft_strchr(mat[i], '1'))
	{
		trimmed_line = ft_strtrim(mat[i], "\n");
		map[i] = ft_strdup(trimmed_line);
		j = ft_strlen(map[i]) - 1;
		while (map[i][j] == ' ')
			map[i][j--] = '\0';
		ft_strdel(&trimmed_line);
		i++;
	}
	map[i] = NULL;
	return (map);
}

static int	validate_player(t_game *game, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				if ((*game).player.start_dir)
					return (1);
				(*game).player.x = i;
				(*game).player.y = j;
				(*game).player.start_dir = map[i][j];
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (!(*game).player.start_dir)
		return (1);
	return (0);
}

static int	validate_map_boundaries(char **f_c)
{
	int		i;
	int		j;
	char	*tline;
	char	**sline;

	i = 0;
	j = 0;
	while (i < ft_matlen(f_c) && f_c[i])
	{
		tline = ft_strtrim(f_c[i], " \n");
		sline = ft_split(tline, ' ');
		while (sline[j] && (ft_strchr(f_c[i], '0') || ft_strchr(f_c[i], '1')))
		{
			if (sline[j][0] != '1' || sline[j][ft_strlen(sline[j]) - 1] != '1')
				return (ft_free_matrix(sline), ft_strdel(&tline), 0);
			j++;
		}
		ft_free_matrix(sline);
		ft_strdel(&tline);
		j = 0;
		i++;
	}
	return (1);
}

static int	validate_map_line(char *line)
{
	if (!line || !stris_empty(line))
		return (1);
	while (*line && ft_strchr(" \n012NSEW", *line))
		line++;
	if (*line)
		return (0);
	return (1);
}

int	parse_map(t_game *game, char **file_content)
{
	int		map_end;
	int		map_start;
	char	**flipped_map;

	map_start = 0;
	while (file_content[map_start] && \
		validate_map_line(file_content[map_start]))
		map_start++;
	if (file_content[map_start])
		return (0);
	map_start = 0;
	flipped_map = ft_flip_matrix(file_content, ft_matlen(file_content), \
		ft_get_matrix_maxlen(file_content));
	if (!validate_map_boundaries(file_content) || \
		!validate_map_boundaries(flipped_map))
		return (ft_free_matrix(flipped_map), 0);
	map_end = ft_get_matrix_maxlen(flipped_map);
	ft_free_matrix(flipped_map);
	(*game).map = save_map(file_content, map_end);
	(*game).map_height = ft_matlen((*game).map);
	(*game).map_width = ft_get_matrix_maxlen((*game).map);
	if (validate_player(game, (*game).map))
		return (0);
	(*game).map[(int)(*game).player.x][(int)(*game).player.y] = '0';
	return (1);
}
