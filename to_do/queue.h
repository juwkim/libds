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

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>
# include <stdbool.h>

# define QUEUE_SIZE 100

typedef int Data;
typedef struct
{
	int front;
	int	rear;
	Data items[QUEUE_SIZE];
} Queue;

// Make a queue empty.
void InitQueue(Queue* pqueue);

// Check whether a queue is full.
bool IsFull(Queue* pqueue);

// Check whether a queue is empty.
bool IsQEmpty(Queue* pqueue);

// Read the item at the front.
Data QPeek(Queue* pqueue);

// Insert an item at the rear.
void EnQueue(Queue* pqueue, Data item);

// Delete an item at the front.
void DeQueue(Queue* pqueue);

#endif
