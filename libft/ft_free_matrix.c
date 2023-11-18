/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:48:56 by everonel          #+#    #+#             */
/*   Updated: 2023/11/18 16:37:10 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_free_matrix(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return ;
	while (str[i])
	{
		ft_strdel(&str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
