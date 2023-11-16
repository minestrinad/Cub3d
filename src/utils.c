/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:55:21 by emma              #+#    #+#             */
/*   Updated: 2023/11/16 12:23:22 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_freegame(t_game game)
{
	printf ("ft_freegame\n");

	// if (game.map.map && game.map.map[0])
	// 	ft_free_matrix(game.map.map);
	if (game.view.north.img)
		mlx_destroy_image (game.mlx_ptr, game.view.north.img);
	if (game.view.south.img)
		mlx_destroy_image (game.mlx_ptr, game.view.south.img);
	if (game.view.east.img)
		mlx_destroy_image (game.mlx_ptr, game.view.east.img);
	if (game.view.weast.img)
		mlx_destroy_image (game.mlx_ptr, game.view.weast.img);

	printf ("...\n");
	// printf ("%s\n", game.view.cealing[0]);
	// free(game.view.cealing[0]);
	if (game.view.cealing)
		free(game.view.cealing);
	if (game.view.floor)
		free(game.view.floor);
	// mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	// printf ("...\n");
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
	printf ("...\n");
}

void	ft_error(t_game game, char *str)
{
	ft_freegame(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}
