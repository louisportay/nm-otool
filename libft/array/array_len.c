/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:18:02 by lportay           #+#    #+#             */
/*   Updated: 2018/12/14 19:25:19 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

size_t	array_len(void **a)
{
	void **i;

	if (!a)
		return (0);
	i = a;
	while (*i)
		i++;
	return (i - a);
}
