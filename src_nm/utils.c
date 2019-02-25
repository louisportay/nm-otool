/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:14:40 by lportay           #+#    #+#             */
/*   Updated: 2019/02/25 15:01:23 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

uint64_t	scts(int8_t action, enum e_section index, uint64_t value)
{
	static uint64_t s[4] = {0, 0, 0, 0};

	if (action == RESET)
	{
		s[TEXT] = 0;
		s[DATA] = 0;
		s[BSS] = 0;
		s[I] = 0;
	}
	else if (action == ADD)
		s[index] += value;
	else if (action == SET)
		s[index] = value;
	else if (action == GET)
		return (s[index]);
	return (0);
}

uint8_t		type(uint8_t t)
{
	return (t & N_TYPE);
}

uint8_t		ext(uint8_t e)
{
	return (e & N_EXT);
}

t_buf		*get_buf(void)
{
	static t_buf b;

	return (&b);
}

char *name(char *filename)
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
