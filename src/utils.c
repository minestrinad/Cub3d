/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:55:21 by emma              #+#    #+#             */
/*   Updated: 2023/11/15 15:10:20 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_freegame(t_game game)
{
	printf ("ft_freegame\n");
	if (game.window->mlx)
	ft_strdel(game.window->mlx);
	if (game.window->win)
	ft_strdel(game.window->win);

	printf ("...\n");
	if (game.map.map)
		ft_free_matrix(game.map.map);
	if (game.view.north.img)
		free(game.view.north.img);
		if (game.view.south.img)
	ft_strdel(game.view.south.img);
	if (game.view.east.img)
	ft_strdel(game.view.east.img);
	if (game.view.weast.img)
	ft_strdel(game.view.weast.img);

	// printf ("%s\n", game.view.cealing[0]);
	// free(game.view.cealing[0]);
		if (game.view.cealing)
	ft_free_matrix(game.view.cealing);
	printf ("...\n");
		if (game.view.floor)
	ft_free_matrix(game.view.floor);
}

void	ft_error(t_game game, char *str)
{
	// ft_freegame(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}
