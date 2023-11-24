/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:55:21 by emma              #+#    #+#             */
/*   Updated: 2023/11/24 16:58:40 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_freegame(t_game game)
{
	if (game.view.north.img)
		mlx_destroy_image (game.mlx_ptr, game.view.north.img);
	if (game.view.south.img)
		mlx_destroy_image (game.mlx_ptr, game.view.south.img);
	if (game.view.east.img)
		mlx_destroy_image (game.mlx_ptr, game.view.east.img);
	if (game.view.weast.img)
		mlx_destroy_image (game.mlx_ptr, game.view.weast.img);
	if (game.view.cealing)
		free(game.view.cealing);
	if (game.view.floor)
		free(game.view.floor);
	if (game.map)
		ft_free_matrix(game.map);
	if (game.win_ptr)
		mlx_destroy_window(game.mlx_ptr, game.win_ptr);
}

void	ft_error(t_game *game, char *str)
{
	ft_freegame(*game);
	if ((*game).test.img)
		mlx_destroy_image((*game).mlx_ptr, (*game).test.img);
	if ((*game).mlx_ptr)
	{
		mlx_destroy_display((*game).mlx_ptr);
		free((*game).mlx_ptr);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}

void	handle_window(t_game *game)
{
	(*game).win_ptr = mlx_new_window((*game).mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
		"Cub3d");
	image(game);
	mlx_hook((*game).win_ptr, 17, 0L, ft_close, game);
	mlx_hook((*game).win_ptr, 2, 1L << 0, deal_keys, game);
	mlx_hook((*game).win_ptr, 6, 1L << 6, deal_mouse, game);
	mlx_loop((*game).mlx_ptr);
}
