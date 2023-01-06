/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:55 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:15:55 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LINKED_LIST_H
# define DOUBLE_LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* prev;
	struct _Node* next;
} Node;

typedef struct
{
	Node* head;
	int len;
} DoubleLinkedList;

void InitList(DoubleLinkedList* plist);
void InsertMiddle(DoubleLinkedList* plist, int pos, Data item);
void RemoveMiddle(DoubleLinkedList* plist, int pos);

#endif
