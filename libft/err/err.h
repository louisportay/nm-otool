/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:48:42 by lportay           #+#    #+#             */
/*   Updated: 2019/02/11 19:03:36 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_H
# define ERR_H

/*
** Accepted flags includes
**
** %s : str
** %S : wide str
** %u : uint64_t
** %i : int64_t
*/

# include <stdarg.h>
# include "buf.h"

int32_t	err(const char *format, ...);

#endif
