/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:29:33 by everonel          #+#    #+#             */
/*   Updated: 2023/11/14 12:32:45 by everonel         ###   ########.fr       */
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
	printf ("%s\n", game.view.cealing[0]);
	parse_map(game, file_content + last_readed);
	game.map.map = file_content + last_readed;
	// ft_free_matrix(file_content);
	return (game);
}

int main(int argc, char **argv)
{
	t_game	game;

	game.window.mlx = mlx_init();
	if (argc == 2)
		game = ft_parse_input_file(game, argv[1]);
	else 
		ft_error (game, "Usage: ./cub3d <map_name.cub>\n");
	// ft_freegame(game);
	game.window.win = mlx_new_window(game.window.mlx, 800, 500, "Cub3d");
	mlx_loop(game.window.mlx);
	// ft_window_manager(mlx, win);
	// ft_game_loop(mlx, win);
	(void) game.window.win;
	printf("Hello World\n");
	return (0);
}