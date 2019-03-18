/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 13:29:52 by lportay           #+#    #+#             */
/*   Updated: 2019/03/18 14:02:34 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

t_ctx		*ctx(void)
{
	static t_ctx c;

	return (&c);
}

t_buf		*get_buf(void)
{
	return (&ctx()->b);
}

uint32_t	safe(void *pos)
{
	return (ctx()->max >= pos);
}

uint32_t	hostarch(cpu_type_t type)
{
	return (((type == CPU_TYPE_X86_64) && (sizeof(void *) == 8))
			|| ((type == CPU_TYPE_I386) && (sizeof(void *) == 4)));
}
