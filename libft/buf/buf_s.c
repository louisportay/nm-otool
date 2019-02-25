/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:34:28 by lportay           #+#    #+#             */
/*   Updated: 2019/02/24 18:37:22 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"

void	buf_s(t_buf *b, char *s)
{
	while (*s)
		buf_c(b, *s++);
}

void	buf_ns(t_buf *b, char *s, unsigned n)
{
	if (!n)
		return ;
	while (*s && n--)
		buf_c(b, *s++);
}

void	buf_s_pad(t_buf *b, char *s, char pad_char, unsigned pad_amount)
{
	buf_nc(b, pad_char, pad_amount);
	buf_s(b, s);
}
