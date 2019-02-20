/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lportay <lportay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:57:13 by lportay           #+#    #+#             */
/*   Updated: 2019/02/19 13:07:36 by lportay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdlib.h>
# include "array.h"
# include "is.h"

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strstr(const char *haystack, const char *needle);
void	strdel(char **as);
char	*strnew(size_t size);
char	**strsplit(char const *s, char c);
int		strequ(char const *s1, char const *s2);
int		strnequ(char const *s1, char const *s2, size_t n);
size_t	stroccur(const char *s, char c);
char	*strjoin(char const *s1, char const *s2);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		strchri(const char *s, char c);
int		strrchri(const char *s, int c);

/*
** Aliases
*/

int		scmp(const char *s1, const char *s2);
int		sncmp(const char *s1, const char *s2, size_t n);
size_t	slen(const char *s);
char	*scpy(char *dst, const char *src);
char	*sncpy(char *dst, const char *src, size_t len);

#endif
