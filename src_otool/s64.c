/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s64.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:35:28 by lportay           #+#    #+#             */
/*   Updated: 2019/02/25 15:04:05 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static int32_t	segments_64(struct load_command *lc, void *p)
{
	struct segment_command_64	*segment;
	struct section_64			*sct;
	uint32_t					i;

	if (!safe(lc + sizeof(struct segment_command_64)))
		return (err(INV_OBJ, name(NULL)));
	segment = (struct segment_command_64 *)lc;
	sct = (struct section_64 *)((void *)segment + sizeof(*segment));
	i = 0;
	while (safe(sct + i + 1) && i < ndian_32(segment->nsects))
	{
		if (!sncmp((sct + i)->segname, SEG_TEXT, 16) && !sncmp((sct + i)->sectname, SECT_TEXT, 16))
		{
			if (!safe(p + ndian_64((sct + i)->size)))
				return (err(INV_OBJ, name(NULL)));
			return (print_text(p + ndian_64((sct + i)->offset), sct + i, NULL));
		}
		i++;
	}
	if (!safe(sct + i + 1))
		return (err(INV_OBJ, name(NULL)));
	return (0);
}

int32_t	f_64_bits(void *p)
{
	struct mach_header_64	*h;
	struct load_command		*lc;
	uint32_t				ncmds;

	if (!safe(p + sizeof(struct mach_header_64)))
		return (err(INV_OBJ, name(NULL)));

	buf_s(get_buf(), name(NULL));
	buf_s(get_buf(), ":\n");
	h = (struct mach_header_64 *)p;
	endianness(h->magic);
	lc = p + sizeof(struct mach_header_64);
	ncmds = ndian_32(h->ncmds);
	while (safe (lc) && ncmds--)
	{
		if (ndian_32(lc->cmd) == LC_SEGMENT_64 && segments_64(lc, p) < 0)
			return (-1);
		lc = (void *)lc + ndian_32(lc->cmdsize);
	}
	if (!safe(lc))
		return (err(INV_OBJ, name(NULL)));
	return (0);
}

