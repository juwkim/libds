/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:51:16 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 06:05:52 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_pop_front(t_array *array)
{
	array_erase(array, 0);
}

void	array_pop_back(t_array *array)
{
	array_erase(array, array->size - 1);
}

void	array_erase(t_array *array, int pos)
{
	size_t	i;

	i = pos;
	while (i < array->size - 1)
	{
		array->items[i] = array->items[i + 1];
		++i;
	}
	--array->size;
}
