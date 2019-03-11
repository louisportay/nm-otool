/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:07:43 by lportay           #+#    #+#             */
/*   Updated: 2019/03/11 16:14:36 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <stdlib.h>
# include <ar.h>
# include <mach-o/fat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# include "err.h"
# include "bridge.h"
# include "is.h"
# include "mem.h"
# include "buf.h"
# include "bytes.h"
# include "str.h"

# define INV_OBJ "%s: The file was not recognized as a valid object file\n"
# define PPC_S		" (for architecture ppc):\n"
# define PPC64_S	" (for architecture ppc64):\n"
# define I386_S		" (for architecture i386):\n"
# define X86_64_S	" (for architecture x86_64):\n"

# define SYMLEN (255)
# define NOT_NATIVE (0)
# define NATIVE (1)
# define RESET (0)
# define GET (1)
# define SET (2)
# define ADD (3)

enum			e_section
{
	TEXT = 0,
	DATA = 1,
	BSS = 2,
	I = 3
};

/*
** Macros NOT IN USE
*/

# define TYPE(n) (n & N_TYPE)
# define EXT(n) (n & N_EXT)

typedef struct	s_sym
{
	char		*name;
	uint64_t	len;
	uint64_t	value;
	uint8_t		type;
	uint8_t		sect;
}				t_sym;

int				ft_nm(uint32_t ac, char **av);

int32_t			placeholder1(void *p);

int32_t			f_64_bits(void *p);
int32_t			f_32_bits(void *p);
int32_t			fat_64(void *p);
int32_t			fat_32(void *p);
int32_t			f_archive(void *p);

uint64_t		scts(int8_t action, enum e_section index, uint64_t value);
void			print_sym(t_sym s, uint8_t width);
void			sort_symbols(t_sym *list, uint32_t len);

char			*name(char *filename);
uint64_t		safe_len(char *name);
uint8_t			type(uint8_t t);
uint8_t			ext(uint8_t e);
t_buf			*get_buf(void);
void			*max(void *p, off_t size);
uint32_t		safe(void *pos);
int32_t			corrupt_bin(t_sym *list);
uint32_t		hostarch(cpu_type_t type);
uint32_t		endianness(uint32_t magic);
uint64_t		ndian_64(uint64_t n);
uint32_t		ndian_32(uint32_t n);
uint16_t		ndian_16(uint16_t n);
uint32_t		nb_args(uint32_t *ac);
void			print_name(char *path);
uint32_t		*name_printed(void);

#endif
