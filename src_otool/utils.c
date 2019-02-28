/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:29:52 by lportay           #+#    #+#             */
/*   Updated: 2019/02/28 15:33:32 by lportay          ###   ########.fr       */
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

uint32_t	hostarch(cpu_type_t type)
{
	return (((type == CPU_TYPE_X86_64) && (sizeof(void *) == 8))
			|| ((type == CPU_TYPE_I386) && (sizeof(void *) == 4)));
}

uint32_t	*name_printed(void)
{
	static uint32_t printed;

	return (&printed);
}
