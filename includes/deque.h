/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:43 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:43 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stddef.h>
# include <stdbool.h>

# include "max_heap.h"
# include "binary_search_tree.h"

# define QUEUE_SIZE 3000

typedef int	t_dq_data;

typedef struct s_dq_node
{
	t_dq_data	item;
	int			rank;
}	t_dq_node;

typedef struct s_deque
{
	int			head;
	int			tail;
	t_dq_node	nodes[QUEUE_SIZE];
}	t_deque;

// utils.c
void		dq_init(t_deque *dq);
bool		dq_is_empty(t_deque *dq);
bool		dq_is_full(t_deque *dq);
size_t		dq_size(t_deque *dq);

// push.c
void		dq_push_front(t_deque *dq, t_dq_node node);
void		dq_push_back(t_deque *dq, t_dq_node node);

// pop.c
void		dq_pop_front(t_deque *dq);
void		dq_pop_back(t_deque *dq);

// getter.c
t_dq_node	dq_front(t_deque *dq);
t_dq_node	dq_back(t_deque *dq);

// operation.c
bool		dq_is_duplication(const t_deque *dq);
void		dq_set_rank(t_deque *a);
bool		dq_nsorted(t_deque *dq, size_t n, bool (*key)(int a, int b));

#endif // DEQUE_H
