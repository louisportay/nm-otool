/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 11:51:52 by lportay           #+#    #+#             */
/*   Updated: 2018/12/17 13:14:58 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	**array_new(size_t len)
{
	return (malloc(sizeof(void *) * (len + 1)));
}

void	**array_w_new(size_t height, size_t width)
{
	void	**a;
	size_t	i;

	a = malloc(sizeof(void *) * (height + 1));
	a[height] = NULL;
	i = 0;
	while (i < height)
	{
		if (!(a[i] = malloc(width)))
		{
			while (i != 0)
				free(a[--i]);
			free(a);
			return (NULL);
		}
		i++;
	}
	return (a);
}
