/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:48:42 by lportay           #+#    #+#             */
/*   Updated: 2019/02/20 22:53:07 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRIDGE_H
# define BRIDGE_H

# include <stdlib.h>
# include "is.h"
# include "mem.h"

# define NO_PREFIX 0
# define PREFIX 1

# define LOWER 0
# define UPPER 1

long		ft_atol(const char *nptr);
char		*ultoa(unsigned long n);
char		*ultoa_buf(long n, char *buf);
char		*ltoa(long n);
char		*ltoa_buf(long n, char *buf);
char		*ltox(unsigned long n);
char		*ltox_buf(unsigned long n, char *buf, int prefix, int _case);
char		*ltob(unsigned long n);
char		*ltob_buf(unsigned long n, char *buf, int prefix);
unsigned	uwidth(unsigned long nb);
unsigned	lwidth(long nb);
long		ft_abs(long n);
void		lswap(long *a, long *b);
void		iswap(int *a, int *b);
unsigned	base_width(size_t nb, unsigned char base);

/*
** int		vswap(void *a, void *b, size_t size);
** void		swap(void *a, void *b, size_t size);
**
** # include "list.h"
**
** --> list_from_array
*/

#endif
