/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:57 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:57 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include <stdbool.h>

# include "max_heap.h"

# define MAX_SIZE 100000

typedef int	t_sort_data;

bool	less(t_sort_data a, t_sort_data b);
bool	greater(t_sort_data a, t_sort_data b);

// O(N ** 2)
void	selection_sort(t_sort_data *list, int n);
void	bubble_sort(t_sort_data *list, int n);
void	insertion_sort(t_sort_data *list, int n);

// O(N ** 1.5)
void	shell_sort(t_sort_data *list, int n);

// O(NlogN)
void	quick_sort(t_sort_data *list, int left, int right);
void	merge_sort(t_sort_data *list, int left, int right);
void	iter_merge_sort(t_sort_data *list, int n);
void	heap_sort(t_sort_data *list, int n);

// O(N)
void	counting_sort(t_sort_data *list, int n);
void	radix_sort(t_sort_data *list, int n);

#endif // SORTING_H
