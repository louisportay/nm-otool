/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strequ.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:14:27 by lportay           #+#    #+#             */
/*   Updated: 2018/12/13 11:46:19 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	strequ(char const *s1, char const *s2)
{
	if (s1 == s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == '\0' && *s2 == '\0');
}

int	strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (s1 == s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		i++;
	return (s1[i] == '\0' && s2[i] == '\0');
}
