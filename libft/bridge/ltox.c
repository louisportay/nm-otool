/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:00:47 by lportay           #+#    #+#             */
/*   Updated: 2019/02/25 14:18:22 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bridge.h"

static void	fill_lookup(char *lookup, char first_letter_charset)
{
	char		val;
	char		limit;

	val = '0';
	while (val <= '9')
		*lookup++ = val++;
	val = first_letter_charset;
	limit = val + 5;
	while (val <= limit)
		*lookup++ = val++;
}

/*
** 32 bytes is a good minimum length for buf
*/

char		*ltox_buf(unsigned long n, char *buf, enum e_prefix p,
						enum e_charset c)
{
	char			lookup[16];
	unsigned		i;

	fill_lookup(lookup, c == LOWER ? 'a' : 'A');
	i = base_width(n, 16) + (p == PREFIX ? 2 : 0);
	buf[i--] = '\0';
	buf[i--] = lookup[(n % 16)];
	while ((n /= 16) != 0)
		buf[i--] = lookup[(n % 16)];
	if (p)
	{
		buf[1] = 'x';
		buf[0] = '0';
	}
	return (buf);
}

char		*ltox(unsigned long n)
{
	char			lookup[16];
	char			*s;
	unsigned		i;

	fill_lookup(lookup, 'A');
	i = base_width(n, 16) + 2;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i--] = '\0';
	s[i--] = lookup[(n % 16)];
	while ((n /= 16) != 0)
		s[i--] = lookup[(n % 16)];
	s[1] = 'x';
	s[0] = '0';
	return (s);
}
