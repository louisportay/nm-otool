/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:14:40 by lportay           #+#    #+#             */
/*   Updated: 2019/03/04 11:20:20 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t		corrupt_bin(t_sym *list)
{
	free(list);
	return (err(INV_OBJ, name(NULL)));
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
