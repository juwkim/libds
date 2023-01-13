/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_queue.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIORITY_QUEUE_H
# define PRIORITY_QUEUE_H

# include <stdio.h>
# include <stdbool.h>

# include "max_heap.h"

typedef Heap PQueue;

void InitPQueue(PQueue* ppqueue);

bool IsPQEmpty(PQueue* ppqueue);
bool IsPQFull(PQueue* ppqueue);

void Enqueue(PQueue* ppqueue, Data data, int priority);
Data Dequeue(PQueue* ppqueue);

void HeapSort(Data a[], int n);

#endif
