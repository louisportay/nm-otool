/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:21:03 by lportay           #+#    #+#             */
/*   Updated: 2019/01/14 21:21:05 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int		strchri(const char *s, char c)
{
	const char *s_addr;

	s_addr = s;
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return (s - s_addr);
	else
		return (-1);
}

int		strrchri(const char *s, int c)
{
	const char *iter;

	iter = s + ft_strlen(s);
	while (*iter != c && iter != s)
		iter--;
	if (*iter == c)
		return (iter - s);
	else
		return (-1);
}
