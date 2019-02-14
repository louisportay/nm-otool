/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:43:03 by lportay           #+#    #+#             */
/*   Updated: 2019/02/14 20:05:14 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

#define RESET (-2)
#define GET (-1)
#define TEXT (0)
#define DATA (1)
#define BSS (2)
#define COMMON (3)

uint64_t	*sections(int8_t index, uint64_t value)
{
	static uint64_t sct[4] = {0, 0, 0, 0};
	if (index == RESET)
	{
		sct[TEXT] = 0;
		sct[DATA] = 0;
		sct[BSS] = 0;
		sct[COMMON] = 0;
	}
	if (index > 0)
		sct[index] = value;

	return (sct);
}


void	*max(void *p, off_t size)
{
	static void *m;

	if (m == 0)
		m = p + size;
	return (m);
}

uint32_t	safe(void *pos)
{
	return (max(NULL, 0) >= pos);
}

#define NOT_NATIVE (0)
#define NATIVE (1)

uint32_t	endianness(uint32_t magic)
{
	static uint32_t endian;

	if (magic)
			endian = (magic == MH_MAGIC_64 || magic == MH_MAGIC
						|| magic == FAT_MAGIC_64 || magic == FAT_MAGIC);
	return (endian);
}

uint64_t	ndian_64(uint64_t n)
{
	return ((endianness(0) ==  NATIVE) ? n : bswap_64(n));
}

uint32_t	ndian_32(uint32_t n)
{
	return ((endianness(0) ==  NATIVE) ? n : bswap_32(n));
}

/*
** The first load command is just after the header
** Refer yourself to the scheme
*/

int32_t	segments_64(void *p)
{	
	static uint32_t				total_sct = 0;
	struct segment_command_64	*segment;
	struct section_64			*sct;
	uint32_t					nsects;

	if (!safe(p + sizeof(struct segment_command_64)))
		return (err(INV_OBJ));

	segment = (struct segment_command_64 *)p;
	sct = (struct section_64 *)(p + sizeof(struct segment_command_64));
	nsects = ndian_32(segment->nsects);
	while (safe(sct) && nsects--)
	{
		if (!sncmp(sct->segname, SEG_TEXT, 16) && !sncmp(sct->sectname, SECT_TEXT, 16))	
			sections(TEXT, ndian_32(segment->nsects) - nsects + total_sct);
		else if (!sncmp(sct->segname, SEG_DATA, 16) && !sncmp(sct->sectname, SECT_DATA, 16))
			sections(DATA, ndian_32(segment->nsects) - nsects + total_sct);
		else if (!sncmp(sct->segname, SEG_DATA, 16) && !sncmp(sct->sectname, SECT_BSS, 16))
			sections(BSS, ndian_32(segment->nsects) - nsects + total_sct);
	//	else if (/*!sncmp(sct->segname, SEG_DATA, 16) &&*/ !sncmp(sct->sectname, SECT_COMMON, 16))
	//		sections(COMMON, ndian_32(segment->nsects) - nsects + total_sct);
		sct++;
	}
	if (!safe(sct))
		return (err(INV_OBJ));
	total_sct += ndian_32(segment->nsects);
	return (0);
}

int32_t	print_sym(t_sym s, t_buf *b)
{
	(void)b;
	if (slen(s.name) == 0)
		return (0);
	return (0);
}

/*
** We allocate only to sort the symbols
*/

// maybe do the 'p' option

#define NOMEM -2

