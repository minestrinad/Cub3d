/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:55:21 by emma              #+#    #+#             */
/*   Updated: 2023/11/25 11:17:30 by ncortigi         ###   ########.fr       */
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

int	ft_close(t_game *game)
{
	ft_freegame(*game);
	mlx_destroy_image((*game).mlx_ptr, (*game).test.img);
	mlx_destroy_display((*game).mlx_ptr);
	free((*game).mlx_ptr);
	exit(0);
	return (0);
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
