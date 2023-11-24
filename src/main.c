/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:29:33 by everonel          #+#    #+#             */
/*   Updated: 2023/11/24 16:43:51 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_game	ft_parse_input_file(t_game game, char *file)
{
	char	**file_content;
	int		last_readed;

	last_readed = 0;
	file_content = ft_read_file(file);
	if (!file_content)
		ft_error(&game, "invalid file\n");
	if (parse_infos(&game, file_content, &last_readed))
	{
		ft_free_matrix(file_content);
		ft_error(&game, "invalid file header\n");
	}
	if (parse_map(&game, file_content + last_readed))
	{
		ft_free_matrix(file_content);
		ft_error(&game, "invalid map\n");
	}
	ft_free_matrix(file_content);
	return (game);
}

static t_player	player_data(double dir_x, double dir_y, \
	double plane_x, double plane_y)
{
	t_player	player;

	player.dir_x = dir_x;
	player.dir_y = dir_y;
	player.plane_x = plane_x;
	player.plane_y = plane_y;
	return (player);
}

static void	ft_init_player(t_game *game)
{
	double	x;
	double	y;

	x = game->player.x;
	y = game->player.y;
	if (game->player.start_dir == 'N')
		game->player = player_data(-1, 0, 0, 0.66);
	else if (game->player.start_dir == 'W')
		game->player = player_data(0, -1, -0.66, 0);
	else if (game->player.start_dir == 'S')
		game->player = player_data(1, 0, 0, -0.66);
	else if (game->player.start_dir == 'E')
		game->player = player_data(0, 1, 0.66, 0);
	game->player.x = x + 0.01;
	game->player.y = y + 0.01;
}

static void	init_game(t_game *game)
{
	(*game).mlx_ptr = NULL;
	(*game).win_ptr = NULL;
	(*game).mouse_x = 0;
	(*game).mouse_y = 0;
	(*game).mov_speed = 0.1;
	(*game).view.north.img = NULL;
	(*game).view.north.addr = NULL;
	(*game).view.south.img = NULL;
	(*game).view.south.addr = NULL;
	(*game).view.east.img = NULL;
	(*game).view.east.addr = NULL;
	(*game).view.weast.img = NULL;
	(*game).view.weast.addr = NULL;
	(*game).view.cealing = NULL;
	(*game).view.floor = NULL;
	(*game).map = NULL;
	(*game).player.start_dir = 0;
	(*game).player.x = 0;
	(*game).player.y = 0;
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
		ft_error (&game, "Usage: ./cub3d <map_name.cub>\n");
	ft_init_player(&game);
	handle_window(&game);
	ft_freegame(game);
	return (0);
}
