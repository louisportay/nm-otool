/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:05:50 by lportay           #+#    #+#             */
/*   Updated: 2019/03/11 11:47:23 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	sort_symbols(t_sym *s, uint32_t size)
{
	t_sym		swap;
	int32_t		r;
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			r = scmp(s[i].name, s[j].name);
			if (r > 0 || (r == 0 && s[i].value > s[j].value))
			{
				swap = s[i];
				s[i] = s[j];
				s[j] = swap;
			}
			j++;
		}
		i++;
	}
}
