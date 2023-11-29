/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:14:23 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/29 16:06:45 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	draw_square_player(t_game *data, int x, int y, int color)
{
	int	i;
	int	k;
	int	dim_x;
	int	dim_y;

	k = 0;
	dim_x = data->m_x;
	dim_y = data->m_y;
	while (k < dim_x)
	{
		i = 0;
		while (i < dim_y)
		{
			if ((x + k) < WIN_WIDTH && (y + i) < WIN_HEIGHT)
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
	while (k < data->m_x)
	{
		i = 0;
		while (i < data->m_y)
		{
			if ((x + k) < WIN_WIDTH && (y + i) < WIN_HEIGHT)
				my_mlx_pixel_put(data, x + k, y + i, color);
			i++;
		}
		k++;
	}
}

static void	calc_dim(t_game *data)
{
	data->m_x = WIN_WIDTH / (data->map_width * 5);
	if (data->m_x < 2)
		data->m_x = 2;
	data->m_y = WIN_HEIGHT / (data->map_height * 5);
	if (data->m_y < 2)
		data->m_y = 2;
	if (data->m_y > data->m_x)
		data->m_y = data->m_x;
	else if (data->m_x > data->m_y)
		data->m_x = data->m_y;
}

void	draw_minimap(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	calc_dim(data);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_square(data, x * data->m_x, y * data->m_y, 0XFFFFFF);
			else if (data->map[y][x] == '0')
				draw_square(data, x * data->m_x, y * data->m_y, 0x000000);
			x++;
		}
		y++;
	}
	draw_square_player(data, data->player.y * data->m_x, \
		data->player.x * data->m_y, 0xb000f5);
}
