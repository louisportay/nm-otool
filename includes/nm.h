/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:07:43 by lportay           #+#    #+#             */
/*   Updated: 2019/02/14 19:59:38 by lportay          ###   ########.fr       */
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

# define  INV_OBJ "The file was not recognized as a valid object file"

#define DEBUG printf("DEBUG\n");//

#define SYMLEN 255

# define TYPE(n) (n & N_TYPE)
# define EXT(n) (n & N_EXT)

typedef struct	s_sym
{
	char 		name[SYMLEN];
	uint64_t	value;
	uint8_t		type;
	uint8_t		sect;
}				t_sym;

int	ft_nm(uint32_t ac, char **av,char **env);

#endif
