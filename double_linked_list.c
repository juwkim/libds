/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:51 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:15:51 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_linked_list.h"

void InitList(DoubleLinkedList* plist)
{
	Node *dummy1 = (Node*) malloc(sizeof(Node));
	Node *dummy2 = (Node*) malloc(sizeof(Node));

	if (dummy1 == NULL || dummy2 == NULL)
		exit(EXIT_FAILURE);

	dummy1->prev = NULL;
	dummy1->next = dummy2;
	
	dummy2->prev = dummy1;
	dummy2->next = NULL;
	
	plist->head = dummy1;
	plist->len = 0;
}

void InsertMiddle(DoubleLinkedList* plist, int pos, Data item)
{
	// Create a new node.
	Node *newNode = (Node*) malloc(sizeof(Node));
	if (newNode == NULL)
		exit(EXIT_FAILURE);

	newNode->item = item;
	newNode->prev = NULL;
	newNode->next = NULL;

	// Move the cur pointer to the (pos - 1)-th position.
	Node *cur = plist->head;
	while (pos--)
		cur = cur->next;

	// Insert the new node to the pos-th position.
	newNode->prev = cur;
	newNode->next = cur->next;
	cur->next->prev = newNode;
	cur->next = newNode;
	plist->len++;
}

void RemoveMiddle(DoubleLinkedList* plist, int pos)
{
	if (plist->len == 0 || pos < 0 || pos >= plist->len)
		exit(EXIT_FAILURE);

	// Move the cur pointer to the (pos-1)-th position.
	Node *cur = plist->head;
	while (pos--)
		cur = cur->next;

	// Connect adjacent nodes to remove the pos-th node.
	Node *temp = cur->next;
	temp->next->prev = cur;
	cur->next = temp->next;

	// Remove the node to the pos-th position.
	plist->len--;
	free(temp);
}
