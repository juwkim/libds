/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:21:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 06:58:58 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

bool	less(t_sort_data a, t_sort_data b)
{
	return (a < b);
}

bool	greater(t_sort_data a, t_sort_data b)
{
	return (a > b);
}
