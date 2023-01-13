/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SINGLE_LINKED_LIST
# define SINGLE_LINKED_LIST

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node *next;
} Node;

typedef struct
{
	Node *head;
	int len;
} LinkedList;

// Make a list empty.
void InitList(LinkedList* plist);

// Check whether the list is empty.
bool IsEmpty(LinkedList* plist);

// Insert an item at the pos-th position.
void InsertMiddle(LinkedList* plist, int pos, Data item);

// Remove an item at the pos-th position.
void RemoveMiddle(LinkedList* plist, int pos);

void RemoveFirst(LinkedList* plist);

// Read an item at the pos-th position.
Data ReadItem(LinkedList* plist, int pos);

// Print each item in a list in sequence.
void PrintList(LinkedList* plist);

// Remove all nodes in a list in sequence.
void ClearList(LinkedList* plist);

LinkedList* Concatenate(LinkedList* plist1, LinkedList* plist2);

// Make the list in reverse sequence.
void Reverse(LinkedList* plist);

#endif
