/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:49:59 by lportay           #+#    #+#             */
/*   Updated: 2019/02/24 18:37:18 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUF_H
# define BUF_H

# include <wchar.h>
# include <unistd.h>
# include "is.h"
# include "bridge.h"

# define BUFF_SIZE 4096

typedef struct s_buffer	t_buf;

struct					s_buffer
{
	char				buf[BUFF_SIZE];
	size_t				written;
	unsigned char		fd;
};


struct s_bufopt
{
	enum		e_prefix p;
	enum		e_charset cs;
	unsigned	pad_amount;
	char		pad_char;
};

void					buf_init(t_buf *b, int fd);
size_t					buf_reset(t_buf *b);
void					buf_c(t_buf *b, char c);
void					buf_nc(t_buf *b, char c, unsigned n);
void					buf_s(t_buf *b, char *s);
void					buf_ns(t_buf *b, char *s, unsigned n);
int						buf_wc(t_buf *b, wchar_t wc);
void					buf_nwc(t_buf *b, wchar_t wc, unsigned n);
void					buf_ws(t_buf *b, wchar_t *ws);
void					buf_nws(t_buf *b, wchar_t *ws, unsigned n);
void					buf_ul(t_buf *b, unsigned long l);
void					buf_l(t_buf *b, long l);
void					buf_x(t_buf *b, unsigned long l, enum e_prefix p,
								enum e_charset c);
void					buf_b(t_buf *b, unsigned long l, enum e_prefix p);

void					buf_x_pad(t_buf *b, unsigned long l,
									struct s_bufopt bo);
void	buf_s_pad(t_buf *b, char *s, char pad_char, unsigned pad_amount);

#endif
