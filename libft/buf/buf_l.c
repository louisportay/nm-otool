/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:43:42 by lportay           #+#    #+#             */
/*   Updated: 2019/02/20 20:17:06 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"

void	buf_ul(t_buf *b, unsigned long l)
{
	char s[32];

	ultoa_buf(l, s);
	buf_s(b, s);
}

void	buf_l(t_buf *b, long l)
{
	char s[32];

	ltoa_buf(l, s);
	buf_s(b, s);
}

void	buf_x(t_buf *b, unsigned long l, int prefix, int _case)
{
	char s[32];

	ltox_buf(l, s, prefix, _case);
	buf_s(b, s);
}

void	buf_b(t_buf *b, unsigned long l, int prefix)
{
	char s[80];

	ltob_buf(l, s, prefix);
	buf_s(b, s);
}
