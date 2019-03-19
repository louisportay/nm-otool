/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:43:54 by lportay           #+#    #+#             */
/*   Updated: 2019/03/19 19:44:45 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

int32_t			placeholder1(void *p)
{
	uint64_t	magic;

	if (!safe(p))
		return (err(INV_OBJ, ctx()->name));
	magic = *(uint32_t *)p;
	if (safe(p + SARMAG) && !ft_memcmp(p, ARMAG, SARMAG))
		return (f_archive(p));
	else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		return (f_64_bits(p));
	else if (magic == MH_MAGIC || magic == MH_CIGAM)
		return (f_32_bits(p));
	else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		return (fat_64(p));
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		return (fat_32(p));
	else if (ctx()->ar == 1)
		return (0);
	else
		return (err(NOT_OBJ, ctx()->name));
}

static void		fail_munmap(void *p, int32_t *r)
{
	err("%p: failed to munmap file pointer\n", p);
	*r = -1;
}

static int32_t	run(char *exec, char *path)
{
	struct stat	st;
	void		*p;
	int32_t		fd;
	int32_t		r;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (err("%s: %s: open failed\n", exec, path));
	if (fstat(fd, &st) == -1)
		return (err("%s: %s: fstat failed\n", exec, path));
	if (S_ISDIR(st.st_mode))
		return (err("%s: %s: Is a directory\n", exec, path));
	if ((p = mmap(NULL, st.st_size, PROT_READ,
					MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (err("%s: %s: mmap failed\n", exec, path));
	ctx()->max = p + st.st_size;
	ctx()->name = path;
	ctx()->ar = 0;
	ctx()->name_printed = 0;
	r = placeholder1(p);
	if (munmap(p, st.st_size) == -1)
		fail_munmap(p, &r);
	if (close(fd) == -1)
		return (err("%i: failed to close fd\n", fd));
	return (r);
}

int				ft_otool(uint32_t ac, char **av)
{
	uint32_t	u;
	int32_t		r;
	int32_t		tmp_r;

	buf_init(get_buf(), STDOUT_FILENO);
	if (ac < 2)
		return (err(ONE_FILE, av[0]));
	else
	{
		u = 1;
		r = 0;
		ctx()->ac = ac;
		while (u < ac)
		{
			tmp_r = run(av[0], av[u]);
			if (tmp_r < r)
				r = tmp_r;
			u++;
		}
	}
	buf_reset(get_buf());
	return (r);
}
