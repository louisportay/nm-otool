/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:37:50 by lportay           #+#    #+#             */
/*   Updated: 2019/03/19 19:16:47 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void		dump_arch(char *arch)
{
	buf_c(get_buf(), '\n');
	buf_s(get_buf(), ctx()->name);
	buf_s(get_buf(), arch);
	ctx()->name_printed = 1;
}

static int32_t	fat_initializer(void *p, struct fat_header **h, int32_t *nfat,
								int32_t *i)
{
	*h = (struct fat_header *)p;
	if (!safe(p + sizeof(struct fat_header)))
		return (err(INV_OBJ, ctx()->name));
	*nfat = bswap_32((*h)->nfat_arch);
	*i = -1;
	return (0);
}

static int32_t	overlap(struct fat_header *h, struct fat_arch *arch,
						struct fat_arch_64 *arch64)
{
	uint32_t	i;

	i = 0;
	while (i < bswap_32(h->nfat_arch))
	{
		if (arch && bswap_32(arch[i].offset) < sizeof(*h))
			return (-1);
		else if (arch64 && bswap_64(arch[i].offset) < sizeof(*h))
			return (-1);
		i++;
	}
	return (0);
}

int32_t			fat_64(void *p)
{
	struct fat_header	*h;
	struct fat_arch_64	*arch;
	int32_t				nfat;
	int32_t				i;

	if (fat_initializer(p, &h, &nfat, &i) == -1)
		return (-1);
	arch = (struct fat_arch_64 *)(h + 1);
	if (!safe(p + sizeof(struct fat_header) + nfat * sizeof(*arch)) ||
			(overlap(h, NULL, arch) == -1))
		return (err(INV_OBJ, ctx()->name));
	while (++i < nfat)
	{
		if (nfat > 1 && !i && hostarch(bswap_32(arch[i + 1].cputype)))
			continue ;
		if (nfat > 1 && !hostarch(bswap_32(arch[i].cputype)))
			dump_arch(i == 0 ? PPC64_S : X86_64_S);
		else if (LEGACY_BEHAVIOUR)
			ctx()->name_printed = 1;
		if (placeholder1(p + bswap_64(arch[i].offset)) < 0)
			return (-1);
		if (hostarch(bswap_32(arch[i].cputype)))
			return (0);
	}
	return (0);
}

int32_t			fat_32(void *p)
{
	struct fat_header	*h;
	struct fat_arch		*arch;
	int32_t				nfat;
	int32_t				i;

	if (fat_initializer(p, &h, &nfat, &i) == -1)
		return (-1);
	arch = (struct fat_arch *)(h + 1);
	if (!safe(p + sizeof(struct fat_header) + nfat * sizeof(*arch)) ||
			(overlap(h, arch, NULL) == -1))
		return (err(INV_OBJ, ctx()->name));
	while (++i < nfat)
	{
		if (nfat > 1 && !i && hostarch(bswap_32(arch[i + 1].cputype)))
			continue ;
		if (nfat >= 1 && !hostarch(bswap_32(arch[i].cputype)))
			dump_arch(i == 0 ? PPC_S : I386_S);
		else if (LEGACY_BEHAVIOUR)
			ctx()->name_printed = 1;
		if (placeholder1(p + bswap_32(arch[i].offset)) < 0)
			return (-1);
		if (hostarch(bswap_32(arch[i].cputype)))
			return (0);
	}
	return (0);
}
