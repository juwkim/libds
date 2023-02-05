/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:47:18 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/03 23:56:11 by juwkim           ###   ########.fr       */
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
void	ft_free_array(char **split);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);

int		ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, int n);

int		ft_strfind(const char *str, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(const char *s, int c);

char	*ft_strtrim(char *s1, char *set);
void	ft_strreverse(char *begin, char *end);

char	*ft_substr(char const *s, int start, int len);

int		ft_strlen(const char *s);

int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
