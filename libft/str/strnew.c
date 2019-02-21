/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:26:21 by lportay           #+#    #+#             */
/*   Updated: 2018/12/12 13:05:52 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Renvoie une chaîne propre de "size" caracteres + 1 ('\0' final)
*/

#include "str.h"

char	*strnew(size_t size)
{
	char	*s;
	char	*iter;

	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	iter = s;
	while (size--)
		*iter++ = '\0';
	*iter = '\0';
	return (s);
}
