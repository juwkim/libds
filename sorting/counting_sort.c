/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:28:18 by juwkim            #+#    #+#             */
/*   Updated: 2023/03/01 07:00:10 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	counting_sort(t_sort_data *list, int n)
{
	int				i;
	t_sort_data		count[MAX_SIZE];
	t_sort_data		output[MAX_SIZE];

	i = -1;
	while (++i < MAX_SIZE)
		count[i] = 0;
	i = -1;
	while (++i < n)
		count[list[i]]++;
	i = -1;
	while (++i < MAX_SIZE - 1)
		count[i + 1] += count[i];
	i = -1;
	while (++i < n)
		output[count[list[i]]-- - 1] = list[i];
	i = -1;
	while (++i < n)
		list[i] = output[i];
}
