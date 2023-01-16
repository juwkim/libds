/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:34:24 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/16 14:45:12 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "max_heap.h"

void	heap_init(t_heap *heap)
{
	heap->size = 0;
}

bool	heap_is_empty(t_heap *heap)
{
	return (heap->size == 0);
}

bool	heap_is_full(t_heap *heap)
{
	return (heap->size == HEAP_SIZE);
}
