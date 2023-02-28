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

# define HEAP_SIZE 100000

typedef int	t_heap_data;

typedef struct s_heap_node
{
	int			priority;
	t_heap_data	data;
}	t_heap_node;

typedef struct s_heap
{
	int			size;
	t_heap_node	items[HEAP_SIZE + 1];
}	t_heap;

// utils.c
void		heap_init(t_heap *heap);
bool		heap_is_empty(t_heap *heap);
bool		heap_is_full(t_heap *heap);

// max_heap.c
void		heap_insert(t_heap *heap, t_heap_data data, int priority);
t_heap_data	heap_delete(t_heap *heap);

// getter.c
int			__heap_get_parent(int idx);
int			__heap_get_higher_prioity_child(t_heap *heap, int idx);

#endif // MAX_HEAP_H
