/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:55:21 by emma              #+#    #+#             */
/*   Updated: 2023/11/14 12:17:35 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_freegame(t_game game)
{
	printf ("ft_freegame\n");
	// if (game.window.mlx)
	ft_strdel(game.window.mlx);
	// if (game.window.win)
	ft_strdel(game.window.win);

	printf ("...\n");
	ft_free_matrix(game.map.map);
// 	if (game.view.north.img)
// 		free(game.view.north.img);
// 	ft_strdel(game.view.south.img);
// 	ft_strdel(game.view.east.img);
// 	ft_strdel(game.view.weast.img);

	// printf ("%s\n", game.view.cealing[0]);
	// free(game.view.cealing[0]);
	ft_free_matrix(game.view.cealing);
	printf ("...\n");
	ft_free_matrix(game.view.floor);
}

void	ft_error(t_game game, char *str)
{
	// ft_freegame(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}
