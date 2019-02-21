/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:56:25 by lportay           #+#    #+#             */
/*   Updated: 2018/12/12 14:59:49 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
