/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ar.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:04:34 by lportay           #+#    #+#             */
/*   Updated: 2019/04/10 17:41:46 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	print_ar_obj(char *ar_obj)
{
	buf_c(get_buf(), '\n');
	buf_s(get_buf(), ctx()->name);
	buf_c(get_buf(), '(');
	buf_s(get_buf(), ar_obj);
	buf_s(get_buf(), "):\n");
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
	p += ft_atoi(h->ar_size) + sizeof(struct ar_hdr);
	ctx()->ar = 1;
	ctx()->name_printed = 1;
	while (1)
	{
		h = (struct ar_hdr *)p;
		if (!safe(h->ar_size) || ft_atoi(h->ar_size) <= 0 ||
			!safe(p + ft_atoi(h->ar_size) + sizeof(struct ar_hdr)))
			return (0);
		s = p + sizeof(struct ar_hdr);
		print_ar_obj(s);
		placeholder1(p + sizeof(struct ar_hdr) + get_offset(s) - 1);
		p += ft_atoi(h->ar_size) + sizeof(struct ar_hdr);
	}
	return (0);
}
