/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:56:05 by lportay           #+#    #+#             */
/*   Updated: 2018/12/13 12:11:55 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strsub(char const *s, unsigned start, size_t len)
{
	if (ft_strlen(s) <= start)
		return (NULL);
	return (ft_strndup(s + start, len));
}
