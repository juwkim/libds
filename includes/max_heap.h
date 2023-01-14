/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_heap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:28 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:28 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_HEAP_H
# define MAX_HEAP_H

# include <stdlib.h>
# include <stdbool.h>

# define HEAP_SIZE 100

typedef int	t_data;

typedef struct s_node
{
	t_data	data;
	int		priority;
}	t_node;

typedef struct s_heap
{
	int		size;
	t_node	items[HEAP_SIZE + 1];
}	t_heap;

// utils.c
void	heap_init(t_heap *heap);
bool	is_empty(t_heap *heap);
bool	is_full(t_heap *heap);

// max_heap.c
void	heap_insert(t_heap *heap, t_data data, int priority);
t_data	heap_delete(t_heap *heap);

// getter.c
int		get_parent(int idx);
int		get_left_child(int idx);
int		get_right_child(int idx);
int		get_high_prioity_child(t_heap *heap, int idx);

#endif // MAX_HEAP_H
