/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:48:26 by lportay           #+#    #+#             */
/*   Updated: 2018/12/13 13:20:51 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void	strdel(char **s)
{
	free(*s);
	*s = NULL;
}