int32_t	symbols_64(void *p, t_buf *b)
{	
	struct symtab_command	*sym;
	struct nlist_64			*symtable;
	char					*strtable;
	uint32_t				nsyms;
	t_sym					*list;

	if (!safe(p + sizeof(struct symtab_command)))
		return (err(INV_OBJ));
	sym = (struct symtab_command *)p;
	nsyms = ndian_32(sym->nsyms);
	strtable = p + ndian_32(sym->stroff);
	symtable = p + ndian_32(sym->symoff);
	if (!safe(strtable) || !safe(symtable + (nsyms * sizeof(struct nlist_64))))
		return (err(INV_OBJ));
	if ((list = malloc(sizeof(t_sym) * nsyms)) == NULL)
		return (err("Cannot allocate Memory"));
	while (nsyms--)
	{
		ft_strncpy(list[nsyms].name, strtable + ndian_32(symtable[nsyms].n_un.n_strx), SYMLEN);
		list[nsyms].value = symtable[nsyms].n_value;
		list[nsyms].type = symtable[nsyms].n_type;
		list[nsyms].sect = symtable[nsyms].n_sect;	
	}
	//sort
	while (nsyms < ndian_32(sym->nsyms))
		print_sym(list[nsyms++], b);
	free(list);
	return (0);
}

int32_t	f_64_bits(void *p, t_buf *b)
{
	(void)b;//
	
	struct mach_header_64	*h;
	struct load_command		*lc;
	uint32_t				ncmds;

	if (!safe(p + sizeof(struct mach_header_64)))
		return (err(INV_OBJ));

	h = (struct mach_header_64 *)p;
	endianness(h->magic);
	lc = p + sizeof(struct mach_header_64);
	ncmds = ndian_32(h->ncmds);
	while (safe(lc) && ncmds--)
	{
		if (ndian_32(lc->cmd) == LC_SEGMENT_64 && segments_64(lc) < 0)
			return (-1);
		else if (ndian_32(lc->cmd) == LC_SYMTAB && symbols_64(lc, b) < 0)
			return (-1);
		lc = (void *)lc + ndian_32(lc->cmdsize);
	}
	if (!safe(lc))
		return (err(INV_OBJ));

	return (0);
}




int32_t	placeholder1(void *p, t_buf *b)
{
	uint64_t magic;

	magic = *(uint32_t *)p;
	sections(RESET, 0);
	if (safe(p + SARMAG) && !ft_memcmp(p, ARMAG, SARMAG))
		//archive(p)
		printf("Archive\n");

	else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		f_64_bits(p, b);

	else if (magic == MH_MAGIC || magic == MH_CIGAM)
		//32_bits(p);
		printf("binaire 32 bits\n");

	else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		//fat_64_bits(p);
		printf("binaire universel 64 bits\n");

	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)	
		//fat_32_bits(p);
		printf("binaire universel 32 bits\n");
	else
		return (err(INV_OBJ));

	return (0);//
}

int32_t	run(char *exec, char *path, uint32_t ac, t_buf *b)
{
	struct stat	st;
	void		*p;
	int32_t 	fd;
	int32_t		r;

	if ((fd = open(path, O_RDONLY)) == -1)
		return(err("%s: %s: open failed\n", exec, path));
	if (fstat(fd, &st) == -1)
		return (err("%s: %s: fstat failed", exec, path));
	if (S_ISDIR(st.st_mode))
		return (err("%s: %s: Is a directory", exec, path));
	if ((p = mmap(NULL, st.st_size, PROT_READ,
					MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (err("%s: %s: mmap failed", exec, path));

	max(p, st.st_size); //Set the address max where you can have

	if (ac > 2)
	{
		buf_c(b, '\n');
		buf_s(b, path);
		buf_s(b, ":\n");
	}

	r = placeholder1(p, b);

	if (munmap(p, st.st_size) == -1)
	{
		err("%p: failed to munmap file pointer\n", p);
		r = -1;
	}
	if (close(fd) == -1)
		return (err("%i: failed to close fd\n", fd));
	return (0);
}

int			ft_nm(uint32_t ac, char **av, char **env)
{
	(void)		env;
	uint32_t	u;
	int32_t		r;
	int32_t		tmp_r;
	t_buf		buf;

	buf_init(&buf, STDOUT_FILENO);
	if (ac < 2)
		r = run(av[0], "a.out", 1, &buf);
	else
	{
		u = 1;
		r = 0;
		while (u < ac)
		{
			tmp_r = run(av[0], av[u], ac, &buf);
			if (tmp_r < r)
				r = tmp_r;
			u++;
		}
	}
	buf_reset(&buf);
	return (r);
}
