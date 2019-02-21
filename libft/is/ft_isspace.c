/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:26:49 by lportay           #+#    #+#             */
/*   Updated: 2018/12/12 15:30:52 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\f' || c == '\r' || c == '\v');
}
