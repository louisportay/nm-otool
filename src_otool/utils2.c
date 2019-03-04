/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 12:01:34 by lportay           #+#    #+#             */
/*   Updated: 2019/03/04 12:01:53 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

uint32_t	hostarch(cpu_type_t type)
{
	return (((type == CPU_TYPE_X86_64) && (sizeof(void *) == 8))
			|| ((type == CPU_TYPE_I386) && (sizeof(void *) == 4)));
}
