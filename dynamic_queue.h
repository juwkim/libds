/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_queue.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:01 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:01 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_QUEUE_H
# define DYNAMIC_QUEUE_H

# include <stdlib.h>
# include <stdbool.h>

typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;

typedef struct
{
	Node* front;
	Node* rear;
} DQueue;

// Make a queue empty.
void InitQueue(DQueue* pqueue);

// Check whether a queue is empty.
bool IsEmpty(DQueue* pqueue);

// Read the item at the front.
Data Peek(DQueue* pqueue);

void EnQueue(DQueue* pqueue, Data item);

void DeQueue(DQueue* pqueue);

#endif
