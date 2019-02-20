/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:49:04 by lportay           #+#    #+#             */
/*   Updated: 2019/02/20 21:10:33 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t	fat_32(void *p)
{
	struct fat_header	*h;
	struct fat_arch		*arch;
	uint32_t			nfat;
	uint32_t			i;



	h = (struct fat_header *)p;
	if (!safe(p + sizeof(struct fat_header)))
		return (err(INV_OBJ, name(NULL)));
	endianness(h->magic);
	nfat = ndian_32(h->nfat_arch);
	if (!safe(p + sizeof(struct fat_header) + nfat * sizeof(struct fat_arch)))
		return (err(INV_OBJ, name(NULL)));
	arch = (struct fat_arch *)(h + 1);
	i = 0;
	while (i < nfat)
	{
		if (nfat > 1 && !hostarch(ndian_32(arch[i].cputype)))
		{
			buf_c(get_buf(), '\n');
			buf_s(get_buf(), name(NULL));
			buf_s(get_buf(), i == 0 ? PPC_S : I386_S);
		}
		if (placeholder1(p + ndian_32(arch[i].offset)) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int32_t	fat_64(void *p)
{
	struct fat_header	*h;
	struct fat_arch_64	*arch;
	uint32_t			nfat;
	uint32_t			i;


	h = (struct fat_header *)p;
	if (!safe(p + sizeof(struct fat_header)))
		return (err(INV_OBJ, name(NULL)));
	endianness(h->magic);
	nfat = ndian_32(h->nfat_arch);
	if (!safe(p + sizeof(struct fat_header) + nfat * sizeof(struct fat_arch_64)))
		return (err(INV_OBJ, name(NULL)));
	arch = (struct fat_arch_64 *)(h + 1);
	i = 0;
	while (i < nfat)
	{
		if (nfat > 1 && !hostarch(ndian_32(arch[i].cputype)))
		{
			buf_c(get_buf(), '\n');
			buf_s(get_buf(), name(NULL));
			buf_s(get_buf(), i == 0 ? PPC64_S : X86_64_S);
		}
		if (placeholder1(p + ndian_64(arch[i].offset)) < 0)
			return (-1);
		i++;
	}
	return (0);
}