/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:04:34 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/15 19:34:57 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_close(t_game *game)
{
	mlx_destroy_image((*game).window.mlx, (*game).test.img);
	mlx_destroy_window((*game).window.mlx, (*game).window.win);
	mlx_destroy_display((*game).window.mlx);
	//fare free di tutto
	exit(0);
	return (0);
}
