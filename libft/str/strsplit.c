/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:16:38 by lportay           #+#    #+#             */
/*   Updated: 2018/12/13 12:11:36 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

static void	str_nb(char const *s, int c, int *str_nb)
{
	int	prev_c;

	*str_nb = 0;
	prev_c = 0;
	while (*s)
	{
		if (*s == c)
			prev_c = 0;
		else if (prev_c == 0)
		{
			*str_nb += 1;
			prev_c = 1;
		}
		s++;
	}
}

static int	split(char const *s, char **str_tab, char c)
{
	char	*tmp;
	int		len;

	while (*s)
	{
		if (*s != c)
		{
			tmp = (char *)s;
			len = 0;
			while (*s != c && *s)
			{
				len++;
				s++;
			}
			if (!((*str_tab) = (char *)malloc(sizeof(char) * len + 1)))
				return (-1);
			ft_strncpy(*str_tab, tmp, len);
			(*str_tab)[len] = '\0';
			str_tab++;
		}
		else if (*s == c)
			s++;
	}
	return (0);
}

char		**strsplit(char const *s, char c)
{
	char	**str_tab;
	int		width;

	if (!s || !ft_isprint(c) || !ft_strlen(s) || stroccur(s, c) == ft_strlen(s))
		return (NULL);
	str_nb(s, c, &width);
	if (!(str_tab = (char **)array_new(width + 1)))
		return (NULL);
	array_clear((void **)str_tab, width + 1);
	if (split(s, str_tab, c) == -1)
	{
		array_destroy((void ***)&str_tab, width, &free);
		return (NULL);
	}
	return (str_tab);
}
