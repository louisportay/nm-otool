/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:07:43 by lportay           #+#    #+#             */
/*   Updated: 2019/02/06 13:56:36 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

#include <stdlib.h> // malloc, free

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <sys/mman.h>

#include <fcntl.h> // open
#include <unistd.h> // close, write

#include <sys/stat.h>// fstat

int	ft_nm(int ac, char **av,char **env);

#endif
