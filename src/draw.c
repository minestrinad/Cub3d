/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:12 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/15 15:03:52 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_draw_floor_ceiling(t_game *game, t_img *img, int floor_ceiling)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (floor_ceiling == 0)
				my_mlx_pixel_put(game, x, y, 0x66FF33);
			else
				my_mlx_pixel_put(game, x, y, 0xBBFAFF);
			x++;
		}
		y++;
	}
}

void	draw(t_game *game)
{
	ft_draw_floor_ceiling(game, game->img, 0);
	ft_draw_floor_ceiling(game, game->img, 1);
}
