/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:28:01 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/15 13:02:59 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_keys(int key)
{
	if (key == SX || key == DX)
		return (1);
	if (key == W || key == A || key == S || key == D)
		return (1);
	return (0);
}

static void	keys(int key, t_game *game)
{
	if (key == DX)
		printf("Freccia destra\n");
	else if (key == SX)
		printf("Freccia sinistra\n");
	else if (key == W)
		printf("W\n");
	else if (key == A)
		printf("A\n");
	else if (key == S)
		printf("S\n");
	else if (key == D)
		printf("D\n");
}

int	deal_keys(int key, t_game *game)
{
	if (check_keys(key))
	{
		// mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
		keys(key, game);
		// image(data);
	}
	if (key == ESC)
		ft_close(game);
	return (0);
}
