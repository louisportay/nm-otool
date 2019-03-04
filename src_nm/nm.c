/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:43:03 by lportay           #+#    #+#             */
/*   Updated: 2019/03/04 11:34:49 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t		placeholder1(void *p)
{
	uint64_t	magic;

	magic = *(uint32_t *)p;
	scts(RESET, 0, 0);
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
	else
		return (err(INV_OBJ, name(NULL)));
}

static void	print_name(char *path)
{
	buf_c(get_buf(), '\n');
	buf_s(get_buf(), path);
	buf_s(get_buf(), ":\n");
}

static void	fail_munmap(void *p, int32_t *r)
{
	err("%p: failed to munmap file pointer\n", p);
	*r = -1;
}

int32_t		run(char *exec, char *path, uint32_t ac)
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
	if (ac > 2)
		print_name(path);
	max(p, st.st_size);
	name(path);
	r = placeholder1(p);
	if (munmap(p, st.st_size) == -1)
		fail_munmap(p, &r);
	if (close(fd) == -1)
		return (err("%i: failed to close fd\n", fd));
	return (r);
}

int			ft_nm(uint32_t ac, char **av)
{
	uint32_t	u;
	int32_t		r;
	int32_t		tmp_r;

	buf_init(get_buf(), STDOUT_FILENO);
	if (ac < 2)
		r = run(av[0], "a.out", 1);
	else
	{
		u = 1;
		r = 0;
		while (u < ac)
		{
			tmp_r = run(av[0], av[u], ac);
			if (tmp_r < r)
				r = tmp_r;
			u++;
		}
	}
	buf_reset(get_buf());
	return (r);
}
