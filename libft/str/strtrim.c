/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:46:19 by lportay           #+#    #+#             */
/*   Updated: 2018/12/13 12:15:10 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*strtrim(char const *s)
{
	char *iter;

	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		s++;
	iter = (char *)s;
	while (*iter)
		iter++;
	iter--;
	while (ft_isspace(*iter))
		iter--;
	iter++;
	return (ft_strndup(s, iter - s));
}
