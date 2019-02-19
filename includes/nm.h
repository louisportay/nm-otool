/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:07:43 by lportay           #+#    #+#             */
/*   Updated: 2019/02/19 19:09:54 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <stdlib.h> // malloc, free

# include <ar.h>
# include <mach-o/fat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <sys/mman.h>

# include <fcntl.h> // open
# include <unistd.h> // close, write

# include <sys/stat.h>// fstat

# include "err.h"
# include "bridge.h"
# include "is.h"
# include "mem.h"
# include "buf.h"
# include "bytes.h"
# include "str.h"

# define  INV_OBJ "The file was not recognized as a valid object file\n"

# define DEBUG printf("DEBUG\n");//

# define SYMLEN (255)

# define NOT_NATIVE (0)
# define NATIVE (1)

# define RESET (0)
# define GET (1)
# define SET (2)

enum e_section
{
	TEXT = 0,
	DATA = 1,
	BSS = 2		
};

/*
** Macros NOT IN USE
*/

# define TYPE(n) (n & N_TYPE)
# define EXT(n) (n & N_EXT)

typedef struct	s_sym
{
	char 		name[SYMLEN];
	uint64_t	value;
	uint8_t		type;
	uint8_t		sect;
}				t_sym;

int				ft_nm(uint32_t ac, char **av,char **env);
int32_t			f_64_bits(void *p);

uint64_t		scts(int8_t action, enum e_section index, uint64_t value);
int32_t			print_sym(t_sym s);
void			sort_symbols(t_sym *list, uint32_t len);


uint8_t			type(uint8_t t);
uint8_t			ext(uint8_t e);
t_buf			*get_buf(void);
void			*max(void *p, off_t size);
uint32_t		safe(void *pos);
uint32_t		endianness(uint32_t magic);
uint64_t		ndian_64(uint64_t n);
uint32_t		ndian_32(uint32_t n);

#endif
