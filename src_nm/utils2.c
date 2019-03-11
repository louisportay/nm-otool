/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:03:46 by lportay           #+#    #+#             */
/*   Updated: 2019/03/11 17:02:45 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

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
	return (max(NULL, 0) > pos);
}

uint32_t	hostarch(cpu_type_t type)
{
	if ((type == CPU_TYPE_X86_64) && (sizeof(void *) == 8))
		return (1);
	if ((type == CPU_TYPE_I386) && (sizeof(void *) == 4))
		return (1);
	return (0);
}

uint64_t	safe_len(char *name)
{
	uint64_t len;

	len = 0;
	while (*name)
	{
		len++;
		name++;
		if (!safe(name))
			return (len);
	}
	return (len);
}

uint32_t	nb_args(uint32_t *ac)
{
	static uint32_t	nb;

	if (ac)
		nb = *ac;
	return (nb);
}

void	print_name(char *path)
{
	buf_c(get_buf(), '\n');
	buf_s(get_buf(), path);
	buf_s(get_buf(), ":\n");
}

uint32_t	*name_printed(void)
{
	static uint32_t printed;

	return (&printed);
}
