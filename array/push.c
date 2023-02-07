/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:41:27 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 06:05:46 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_push_front(t_array *array, t_array_data item)
{
	array_insert(array, 0, item);
}

void	array_push_back(t_array *array, t_array_data item)
{
	array->items[array->size++] = item;
}

void	array_insert(t_array *array, int pos, t_array_data item)
{
	int	i;

	i = array->size - 1;
	while (i >= pos)
	{
		array->items[i + 1] = array->items[i];
		--i;
	}
	array->items[pos] = item;
	++array->size;
}
