/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:40:35 by lportay           #+#    #+#             */
/*   Updated: 2019/02/13 13:04:44 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BYTES_H
# define BYTES_H

#include <stdint.h>

uint16_t bswap_16(uint16_t val);
uint32_t bswap_32(uint32_t val);
uint64_t bswap_64(uint64_t val);

#endif
