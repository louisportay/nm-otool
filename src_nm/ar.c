/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ar.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:04:34 by lportay           #+#    #+#             */
/*   Updated: 2019/03/11 16:18:53 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	print_name_ar(char *s)
{
	buf_c(get_buf(), '\n');
	buf_s(get_buf(), name(NULL));
	buf_c(get_buf(), '(');
	buf_s(get_buf(), s);
	buf_s(get_buf(), "):\n");
	*name_printed() = 1;
}

/*
** This is historical hack to skip padding you see
*/

static int	get_offset(char *s)
{
	size_t			l;

	l = ft_strlen(s);
	while (!s[l++])
		;
	return (l);
}

int32_t		f_archive(void *p)
{
	struct ar_hdr	*h;
	char			*s;

	p += SARMAG;
	h = (struct ar_hdr *)p;
	if (ft_atol(h->ar_size) == 0)
		return (0);
	if (!safe(p + ft_atol(h->ar_size) + sizeof(struct ar_hdr)))
		return (err(INV_OBJ, name(NULL)));
	p += ft_atol(h->ar_size) + sizeof(struct ar_hdr);
	while (1)
	{
		h = (struct ar_hdr *)p;
		if (ft_atol(h->ar_size) == 0)
			return (0);
		s = p + sizeof(struct ar_hdr);
		print_name_ar(s);
		placeholder1(p + sizeof(struct ar_hdr) + get_offset(s) - 1);
		p += ft_atol(h->ar_size) + sizeof(struct ar_hdr);
	}
	return (0);
}
