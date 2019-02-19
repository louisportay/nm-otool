/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:07:31 by lportay           #+#    #+#             */
/*   Updated: 2019/02/19 19:07:38 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t	print_sym(t_sym s)
{
	if (slen(s.name) == 0)
		return (0);
	if (type(s.type) == N_UNDF && ext(s.type))
		buf_s(get_buf(), "                 U ");
	else if (type(s.type) == N_ABS)
	{
		buf_nc(get_buf(), '0', 16 - base_width(s.value, 16));
		buf_x(get_buf(), s.value, NO_PREFIX);
		buf_s(get_buf(), ext(s.type) ? " A " : " a ");
	}
	else if (type(s.type) == N_INDR)
	{
		buf_nc(get_buf(), '0', 16 - base_width(s.value, 16));
		buf_x(get_buf(), s.value, NO_PREFIX);
		buf_s(get_buf(), ext(s.type) ? " I " : " i ");
	}
	else if (type(s.type) == N_SECT)
	{
		buf_nc(get_buf(), '0', 16 - base_width(s.value, 16));
		buf_x(get_buf(), s.value, NO_PREFIX);
		if (s.sect == scts(GET, DATA, 0))
			buf_s(get_buf(), ext(s.type) ? " D " : " d ");
		else if (s.sect == scts(GET, BSS, 0))
			buf_s(get_buf(), ext(s.type) ? " B " : " b ");
		else if (s.sect == scts(GET, TEXT, 0))
			buf_s(get_buf(), ext(s.type) ? " T " : " t ");
		else
			buf_s(get_buf(), ext(s.type) ? " S " : " s ");
	}
	else
		return (0);
	buf_ns(get_buf(), s.name, 255);
	buf_c(get_buf(), '\n');
	return (0);
}
