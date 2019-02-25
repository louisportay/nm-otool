/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:08:55 by lportay           #+#    #+#             */
/*   Updated: 2019/02/24 18:34:24 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buf.h"

void	buf_c(t_buf *b, char c)
{
	b->buf[b->written++ % BUFF_SIZE] = c;
	if ((b->written % BUFF_SIZE) == 0)
		write(b->fd, b->buf, BUFF_SIZE);
}

void	buf_nc(t_buf *b, char c, unsigned n)
{
	if (!n)
		return ;
	while (n--)
		buf_c(b, c);
}
