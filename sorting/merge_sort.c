/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:02:46 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 07:01:15 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	merge(t_sort_data *list, int left, int mid, int right)
{
	int	sorted[MAX_SIZE];
	int	first;
	int	second;
	int	i;

	first = left;
	second = mid + 1;
	i = left;
	while (first <= mid && second <= right)
	{
		if (list[first] <= list[second])
			sorted[i++] = list[first++];
		else
			sorted[i++] = list[second++];
	}
	if (first <= mid)
		while (first <= mid)
			sorted[i++] = list[first++];
	else
		while (second <= right)
			sorted[i++] = list[second++];
	i = left;
	while (i <= right)
		list[i] = sorted[i];
}

void	merge_sort(t_sort_data *list, int left, int right)
{
	int	mid;

	if (left >= right)
		return ;
	mid = (left + right) / 2;
	merge_sort(list, left, mid - 1);
	merge_sort(list, mid + 1, right);
	merge(list, left, mid, right);
}

void	iter_merge_sort(t_sort_data *list, int n)
{
	int	size;
	int	left;
	int	mid;
	int	right;

	size = 1;
	while (size <= n - 1)
	{
		left = 0;
		while (left < n - 1)
		{
			mid = left + size - 1;
			if (left + 2 * size - 1 > n - 1)
				right = n - 1;
			else
				right = left + 2 * size - 1;
			merge(list, left, mid, right);
			left += 2 * size;
		}
		size <<= 1;
	}
}
