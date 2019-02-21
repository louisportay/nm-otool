/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:03:35 by lportay           #+#    #+#             */
/*   Updated: 2018/12/11 17:50:11 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/*
** man 3 strstr
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *iter_haystack;
	char *iter_needle;

	if (!ft_strlen(needle) || haystack == needle)
		return ((char *)haystack);
	while (*haystack)
	{
		iter_haystack = (char *)haystack;
		iter_needle = (char *)needle;
		while (*iter_haystack++ == *iter_needle && *iter_needle != '\0')
			iter_needle++;
		if (*iter_needle == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
