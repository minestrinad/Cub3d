/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:50:46 by emma              #+#    #+#             */
/*   Updated: 2023/11/24 16:56:12 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	**save_map(char **mat)
{
	int		i;
	int		j;
	char	**map;
	char	*trimmed_line;

	i = 0;
	map = NULL;
	while (*mat && (!ft_strchr(*mat, '1') && !ft_strchr(*mat, '0')))
		mat++;
	while (mat[i] && ft_strchr(mat[i], '1'))
		i++;
	map = (char **)ft_calloc(sizeof(char *), i + 1);
	i = 0;
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

static int	check_map_boundaries(char **f_c)
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
				return (ft_free_matrix(sline), ft_strdel(&tline), 1);
			j++;
		}
		ft_free_matrix(sline);
		ft_strdel(&tline);
		j = 0;
		i++;
	}
	return (0);
}

static int	save_player(t_game *game, char **map, int i, int j)
{
	if (ft_strchr(PLAYER, map[i][j]))
	{
		if ((*game).player.start_dir)
			return (1);
		(*game).player.start_dir = map[i][j];
		(*game).player.x = i;
		(*game).player.y = j;
	}
	return (0);
}

static int	validate_map_characters(t_game *game, char **map)
{
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
	if (!(*game).player.start_dir)
		return (1);
	return (0);
}

int	parse_map(t_game *game, char **file_content)
{
	char	**flipped_map;
	char	**tmp;

	tmp = save_map(file_content);
	if (validate_map_characters(game, tmp) || check_map_boundaries(tmp))
	{
		ft_free_matrix(tmp);
		return (1);
	}
	flipped_map = ft_flip_matrix(tmp, ft_matlen(tmp), \
		ft_get_matrix_maxlen(tmp));
	if (check_map_boundaries(flipped_map))
	{
		ft_free_matrix(tmp);
		ft_free_matrix(flipped_map);
		return (1);
	}
	(*game).map = save_map(file_content);
	(*game).map[(int)(*game).player.x][(int)(*game).player.y] = '0';
	(*game).map_height = ft_matlen((*game).map);
	(*game).map_width = ft_get_matrix_maxlen((*game).map);
	ft_free_matrix(tmp);
	ft_free_matrix(flipped_map);
	return (0);
}
