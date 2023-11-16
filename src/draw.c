/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:12 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/16 13:51:55 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	ft_rgb(int *color, int t)
{
	return (t << 24 | color[0] << 16 | color[1] << 8 | color[2]);
}

static void	ft_draw_floor_ceiling(t_game *game, t_texture *img, int floor_ceiling, int y)
{
	int	x;
	int k;

	if (floor_ceiling == 0)
		k = WIN_HEIGHT / 2;
	else
		k = WIN_HEIGHT;
	while (y < k)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (floor_ceiling == 0)
				my_mlx_pixel_put(game, x, y, ft_rgb(game->view.floor, 0));
			else
				my_mlx_pixel_put(game, x, y, ft_rgb(game->view.cealing, 0));
			x++;
		}
		y++;
	}
}

void	draw(t_game *game)
{
	t_ray	*ray;
	int		x;

	ft_draw_floor_ceiling(game, &(*game).test, 0, 0);
	ft_draw_floor_ceiling(game, &(*game).test, 1, WIN_HEIGHT / 2);
	x = 0;
	while (x < WIN_WIDTH)
	{
		x++;
	}
}
