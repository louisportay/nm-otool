/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s32.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:35:28 by lportay           #+#    #+#             */
/*   Updated: 2019/02/25 16:09:20 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static int32_t	segments(struct load_command *lc, void *p)
{
	struct segment_command	*segment;
	struct section			*sct;
	uint32_t				i;

	if (!safe(lc + sizeof(struct segment_command)))
		return (err(INV_OBJ, name(NULL)));
	segment = (struct segment_command *)lc;
	sct = (struct section *)((void *)segment + sizeof(*segment));
	i = 0;
	while (safe(sct + i + 1) && i < ndian_32(segment->nsects))
	{
		if (!sncmp((sct + i)->segname, SEG_TEXT, 16) && !sncmp((sct + i)->sectname, SECT_TEXT, 16))
		{
			if (!safe(p + ndian_32((sct + i)->size)))
				return (err(INV_OBJ, name(NULL)));
			return (print_text(p + ndian_32((sct + i)->offset), NULL, sct + i));
		}
		i++;
	}
	if (!safe(sct + i + 1))
		return (err(INV_OBJ, name(NULL)));
	return (0);
}

int32_t	f_32_bits(void *p)
{
	struct mach_header	*h;
	struct load_command	*lc;
	uint32_t			ncmds;

	if (!safe(p + sizeof(struct mach_header)))
		return (err(INV_OBJ, name(NULL)));

	h = (struct mach_header *)p;
	endianness(h->magic);
	lc = p + sizeof(struct mach_header);
	ncmds = ndian_32(h->ncmds);
	while (safe (lc) && ncmds--)
	{
		if (ndian_32(lc->cmd) == LC_SEGMENT && segments(lc, p) < 0)
			return (-1);
		lc = (void *)lc + ndian_32(lc->cmdsize);
	}
	if (!safe(lc))
		return (err(INV_OBJ, name(NULL)));
	return (0);
}
