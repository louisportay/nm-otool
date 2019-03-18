/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:14:40 by lportay           #+#    #+#             */
/*   Updated: 2019/03/18 13:00:58 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t		corrupt_bin(t_sym *list)
{
	free(list);
	return (err(INV_OBJ, ctx()->name));
}

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
		if (!safe(name + 1))
			return (len);
	}
	return (len);
}

void		print_name(void)
{
	buf_c(get_buf(), '\n');
	buf_s(get_buf(), ctx()->name);
	buf_s(get_buf(), ":\n");
}
