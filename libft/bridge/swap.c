/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:19:09 by lportay           #+#    #+#             */
/*   Updated: 2019/02/20 22:54:05 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bridge.h"

/*
** int			vswap(void *a, void *b, size_t size)
** {
**     char buf[512];
**     void *p;
**
** 	p = buf;
**     if (size > sizeof(buf) && !(p = malloc(size)))
** 		return (-1);
**     mcpy(p, a, size);
**     mcpy(a, b, size);
**     mcpy(b, p, size);
**     if (p != buf)
** 		free(p);
** 	return (0);
** }
*/

void		lswap(long *a, long *b)
{
	long c;

	c = *a;
	*a = *b;
	*b = c;
}

void		iswap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
