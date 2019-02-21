/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:02:46 by lportay           #+#    #+#             */
/*   Updated: 2019/02/19 12:16:24 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*scpy(char *dst, const char *src)
{
	return (ft_strcpy(dst, src));
}

char	*ft_strcpy(char *dst, const char *src)
{
	char *s;

	s = dst;
	while ((*s++ = *src++))
		;
	return (dst);
}
