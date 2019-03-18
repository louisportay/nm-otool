/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:07:43 by lportay           #+#    #+#             */
/*   Updated: 2019/03/18 15:29:50 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include <ar.h>
# include <mach-o/fat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# include "err.h"
# include "bytes.h"
# include "buf.h"
# include "str.h"
# include "maths.h"

# define ONE_FILE "%s: at least one file must be specified\n"
# define NOT_OBJ "%s: is not an object file\n"
# define INV_OBJ "%s: truncated or malformed object\n"

# define PPC_S		" (architecture ppc):\n"
# define PPC64_S	" (architecture ppc64):\n"
# define I386_S		" (architecture i386):\n"
# define X86_64_S	" (architecture x86_64):\n"

# define NOT_NATIVE (0)
# define NATIVE (1)

typedef struct	s_ctx
{
	t_buf		b;
	void		*max;
	char		*name;
	uint32_t	ac;
	uint8_t		ar;
	uint8_t		name_printed;
}				t_ctx;

int				ft_otool(uint32_t ac, char **av);

int32_t			f_64_bits(void *p);
int32_t			f_32_bits(void *p);
int32_t			fat_64(void *p);
int32_t			fat_32(void *p);
int32_t			f_archive(void *p);

int32_t			placeholder1(void *p);
int32_t			print_text(void *text, struct section_64 *sct64,
									struct section *sct);

t_ctx			*ctx(void);
t_buf			*get_buf(void);
uint32_t		hostarch(cpu_type_t type);
uint32_t		safe(void *pos);
uint32_t		endianness(uint32_t magic);
uint64_t		ndian_64(uint64_t n);
uint32_t		ndian_32(uint32_t n);
uint16_t		ndian_16(uint16_t n);

#endif
