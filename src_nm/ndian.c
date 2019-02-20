/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ndian.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:25:52 by lportay           #+#    #+#             */
/*   Updated: 2019/02/20 12:21:58 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

uint32_t	endianness(uint32_t magic)
{
	static uint32_t endian;

	if (magic != 0)
		endian = (magic == MH_MAGIC_64 || magic == MH_MAGIC
						|| magic == FAT_MAGIC_64 || magic == FAT_MAGIC);
	return (endian);
}

uint64_t	ndian_64(uint64_t n)
{
	return ((endianness(0) == NATIVE) ? n : bswap_64(n));
}

uint32_t	ndian_32(uint32_t n)
{
	return ((endianness(0) == NATIVE) ? n : bswap_32(n));
}

uint16_t	ndian_16(uint16_t n)
{
	return ((endianness(0) == NATIVE) ? n : bswap_16(n));
}
