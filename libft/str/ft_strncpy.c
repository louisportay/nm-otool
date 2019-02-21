/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:36:50 by lportay           #+#    #+#             */
/*   Updated: 2019/02/19 12:16:45 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*sncpy(char *dst, const char *src, size_t len)
{
	return (ft_strncpy(dst, src, len));
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *iter;

	iter = dst;
	while (len > 0 && *src != '\0')
	{
		*iter++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*iter++ = '\0';
		len--;
	}
	return (dst);
}
