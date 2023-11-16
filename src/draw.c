/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:12 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/16 12:41:39 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	ft_draw_floor_ceiling(game, &(*game).test, 0, 0);
	ft_draw_floor_ceiling(game, &(*game).test, 1, WIN_HEIGHT / 2);
}
