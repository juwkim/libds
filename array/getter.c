/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:36:45 by juwkim            #+#    #+#             */
/*   Updated: 2023/02/07 06:05:56 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_array_data	array_front(t_array *array)
{
	return (array_get_item(array, 0));
}

t_array_data	array_back(t_array *array)
{
	return (array_get_item(array, array->size - 1));
}

t_array_data	array_get_item(t_array *array, int pos)
{
	return (array->items[pos]);
}
