/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:29:33 by everonel          #+#    #+#             */
/*   Updated: 2023/11/16 12:42:22 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_game ft_parse_input_file(t_game game, char *file)
{
	char	**file_content;
	int		last_readed;

	last_readed = 0;
	file_content = ft_read_file(file);
	if (!file_content)
		ft_error(game, "invalid file\n");
	printf ("file_content[0]:%s\n", file_content[0]);
	if (parse_infos(&game, file_content, &last_readed))
	{
		ft_free_matrix(file_content);
		ft_error(game, "invalid file header\n");
	}
	parse_map(game, file_content + last_readed);
	while (!ft_strchr(file_content[last_readed], '1'))
		last_readed++;
	game.map.map = file_content + last_readed;
	ft_free_matrix(file_content);
	return (game);
}

static void	handle_window(t_game *game)
{
	// game->window->mlx = mlx_init();
	(*game).win_ptr = mlx_new_window((*game).mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	image(game);
	mlx_hook((*game).win_ptr, 17, 0L, ft_close, game);
	mlx_hook((*game).win_ptr, 2, 1L << 0, deal_keys, game);
	mlx_loop((*game).mlx_ptr);
}

int main(int argc, char **argv)
{
	t_game	game;

	game.mlx_ptr = NULL;
	game.win_ptr = NULL;
	game.view.north.img = NULL;
	game.view.north.addr = NULL;
	game.view.south.img = NULL;
	game.view.south.addr = NULL;
	game.view.east.img = NULL;
	game.view.east.addr = NULL;
	game.view.weast.img = NULL;
	game.view.weast.addr = NULL;
	game.view.cealing = NULL;
	game.view.floor = NULL;
	game.map.map = NULL;
	
	game.mlx_ptr = mlx_init();
	if (argc == 2)
		game = ft_parse_input_file(game, argv[1]);
	else 
		ft_error (game, "Usage: ./cub3d <map_name.cub>\n");
	// handle_window(&game);
	ft_freegame(game);

	return (0);
}
