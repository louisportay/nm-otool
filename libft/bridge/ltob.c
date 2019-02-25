/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:59:43 by lportay           #+#    #+#             */
/*   Updated: 2019/02/25 14:18:29 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bridge.h"

/*
** 80 bytes is a good minimum length for buf
*/

char	*ltob_buf(unsigned long n, char *buf, enum e_prefix p)
{
	unsigned		i;

	i = base_width(n, 2) + (p == PREFIX ? 2 : 0);
	buf[i--] = '\0';
	buf[i--] = (n % 2) + '0';
	while ((n /= 2) != 0)
		buf[i--] = (n % 2) + '0';
	if (p)
	{
		buf[1] = 'b';
		buf[0] = '0';
	}
	return (buf);
}

char	*ltob(unsigned long n)
{
	char			*s;
	unsigned		i;

	i = base_width(n, 2) + 2;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i--] = '\0';
	s[i--] = (n % 2) + '0';
	while ((n /= 2) != 0)
		s[i--] = (n % 2) + '0';
	s[1] = 'b';
	s[0] = '0';
	return (s);
}
