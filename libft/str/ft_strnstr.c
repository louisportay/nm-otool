/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:53:16 by lportay           #+#    #+#             */
/*   Updated: 2018/12/11 18:16:04 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned i;
	unsigned j;
	unsigned k;
	unsigned needle_len;

	k = 0;
	if (!ft_strlen(needle) || haystack == needle)
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack)
	{
		i = 0;
		j = 0;
		while (haystack[i] == needle[j] && j < needle_len && (k + i) < len)
		{
			i++;
			j++;
		}
		if (j == needle_len)
			return ((char *)haystack);
		haystack++;
		k++;
	}
	return (NULL);
}
