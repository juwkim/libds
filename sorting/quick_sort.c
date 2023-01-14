/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:51:31 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/14 17:02:32 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static int	partition(t_data *list, int left, int right)
{
	int				low;
	int				high;
	const t_data	pivot = list[left];

	low = left + 1;
	high = right;
	while (low < high)
	{
		while (low < right && list[low] < pivot)
			low++;
		while (high > left && list[high] >= pivot)
			high--;
		if (low < high)
			ft_swap(list + low, list + high);
	}
	ft_swap(list + left, list + high);
	return (high);
}

void	quick_sort(t_data *list, int left, int right)
{
	int	mid;

	if (left >= right)
		return ;
	mid = partition(list, left, right);
	quick_sort(list, left, mid - 1);
	quick_sort(list, mid + 1, right);
}
