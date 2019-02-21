/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:51:21 by lportay           #+#    #+#             */
/*   Updated: 2019/02/14 19:54:56 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t		slen(const char *s)
{
	return (ft_strlen(s));
}

size_t		ft_strlen(const char *s)
{
	const char *i;

	i = s;
	while (*s)
		s++;
	return (s - i);
}
