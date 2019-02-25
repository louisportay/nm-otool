/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:39:37 by lportay           #+#    #+#             */
/*   Updated: 2019/02/25 14:54:02 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static int32_t	print_text_64(void *text, uint64_t size, uint64_t addr)
{
	uint64_t i;

	if (!safe(text + size))
		return (err(INV_OBJ, name(NULL)));
	i = 0;
	while (i < uround(size, 16))
	{
		if (i % 16 == 0)
		{
			buf_x_pad(get_buf(), addr + i, (struct s_bufopt)
					{NO_PREFIX, LOWER, 16 - base_width(addr + i, 16), '0'});
			buf_c(get_buf(), '\t');
		}
		if (i < size)
		{
			buf_x_pad(get_buf(), 0xff & ((char *)text)[i], (struct s_bufopt)
	{NO_PREFIX, LOWER, 2 - base_width(0xff & ((char *)text)[i], 16), '0'});
			buf_c(get_buf(), ' ');
		}
		if (i % 16 == 15)
			buf_c(get_buf(), '\n');
		i++;
	}
	return (0);
}

static int32_t	print_text_32(void *text, uint32_t size, uint32_t addr)
{
	uint32_t i;

	if (!safe(text + size))
		return (err(INV_OBJ, name(NULL)));
	i = 0;
	while (i < uround(size, 16))
	{
		if (i % 16 == 0)
		{
			buf_x_pad(get_buf(), addr + i, (struct s_bufopt)
				{NO_PREFIX, LOWER, 16 - base_width(addr + i, 16), '0'});
			buf_c(get_buf(), '\t');
		}
		if (i < size)
			buf_x_pad(get_buf(), 0xff & ((char *)text)[i], (struct s_bufopt)
	{NO_PREFIX, LOWER, 2 - base_width(0xff & ((char *)text)[i], 16), '0'});
		if (i % 4 == 3 && i < size)
			buf_c(get_buf(), ' ');
		if (i % 16 == 15)
			buf_c(get_buf(), '\n');
		i++;
	}
	return (0);
}

int32_t	print_text(void *text, struct section_64 *sct64, struct section *sct)
{
	buf_s(get_buf(), "Contents of (__TEXT,__text) section\n");
	if (sct64)
		return (print_text_64(text, ndian_64(sct64->size), ndian_64(sct64->addr)));
	else if (sct)
		return (print_text_32(text, ndian_32(sct->size), ndian_32(sct->addr)));
	else
		return (-1);
}

