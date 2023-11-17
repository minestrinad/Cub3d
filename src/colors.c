/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:07:38 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/17 13:21:32 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_rgb(int *color, int t)
{
	return (t << 24 | color[0] << 16 | color[1] << 8 | color[2]);
}

int	get_pixel_color(t_texture texture, int x, int y)
{
	char	*pixel_add;
	int		new_color;

	if (x < 0 || x >= texture.width || y < 0 || y >= texture.height)
		return (0);
	pixel_add = texture.pixels + (y * texture.line_len + x * \
		(texture.bits_pixel / 8));
	new_color = *(unsigned int *)pixel_add;
	return (new_color);
}

int	ft_make_shade(int color)
{
	int	r;
	int	g;
	int	b;

	r = (color << 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r *= 0.5;
	g *= 0.5;
	b *= 0.5;
	return ((r << 16) | (g << 8) | b);
}
