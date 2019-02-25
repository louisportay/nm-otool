/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:29:52 by lportay           #+#    #+#             */
/*   Updated: 2019/02/22 11:08:12 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "otool.h"

t_buf		*get_buf(void)
{
	static t_buf b;

	return (&b);
}

char		*name(char *filename)
{
	static char *s = NULL;

	if (filename)
		s = filename;
	return (s);
}

void		*max(void *p, off_t size)
{
	static void *m;

	if (p)
		m = p + size;
	return (m);
}

uint32_t	safe(void *pos)
{
	return (max(NULL, 0) >= pos);
}
