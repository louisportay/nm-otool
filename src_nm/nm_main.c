/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:27:43 by lportay           #+#    #+#             */
/*   Updated: 2019/02/06 13:45:25 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	printf("NM\n");	
	return (ft_nm(ac, av, env));
}
