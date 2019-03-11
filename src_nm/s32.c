/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s32.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:54:51 by lportay           #+#    #+#             */
/*   Updated: 2019/03/11 15:38:21 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void		set_sections_breakpoint(struct section *sct,
										struct segment_command *sgt,
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

static int32_t	segments(void *p)
{
	struct segment_command	*sgt;
	struct section			*sct;
	uint32_t				nsects;

	if (!safe(p + sizeof(struct segment_command)))
		return (err(INV_OBJ, name(NULL)));
	sgt = (struct segment_command *)p;
	sct = (struct section *)(p + sizeof(struct segment_command));
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

static void		fill_sym(struct nlist *symtable, char *strtable,
							int32_t nsyms, t_sym *list)
{
	list[nsyms].name = (char *)(strtable + ndian_32(symtable[nsyms].n_un.n_strx));
	list[nsyms].len = safe_len((char *)(strtable + ndian_32(symtable[nsyms].n_un.n_strx)));
	list[nsyms].value = ndian_32(symtable[nsyms].n_value);
	list[nsyms].type = symtable[nsyms].n_type;
	list[nsyms].sect = symtable[nsyms].n_sect;
}

/*
** We allocate only to sort the symbols
*/

static int32_t	symbols(struct symtab_command *sym, void *p)
{
	struct nlist			*symtable;
	char					*strtable;
	int32_t					nsyms;
	t_sym					*list;

	if (!safe(sym + sizeof(struct symtab_command)))
		return (err(INV_OBJ, name(NULL)));
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
		print_sym(list[nsyms], 8);
	free(list);
	return (0);
}

/*
** The first load command is just after the header
** Refer yourself to the scheme
*/

int32_t			f_32_bits(void *p)
{
	struct mach_header	*h;
	struct load_command	*lc;
	uint32_t			ncmds;

	if (!safe(p + sizeof(struct mach_header)))
		return (err(INV_OBJ, name(NULL)));
	if (nb_args(NULL) > 2 && *name_printed() == 0)
		print_name(name(NULL));
	h = (struct mach_header *)p;
	endianness(h->magic);
	lc = p + sizeof(struct mach_header);
	ncmds = ndian_32(h->ncmds);
	while (safe(lc) && ncmds--)
	{
		if (ndian_32(lc->cmd) == LC_SEGMENT && segments(lc) < 0)
			return (-1);
		else if (ndian_32(lc->cmd) == LC_SYMTAB &&
				symbols((struct symtab_command *)lc, p) < 0)
			return (-1);
		lc = (void *)lc + ndian_32(lc->cmdsize);
	}
	if (!safe(lc))
		return (err(INV_OBJ, name(NULL)));
	return (0);
}
