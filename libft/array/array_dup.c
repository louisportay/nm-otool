/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:18:16 by lportay           #+#    #+#             */
/*   Updated: 2019/01/14 21:18:16 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	**array_dup(void **a, size_t len, void *(*dup)(void *),
					void (*del)(void *))
{
	void	**cpy;
	size_t	iter;

	if (!(cpy = array_new(len)))
		return (NULL);
	cpy[len] = NULL;
	iter = 0;
	while (iter < len)
	{
		cpy[iter] = dup(a[iter]);
		if (!cpy[iter])
		{
			while (iter > 0)
				del(cpy[--iter]);
			free(cpy);
			return (NULL);
		}
		iter++;
	}
	return (cpy);
}
