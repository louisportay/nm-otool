/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:16:55 by lportay           #+#    #+#             */
/*   Updated: 2018/12/11 17:41:48 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/*
**  renvoie un pointeur vers le premier caractere 'c' trouvé sinon renvoie NULL
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}

/*
**  renvoie un pointeur vers le dernier caractere 'c' trouvé sinon renvoie NULL
*/

char	*ft_strrchr(const char *s, int c)
{
	char *iter;

	iter = (char *)s + ft_strlen(s);
	while (*iter != c && iter != s)
		iter--;
	if (*iter == c)
		return (iter);
	else
		return (NULL);
}
