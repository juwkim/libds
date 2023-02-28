/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:36:12 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 07:04:40 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	__swap(int *a, int *b)
{
	const int	tmp = *a;

	*a = *b;
	*b = tmp;
}

void	selection_sort(t_sort_data *list, int n)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < n - 1)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (list[j] < list[min])
				min = j;
			++j;
		}
		__swap(list + i, list + min);
		++i;
	}
}
