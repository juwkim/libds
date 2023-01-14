/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:15:12 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 16:16:09 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "max_heap.h"

int	get_parent(int idx)
{
	return (idx >> 1);
}

int	get_left_child(int idx)
{
	return (idx << 1);
}

int	get_right_child(int idx)
{
	return ((idx << 1) + 1);
}

int	get_high_prioity_child(t_heap *heap, int idx)
{
	const int	left = get_left_child(idx);
	const int	right = get_right_child(idx);

	if (left > heap->size)
		return (0);
	else if (left == heap->size)
		return (left);
	else
	{
		if (heap->items[left].priority > heap->items[right].priority)
			return (left);
		else
			return (right);
	}
}
