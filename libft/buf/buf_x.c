/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:24:42 by lportay           #+#    #+#             */
/*   Updated: 2019/02/24 18:33:20 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"

void	buf_x(t_buf *b, unsigned long l, enum e_prefix p, enum e_charset c)
{
	char s[32];

	ltox_buf(l, s, p, c);
	buf_s(b, s);
}

void	buf_x_pad(t_buf *b, unsigned long l, struct s_bufopt bo)
{	
	buf_nc(b, bo.pad_char, bo.pad_amount);
	buf_x(b, l, bo.p, bo.cs);
}
