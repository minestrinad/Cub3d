/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:32:51 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/15 19:25:13 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*i;
	int		y1;

	y1 = y * (*data).test.line_len;
	i = (*data).test.addr + (y1 + x * ((*data).test.bits_pixel / 8));
	*(unsigned int *)i = color;
}

int	image(t_game *data)
{
	(*data).test.img = mlx_new_image((*data).window.mlx, WIN_WIDTH, WIN_HEIGHT);
	(*data).test.addr = mlx_get_data_addr((*data).test.img,
			&(*data).test.bits_pixel,
			&(*data).test.line_len,
			&(*data).test.endian);
	draw(data);
	mlx_put_image_to_window((*data).window.mlx, (*data).window.win,
		(*data).test.img, 0, 0);
	// key_map(data);
	return (0);
}
