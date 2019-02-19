/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:43:03 by lportay           #+#    #+#             */
/*   Updated: 2019/02/19 19:08:54 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t	placeholder1(void *p)
{
	uint64_t magic;

	magic = *(uint32_t *)p;
	scts(RESET, 0, 0);
	if (safe(p + SARMAG) && !ft_memcmp(p, ARMAG, SARMAG))
		//archive(p)
		printf("Archive\n");

	else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
		f_64_bits(p);

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

int32_t	run(char *exec, char *path, uint32_t ac)
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
		buf_c(get_buf(), '\n');
		buf_s(get_buf(), path);
		buf_s(get_buf(), ":\n");
	}

	r = placeholder1(p);

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
