/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:47:18 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/13 02:51:37 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include "ft_is.h"
# include "ft_memory.h"

char	*get_next_line(int fd);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s);

int		ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strnstr(const char *str, const char *to_find, int n);

int		ft_strfind(char c, const char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(const char *s, int c);

char	*ft_strtrim(char *s1, char *set);
void	ft_strreverse(char *begin, char *end);

char	*ft_substr(char const *s, int start, int len);

int		ft_strlen(const char *s);

int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
