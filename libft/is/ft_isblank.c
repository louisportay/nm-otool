/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:58:29 by lportay           #+#    #+#             */
/*   Updated: 2018/12/12 14:59:58 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is.h"

int	ft_isblank(int c)
{
	return (c == ' ' || c == '	');
}
