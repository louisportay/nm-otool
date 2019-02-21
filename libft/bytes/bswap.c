/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bswap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:56:52 by lportay           #+#    #+#             */
/*   Updated: 2019/02/13 13:01:43 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bytes.h"

/*
** bswap_16 - reverse bytes in a uint16_t value.
** @val: value whose bytes to swap.
**
** Example:
**	// Output contains "1024 is 4 as two bytes reversed"
**	printf("1024 is %u as two bytes reversed\n", bswap_16(1024));
*/

inline uint16_t bswap_16(uint16_t val)
{
	return ((val & (uint16_t)0x00ffU) << 8)
		| ((val & (uint16_t)0xff00U) >> 8);
}

/*
** bswap_32 - reverse bytes in a uint32_t value.
** @val: value whose bytes to swap.
**
** Example:
**	// Output contains "1024 is 262144 as four bytes reversed"
**	printf("1024 is %u as four bytes reversed\n", bswap_32(1024));
*/

inline uint32_t bswap_32(uint32_t val)
{
	return ((val & (uint32_t)0x000000ffUL) << 24)
		| ((val & (uint32_t)0x0000ff00UL) <<  8)
		| ((val & (uint32_t)0x00ff0000UL) >>  8)
		| ((val & (uint32_t)0xff000000UL) >> 24);
}

/*
** bswap_64 - reverse bytes in a uint64_t value.
** @val: value whose bytes to swap.
**
** Example:
**	// Output contains "1024 is 1125899906842624 as eight bytes reversed"
**	printf("1024 is %llu as eight bytes reversed\n",
**		(unsigned long long)bswap_64(1024));
*/

inline uint64_t bswap_64(uint64_t val)
{
	return ((val & (uint64_t)0x00000000000000ffULL) << 56)
		| ((val & (uint64_t)0x000000000000ff00ULL) << 40)
		| ((val & (uint64_t)0x0000000000ff0000ULL) << 24)
		| ((val & (uint64_t)0x00000000ff000000ULL) <<  8)
		| ((val & (uint64_t)0x000000ff00000000ULL) >>  8)
		| ((val & (uint64_t)0x0000ff0000000000ULL) >> 24)
		| ((val & (uint64_t)0x00ff000000000000ULL) >> 40)
		| ((val & (uint64_t)0xff00000000000000ULL) >> 56);
}
