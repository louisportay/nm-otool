/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:05:50 by lportay           #+#    #+#             */
/*   Updated: 2019/02/19 19:06:48 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static inline void	swap_sym(t_sym *a, t_sym *b)
{
	t_sym t;

	t = *a;
	*a = *b;
	*b = t;
}

void				sort_symbols(t_sym *list, uint32_t len)
{
	t_sym		pivot;
	uint32_t	i;
	uint32_t	j;

	if (len < 2)
		return;
	pivot = list[len / 2];
	i = 0;
	j = len - 1;
	while (1)
	{
		while (sncmp(list[i].name, pivot.name, SYMLEN) < 0)
			i++;
		while (sncmp(list[j].name, pivot.name, SYMLEN) > 0)
			j--;
		if (i >= j)
			break;
		swap_sym(&list[i++], &list[j--]);
	} 
	sort_symbols(list, i);
	sort_symbols(list + i, len - i);
}

