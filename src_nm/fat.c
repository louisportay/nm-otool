/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:37:50 by lportay           #+#    #+#             */
/*   Updated: 2019/03/11 17:06:49 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	dump_arch(char *arch)
{
	buf_c(get_buf(), '\n');
	buf_s(get_buf(), name(NULL));
	buf_s(get_buf(), arch);
	*name_printed() = 1;
}

int32_t		fat_64(void *p)
{
	struct fat_header	*h;
	struct fat_arch_64	*arch;
	int32_t				nfat;
	int32_t				i;

	h = (struct fat_header *)p;
	if (!safe(p + sizeof(struct fat_header)))
		return (err(INV_OBJ, name(NULL)));
	nfat = bswap_32(h->nfat_arch);
	if (!safe(p + sizeof(struct fat_header) + nfat * sizeof(*arch)))
		return (err(INV_OBJ, name(NULL)));
	arch = (struct fat_arch_64 *)(h + 1);
	i = -1;
	while (++i < nfat)
	{
		if (nfat > 1 && !i && hostarch(bswap_32(arch[i + 1].cputype)))
			continue ;
		if (nfat > 1 && !hostarch(bswap_32(arch[i].cputype)))
			dump_arch(i == 0 ? PPC64_S : X86_64_S);
		if (placeholder1(p + bswap_64(arch[i].offset)) < 0)
			return (-1);
		if (hostarch(bswap_32(arch[i].cputype)))
			return (0);
	}
	return (0);
}

int32_t		fat_32(void *p)
{
	struct fat_header	*h;
	struct fat_arch		*arch;
	int32_t				nfat;
	int32_t				i;

	h = (struct fat_header *)p;
	if (!safe(p + sizeof(struct fat_header)))
		return (err(INV_OBJ, name(NULL)));
	nfat = bswap_32(h->nfat_arch);
	if (!safe(p + sizeof(struct fat_header) + nfat * sizeof(*arch)))
		return (err(INV_OBJ, name(NULL)));
	arch = (struct fat_arch *)(h + 1);
	i = -1;
	while (++i < nfat)
	{
		if (nfat > 1 && !i && hostarch(bswap_32(arch[i + 1].cputype)))
			continue ;
		if (nfat > 1 && !hostarch(bswap_32(arch[i].cputype)))
			dump_arch(i == 0 ? PPC_S : I386_S);
		if (placeholder1(p + bswap_32(arch[i].offset)) < 0)
			return (-1);
		if (hostarch(bswap_32(arch[i].cputype)))
			return (0);
	}
	return (0);
}
