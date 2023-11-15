/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:29:33 by everonel          #+#    #+#             */
/*   Updated: 2023/11/15 13:07:40 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static t_game ft_parse_input_file(t_game game, char *file)
{
	char	**file_content;
	int		last_readed;

	last_readed = 0;
	file_content = ft_read_file(file);
	parse_infos(&game, file_content, &last_readed);
	parse_map(game, file_content + last_readed);
	while (!ft_strchr(file_content[last_readed], '1'))
		last_readed++;
	game.map.map = file_content + last_readed;
	// ft_free_matrix(file_content);
	return (game);
}

static void	ft_mlx(t_game *game)
{
	game->window.mlx = mlx_init();
	game->window.win = mlx_new_window(game->window.mlx, 800, 500, "Cub3d");
	mlx_hook(game->window.win, 17, 0L, ft_close, game);
	mlx_hook(game->window.win, 2, 1L << 0, deal_keys, game);
	mlx_loop(game->window.mlx);
}

int main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
		game = ft_parse_input_file(game, argv[1]);
	else 
		ft_error (game, "Usage: ./cub3d <map_name.cub>\n");
	printf ("%s\n", game.map.map[0]);
	printf ("%s\n", game.view.cealing[0]);
	printf ("%s\n", game.view.floor[0]);
	printf ("%p\n", game.view.north.img);
	// ft_error(game, "Hello World\n");
	ft_mlx(&game);
	// ft_window_manager(mlx, win);
	// ft_game_loop(mlx, win);
	// printf("Hello World\n");
	return (0);
}