/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:53:19 by lportay           #+#    #+#             */
/*   Updated: 2019/02/15 18:58:45 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bridge.h"

/*
** 32 bytes is a good minimum length for buf
*/

char	*ultoa_buf(long n, char *buf)
{
	unsigned		i;

	i = lwidth(n);
	buf[i--] = '\0';
	buf[i--] = (n % 10) + '0';
	while ((n /= 10) != 0)
		buf[i--] = (n % 10) + '0';
	return (buf);
}

char	*ultoa(unsigned long n)
{
	char			*s;
	unsigned		i;

	i = lwidth(n);
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i--] = '\0';
	s[i--] = (n % 10) + '0';
	while ((n /= 10) != 0)
		s[i--] = (n % 10) + '0';
	return (s);
}

/*
** 32 bytes is a good minimum length for buf
*/

char	*ltoa_buf(long n, char *buf)
{
	unsigned long	m;
	unsigned		i;

	i = lwidth(n);
	m = (n < 0) ? -n : n;
	buf[i--] = '\0';
	buf[i--] = (m % 10) + '0';
	while ((m /= 10) != 0)
		buf[i--] = (m % 10) + '0';
	if (n < 0)
		buf[0] = '-';
	return (buf);
}

char	*ltoa(long n)
{
	char			*s;
	unsigned long	m;
	unsigned		i;

	i = lwidth(n);
	m = (n < 0) ? -n : n;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i--] = '\0';
	s[i--] = (m % 10) + '0';
	while ((m /= 10) != 0)
		s[i--] = (m % 10) + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}
