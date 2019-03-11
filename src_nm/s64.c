/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s64.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:54:51 by lportay           #+#    #+#             */
/*   Updated: 2019/03/11 17:01:56 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void			set_sections_breakpoint(struct section_64 *sct,
										struct segment_command_64 *sgt,
										uint32_t nsects)
{
	if (!sncmp(sct->segname, SEG_TEXT, 16) &&
			!sncmp(sct->sectname, SECT_TEXT, 16))
		scts(SET, TEXT, ndian_32(sgt->nsects) - nsects + scts(GET, I, 0));
	else if (!sncmp(sct->segname, SEG_DATA, 16) &&
			!sncmp(sct->sectname, SECT_DATA, 16))
		scts(SET, DATA, ndian_32(sgt->nsects) - nsects + scts(GET, I, 0));
	else if (!sncmp(sct->segname, SEG_DATA, 16) &&
			!sncmp(sct->sectname, SECT_BSS, 16))
		scts(SET, BSS, ndian_32(sgt->nsects) - nsects + scts(GET, I, 0));
}

static int32_t	segments_64(void *p)
{
	struct segment_command_64	*sgt;
	struct section_64			*sct;
	uint32_t					nsects;

	if (!safe(p + sizeof(struct segment_command_64)))
		return (err(INV_OBJ, name(NULL)));
	sgt = (struct segment_command_64 *)p;
	sct = (struct section_64 *)(p + sizeof(struct segment_command_64));
	nsects = ndian_32(sgt->nsects);
	while (safe(sct) && nsects--)
	{
		set_sections_breakpoint(sct, sgt, nsects);
		sct++;
	}
	if (!safe(sct))
		return (err(INV_OBJ, name(NULL)));
	scts(ADD, I, ndian_32(sgt->nsects));
	return (0);
}

static void fill_sym(struct nlist_64 *symtable, char *strtable,
							int32_t nsyms, t_sym *list)
{
	list[nsyms].name = (char *)(strtable + ndian_32(symtable[nsyms].n_un.n_strx));
	list[nsyms].len = safe_len((char *)(strtable + ndian_32(symtable[nsyms].n_un.n_strx)));
	list[nsyms].value = ndian_64(symtable[nsyms].n_value);
	list[nsyms].type = symtable[nsyms].n_type;
	list[nsyms].sect = symtable[nsyms].n_sect;
}

/*
** We allocate only to sort the symbols
*/

static int32_t	symbols_64(struct symtab_command *sym, void *p)
{
	struct nlist_64			*symtable;
	char					*strtable;
	int32_t					nsyms;
	t_sym					*list;

	strtable = (char *)p + ndian_32(sym->stroff);
	symtable = p + ndian_32(sym->symoff);
	nsyms = ndian_32(sym->nsyms);
	if (!safe(strtable) || !safe(symtable))
		return (err(INV_OBJ, name(NULL)));
	if ((list = malloc(sizeof(t_sym) * nsyms)) == NULL)
		return (err("Cannot allocate Memory\n"));
	while (nsyms-- > 0 && safe(&symtable[nsyms]) &&
			safe(strtable + ndian_32(symtable[nsyms].n_un.n_strx)))
		fill_sym(symtable, strtable, nsyms, list);
	if (nsyms >= 0 && (!safe(&symtable[nsyms]) ||
		!safe(strtable + ndian_32(symtable[nsyms].n_un.n_strx))))
		return (corrupt_bin(list));
	sort_symbols(list, ndian_32(sym->nsyms));
	while ((uint32_t)++nsyms < ndian_32(sym->nsyms))
		print_sym(list[nsyms], 16);
	free(list);
	return (0);
}

/*
** The first load command is just after the header
** Refer yourself to the scheme
*/

int32_t			f_64_bits(void *p)
{
	struct mach_header_64	*h;
	struct load_command		*lc;
	uint32_t				ncmds;

	if (!safe(p + sizeof(struct mach_header_64)))
		return (err(INV_OBJ, name(NULL)));
	if (nb_args(NULL) > 2 && *name_printed() == 0)
		print_name(name(NULL));
	h = (struct mach_header_64 *)p;
	endianness(h->magic);
	lc = p + sizeof(struct mach_header_64);
	ncmds = ndian_32(h->ncmds);
	while (safe(lc) && ncmds--)
	{
		if (ndian_32(lc->cmd) == LC_SEGMENT_64 && segments_64(lc) < 0)
			return (-1);
		else if (ndian_32(lc->cmd) == LC_SYMTAB &&
				symbols_64((struct symtab_command *)lc, p) < 0)
			return (-1);
		lc = (void *)lc + ndian_32(lc->cmdsize);
	}
	if (!safe(lc))
		return (err(INV_OBJ, name(NULL)));
	return (0);
}
