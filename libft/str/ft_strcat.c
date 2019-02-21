/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:18:04 by lportay           #+#    #+#             */
/*   Updated: 2018/12/11 17:42:44 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *iter;

	iter = dest;
	while (*iter)
		iter++;
	while (*src)
		*iter++ = (unsigned char)*src++;
	*iter = '\0';
	return (dest);
}
