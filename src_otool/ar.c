/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ar.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 08:55:44 by lportay           #+#    #+#             */
/*   Updated: 2019/03/18 14:15:23 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void	print_filename(void)
{
	buf_s(get_buf(), "Archive : ");
	buf_s(get_buf(), ctx()->name);
	buf_c(get_buf(), '\n');
}

static void	print_ar_obj(char *s)
{
	buf_s(get_buf(), ctx()->name);
	buf_c(get_buf(), '(');
	buf_s(get_buf(), s);
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
	print_filename();
	ctx()->ar = 1;
	ctx()->name_printed = 1;
	while (1)
	{
		h = (struct ar_hdr *)p;
		if (ft_atoi(h->ar_size) == 0 ||
			!safe(p + ft_atoi(h->ar_size) + sizeof(struct ar_hdr)))
			return (0);
		s = p + sizeof(struct ar_hdr);
		print_ar_obj(s);
		placeholder1(p + sizeof(struct ar_hdr) + get_offset(s) - 1);
		p += ft_atoi(h->ar_size) + sizeof(struct ar_hdr);
	}
	return (0);
}
