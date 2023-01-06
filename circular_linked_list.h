/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:44 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:15:44 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_LINKED_LIST_H
# define CIRCULAR_LINKED_LIST_H

# include <stdlib.h>

typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;

typedef struct
{
	Node* tail;
	int len;
} CircularList;

Node *CreateNode(Data item);
void InsertInitItem(CircularList* plist, Data item);
void InsertFirst(CircularList* plist, Data item);
void InsertLast(CircularList* plist, Data item);
void InsertMiddle(CircularList* plist, int pos, Data item);
void RemoveInitItem(CircularList* plist);
void RemoveFirst(CircularList* plist);
void RemoveLast(CircularList* plist);
void RemoveMiddle(CircularList* plist, int pos);

#endif
