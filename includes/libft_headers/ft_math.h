/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:01:44 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/09 12:22:59 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "ft_is.h"
# include "ft_memory.h"

# define INT_LEN 11

int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_median(int a, int b, int c);
int		ft_abs(int a);

int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif
