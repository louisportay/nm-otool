/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:07:31 by lportay           #+#    #+#             */
/*   Updated: 2019/03/11 11:40:36 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	print_sect(t_sym s, uint8_t width)
{
	buf_nc(get_buf(), '0', width - base_width(s.value, 16));
	buf_x(get_buf(), s.value, NO_PREFIX, LOWER);
	if (s.sect == scts(GET, DATA, 0))
		buf_s(get_buf(), ext(s.type) ? " D " : " d ");
	else if (s.sect == scts(GET, BSS, 0))
		buf_s(get_buf(), ext(s.type) ? " B " : " b ");
	else if (s.sect == scts(GET, TEXT, 0))
		buf_s(get_buf(), ext(s.type) ? " T " : " t ");
	else
		buf_s(get_buf(), ext(s.type) ? " S " : " s ");
}

void		print_sym(t_sym s, uint8_t width)
{
	if (s.len == 0)
		return ;
	if (type(s.type) == N_UNDF && ext(s.type))
	{
		buf_nc(get_buf(), ' ', width);
		buf_s(get_buf(), " U ");
	}
	else if (type(s.type) == N_ABS)
	{
		buf_nc(get_buf(), '0', width - base_width(s.value, 16));
		buf_x(get_buf(), s.value, NO_PREFIX, LOWER);
		buf_s(get_buf(), ext(s.type) ? " A " : " a ");
	}
	else if (type(s.type) == N_INDR)
	{
		buf_nc(get_buf(), '0', width - base_width(s.value, 16));
		buf_x(get_buf(), s.value, NO_PREFIX, LOWER);
		buf_s(get_buf(), ext(s.type) ? " I " : " i ");
	}
	else if (type(s.type) == N_SECT)
		print_sect(s, width);
	else
		return ;
	buf_ns(get_buf(), s.name, s.len);
	buf_c(get_buf(), '\n');
}
