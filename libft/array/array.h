/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:02:25 by lportay           #+#    #+#             */
/*   Updated: 2019/02/21 13:42:42 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>
# include "bridge.h"

void	array_clear(void **a, size_t len);
void	array_destroy(void ***a, size_t len, void (*del)(void *));
void	**array_new(size_t len);
void	**array_w_new(size_t height, size_t width);
void	**array_dup(void **a, size_t len, void *(*dup)(void *),
					void (*del)(void *));
size_t	array_len(void **a);
void	array_map(void **a, size_t len, void (*fn)(void *));
void	array_print(void **a, size_t len, void (*print)(void *));

/*
** void	ft_qsort(void **base, size_t nel, size_t width,
** int (*cmp)(const void *, const void *));
*/

#endif
