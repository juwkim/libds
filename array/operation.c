/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:46 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 05:53:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_print(t_array *array)
{
	size_t	cur;

	cur = 0;
	while (cur < array->size)
		printf("%s\n", (char *) array->items[cur++]);
}

void	array_reverse(t_array *array)
{
	size_t			left;
	size_t			right;
	t_array_data	temp;

	left = 0;
	right = array->size - 1;
	while (left < right)
	{
		temp = array->items[left];
		array->items[left] = array->items[right];
		array->items[right] = temp;
		++left;
		--right;
	}
}

t_array	*array_concatenate(t_array *array1, t_array *array2)
{
	t_array *const	array = (t_array *) malloc(sizeof(t_array));
	size_t			cur;

	assert(array != NULL);
	array_init(array);
	cur = 0;
	while (cur < array1->size)
		array_push_back(array, array1->items[cur++]);
	cur = 0;
	while (cur < array2->size)
		array_push_back(array, array2->items[cur++]);
	return (array);
}
