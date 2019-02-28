/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:48:42 by lportay           #+#    #+#             */
/*   Updated: 2019/02/28 14:10:28 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRIDGE_H
# define BRIDGE_H

# include <stdlib.h>
# include "is.h"
# include "mem.h"

enum		e_prefix
{
	NO_PREFIX,
	PREFIX
};

enum		e_charset
{
	LOWER,
	UPPER
};

long		ft_atol(const char *nptr);
char		*ultoa(unsigned long n);
char		*ultoa_buf(long n, char *buf);
char		*ltoa(long n);
char		*ltoa_buf(long n, char *buf);
char		*ltox(unsigned long n);
char		*ltox_buf(unsigned long n, char *buf, enum e_prefix p,
						enum e_charset c);
char		*ltob(unsigned long n);
char		*ltob_buf(unsigned long n, char *buf, enum e_prefix p);
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
