/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:30:00 by lportay           #+#    #+#             */
/*   Updated: 2018/12/12 17:27:40 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strdup(const char *s)
{
	char *dup;
	char *iter;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	iter = dup;
	while (*s)
	{
		*iter = *s;
		s++;
		iter++;
	}
	*iter = '\0';
	return (dup);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	char	*iter;
	size_t	len;

	len = ft_strlen(s);
	if (len < n)
		n = len;
	if (!(dup = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	iter = dup;
	while (*s && n)
	{
		*iter = *s;
		s++;
		iter++;
		n--;
	}
	*iter = '\0';
	return (dup);
}
