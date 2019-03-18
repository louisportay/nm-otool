/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:03:46 by lportay           #+#    #+#             */
/*   Updated: 2019/03/18 13:02:27 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

uint8_t		type(uint8_t t)
{
	return (t & N_TYPE);
}

uint8_t		ext(uint8_t e)
{
	return (e & N_EXT);
}

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
