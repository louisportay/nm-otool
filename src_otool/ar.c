/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ar.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 08:55:44 by lportay           #+#    #+#             */
/*   Updated: 2019/03/04 11:45:15 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void	print_filename(void)
{
	buf_s(get_buf(), "Archive : ");
	buf_s(get_buf(), name(NULL));
	buf_c(get_buf(), '\n');
}

static void	print_name(char *s)
{
	buf_s(get_buf(), name(NULL));
	buf_c(get_buf(), '(');
	buf_s(get_buf(), s);
	buf_s(get_buf(), "):\n");
}

/*
** This is historical hack you see
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
	print_filename();
	p += ft_atol(h->ar_size) + sizeof(struct ar_hdr);
	*(name_printed()) = 1;
	while (1)
	{
		h = (struct ar_hdr *)p;
		if (ft_atol(h->ar_size) == 0)
			return (0);
		if (!safe(p + ft_atol(h->ar_size) + sizeof(struct ar_hdr)))
			return (err(INV_OBJ, name(NULL)));
		s = p + sizeof(struct ar_hdr);
		print_name(s);
		placeholder1(p + sizeof(struct ar_hdr) + get_offset(s) - 1);
		p += ft_atol(h->ar_size) + sizeof(struct ar_hdr);
	}
	return (0);
}
