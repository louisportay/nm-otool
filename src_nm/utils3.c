/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:42:32 by lportay           #+#    #+#             */
/*   Updated: 2019/03/11 17:47:08 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

char		*name(char *filename)
{
	static char *s = NULL;

	if (filename)
		s = filename;
	return (s);
}

uint32_t	nb_args(uint32_t *ac)
{
	static uint32_t	nb;

	if (ac)
		nb = *ac;
	return (nb);
}

void		print_name(char *path)
{
	buf_c(get_buf(), '\n');
	buf_s(get_buf(), path);
	buf_s(get_buf(), ":\n");
}

uint32_t	*name_printed(void)
{
	static uint32_t printed;

	return (&printed);
}
