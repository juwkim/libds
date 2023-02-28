/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:54 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:54 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

static void	sort_gap_insertion(t_sort_data *list, int first, int last, int gap)
{
	int	i;
	int	j;
	int	key;

	i = first + gap;
	while (i <= last)
	{
		key = list[i];
		j = i - gap;
		while (j >= first && key < list[j])
		{
			list[j + gap] = list[j];
			j -= gap;
		}
		list[j + gap] = key;
		i += gap;
	}
}

void	shell_sort(t_sort_data *list, int n)
{
	int	i;
	int	gap;

	gap = n >> 1;
	while (gap)
	{
		i = 0;
		while (i < gap)
		{
			sort_gap_insertion(list, i, n - 1, gap);
			++i;
		}
		gap >>= 1;
	}
}
