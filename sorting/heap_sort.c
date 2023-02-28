/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:23:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 07:19:55 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	heap_sort(t_sort_data *list, int n)
{
	t_heap	heap;
	int		i;

	heap_init(&heap);
	i = 0;
	while (i < n)
	{
		heap_insert(&heap, list[i], -list[i]);
		++i;
	}
	i = 0;
	while (i < n)
	{
		list[i] = heap_delete(&heap);
		++i;
	}
}
