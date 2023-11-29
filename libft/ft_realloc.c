/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:39:08 by ncortigi          #+#    #+#             */
/*   Updated: 2023/11/29 11:11:31 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_malloc_usable_size(char **ptr)
{
	size_t	size;

	size = 0;
	while (ptr[size])
		size++;
	return (size * sizeof(char *));
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (ft_calloc(1, size));
	new = ft_calloc(1, size);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, ft_malloc_usable_size(ptr));
	free(ptr);
	return (new);
}
