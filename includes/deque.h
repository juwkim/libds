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

# define QUEUE_SIZE 3000

typedef int	t_data;

typedef struct s_deque
{
	int		head;
	int		tail;
	size_t	size;
	t_data	items[QUEUE_SIZE];
}	t_deque;

// utils.c
void	dq_init(t_deque *dq);
bool	is_empty(t_deque *dq);
bool	is_full(t_deque *dq);
size_t	size(t_deque *dq);

// push.c
void	push_front(t_deque *dq, t_data item);
void	push_back(t_deque *dq, t_data item);

// pop.c
void	pop_front(t_deque *dq);
void	pop_back(t_deque *dq);

// getter.c
t_data	front(t_deque *dq);
t_data	back(t_deque *dq);

#endif // DEQUE_H
