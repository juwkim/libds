/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:15:34 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:15:34 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_linked_list.h"

Node *CreateNode(Data item)
{
	Node* newNode = (Node*) malloc(sizeof(Node));
	if (newNode == NULL)
		exit(EXIT_FAILURE);

	newNode->item = item;
	return (newNode);
}

void InsertInitItem(CircularList* plist, Data item)
{
	Node *newNode = CreateNode(item);
	newNode->next = newNode;

	plist->tail = newNode;
	plist->len++;
}

void InsertFirst(CircularList* plist, Data item)
{
	if (plist->len == 0)
		InsertInitItem(plist, item);
	else
	{
		Node *newNode = CreateNode(item);
		newNode->next = plist->tail->next;

		// Connect the back node to the new node.
		plist->tail->next = newNode;
		plist->len++;
	}
}

void InsertLast(CircularList* plist, Data item)
{
	if (plist->len == 0)
		InsertInitItem(plist, item);
	else
	{
		Node *newNode = CreateNode(item);
		newNode->next = plist->tail->next;

		// Connect the back node to the new node.
		plist->tail->next = newNode;
		plist->tail = newNode;
		plist->len++;
	}
}

void InsertMiddle(CircularList* plist, int pos, Data item)
{
	if (plist->len == 0)
		InsertInitItem(plist, item);
	else
	{
		Node *cur = plist->tail;

		// moving (pos - 1)-th position
		while (pos--)
			cur = cur->next;

		Node *newNode = CreateNode(item);
		newNode->next = cur->next;

		// linking the current node to the new node
		cur->next = newNode;
		plist->len++;
	}
}

void RemoveInitItem(CircularList* plist)
{
	if (plist->len == 0)
		exit(EXIT_FAILURE);
	else if (plist->len == 1)
	{
		free(plist->tail);
		plist->len--;
		plist->tail = NULL;
	}
}

void RemoveFirst(CircularList* plist)
{
	if (plist->len == 1)
		RemoveInitItem(plist);
	else
	{
		Node* temp = plist->tail->next;
		plist->tail->next = temp->next;
		free(temp);
		plist->len--;
	}
}

void RemoveLast(CircularList* plist)
{
	if (plist->len == 1)
		RemoveInitItem(plist);
	else
	{
		Node *cur = plist->tail;
		for (int i = 0; i < plist->len - 1; ++i)
			cur = cur->next;

		Node *temp = cur->next;
		cur->next = temp->next;
		free(temp);

		plist->tail = cur;
		plist->len--;
	}
}

void RemoveMiddle(CircularList* plist, int pos)
{
	if (plist->len == 1)
		RemoveInitItem(plist);
	else
	{
		Node *cur = plist->tail;
		while (pos--)
			cur = cur->next;

		Node *temp = cur->next;
		cur->next = temp->next;
		free(temp);

		plist->len--;
	}
}
