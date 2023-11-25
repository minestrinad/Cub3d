/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:14:23 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/25 11:15:54 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	draw_square_player(t_game *data, int x, int y, int color)
{
	int	i;
	int	k;

	k = 0;
	while (k < 3)
	{
		i = 0;
		while (i < 3)
		{
			my_mlx_pixel_put(data, x + k, y + i, color);
			i++;
		}
		k++;
	}
}

static void	draw_square(t_game *data, int x, int y, int color)
{
	int	i;
	int	k;

	k = 0;
	while (k < 5)
	{
		i = 0;
		while (i < 5)
		{
			my_mlx_pixel_put(data, x + k, y + i, color);
			i++;
		}
		k++;
	}
}

void	draw_minimap(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_square(data, x * 5, y * 5, 0XFFFFFF);
			else if (data->map[y][x] == '0')
				draw_square(data, x * 5, y * 5, 0x000000);
			x++;
		}
		y++;
	}
	draw_square_player(data, data->player.y * 5, data->player.x * 5, 0xb000f5);
}
