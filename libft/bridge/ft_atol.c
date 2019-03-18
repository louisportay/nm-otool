/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:14:40 by lportay           #+#    #+#             */
/*   Updated: 2019/03/13 11:14:35 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bridge.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	nb;

	nb = 0;
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
		nb = (nb * 10) + *str++ - '0';
	return (sign * nb);
}

int		ft_atoi(const char *str)
{
	int		sign;
	int		nb;

	nb = 0;
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && (*str >= '0' && *str <= '9'))
		nb = (nb * 10) + *str++ - '0';
	return (sign * nb);
}
