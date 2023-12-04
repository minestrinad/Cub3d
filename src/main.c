/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:29:33 by everonel          #+#    #+#             */
/*   Updated: 2023/12/04 15:45:10 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	validate_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (ft_strncmp(file + len - 4, ".cub", 4))
		return (0);
	return (1);
}

static t_game	ft_parse_input_file(t_game game, char *file)
{
	char	**file_content;
	int		last_readed;

	last_readed = 0;
	file_content = ft_read_file(file);
	if (!file_content)
		ft_error(&game, "Invalid file\n");
	else if (!validate_file_extension(file))
	{
		ft_free_matrix(file_content);
		ft_error(&game, "Invalid file extension\n");
	}
	else if (parse_infos(&game, file_content, &last_readed))
	{
		ft_free_matrix(file_content);
		ft_error(&game, "Invalid file header\n");
	}
	else if (!parse_map(&game, file_content + last_readed))
	{
		ft_free_matrix(file_content);
		ft_error(&game, "Invalid map\n");
	}
	ft_free_matrix(file_content);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	init_game(&game);
	game.mlx_ptr = mlx_init();
	if (argc == 2)
		game = ft_parse_input_file(game, argv[1]);
	else
		ft_error (&game, "Usage: ./cub3d maps/<map_name.cub>\n");
	ft_init_player(&game);
	handle_window(&game);
	ft_freegame(game);
	return (0);
}
