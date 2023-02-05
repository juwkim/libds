/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:17:32 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/27 02:29:42 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include <stdlib.h>

void	ft_memset(void *ptr, unsigned char c, int n);
void	ft_bzero(void *ptr, int n);
void	*ft_calloc(int nmemb, int size);

char	*ft_memchr(char *s, char c, int n);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_memmove(char *dst, char *src, int len);
int		ft_memcmp(const char *s1, const char *s2, int n);

#endif
