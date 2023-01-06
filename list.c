/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:16:19 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:16:20 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void InitList(ArrayList* plist)
{
	plist->len = 0;
}

bool IsEmpty(ArrayList* plist)
{
	return plist->len == 0;
}

bool IsFull(ArrayList* plist)
{
	return plist->len == LIST_SIZE;
}

void InsertMiddle(ArrayList* plist, int pos, Data item)
{
	if (IsFull(plist) || pos < 0 || pos > plist->len)
		exit(EXIT_FAILURE);
	for (int i = plist->len - 1; i >= pos; --i)
		plist->items[i + 1] = plist->items[i];
	plist->items[pos] = item;
	plist->len++;
}

void RemoveMiddle(ArrayList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(EXIT_FAILURE);
	for (int i = pos; i < plist->len; ++i)
		plist->items[i] = plist->items[i + 1];
	plist->len--;
}

Data ReadItem(ArrayList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(EXIT_FAILURE);
	return plist->items[pos];
}

void PrintList(ArrayList* plist)
{
	for (int i = 0; i < plist->len; ++i)
		printf("%d\n", plist->items[i]);
}
