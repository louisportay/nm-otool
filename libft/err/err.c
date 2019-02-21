/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:02:37 by lportay           #+#    #+#             */
/*   Updated: 2019/02/20 20:39:41 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err.h"

static void	get_arg(t_buf *b, va_list *ap, const char **fmt)
{
	(*fmt)++;
	if (**fmt == '\0')
		return ;
	else if (**fmt == '%')
		buf_c(b, '%');
	else if (**fmt == 's')
		buf_s(b, va_arg(*ap, char *));
	else if (**fmt == 'S')
		buf_ws(b, va_arg(*ap, wchar_t *));
	else if (**fmt == 'u')
		buf_ul(b, va_arg(*ap, unsigned long));
	else if (**fmt == 'p')
		buf_x(b, va_arg(*ap, unsigned long), PREFIX, UPPER);
	else if (**fmt == 'i')
		buf_l(b, va_arg(*ap, long));
	(*fmt)++;
}

int32_t		err(const char *fmt, ...)
{
	t_buf buf;
	va_list ap;

	buf_init(&buf, STDERR_FILENO);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			get_arg(&buf, &ap, &fmt);
		else
			buf_c(&buf, *fmt++);
	}
	va_end(ap);
	buf_reset(&buf);
	return (-1);
}
