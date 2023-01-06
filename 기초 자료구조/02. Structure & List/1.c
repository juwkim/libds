/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:30 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:30 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node);
void remove_node(ListNode** phead, ListNode* p, ListNode* removed);
void display(ListNode* head);
void display_recur(ListNode* head);
ListNode* search(ListNode* head, element x);
ListNode* concat(ListNode* head1, ListNode* head2);
ListNode* reverse(ListNode* head);
ListNode* create_node(element data, ListNode* link);



int main(void)
{
	ListNode* list1 = NULL;
	ListNode* list2 = NULL;

	ListNode* p = NULL;


	//list1에 10, 20, 30 추가
    insert_node(&list1, NULL, create_node(10, NULL));
    insert_node(&list1, NULL, create_node(20, NULL));
    insert_node(&list1, NULL, create_node(30, NULL));
	display(list1);

	// list1에서 첫번째 노드 제거
    remove_node(&list1, NULL, list1);
	display(list1);

	// list2에 60, 70, 80 추가
    insert_node(&list2, NULL, create_node(60, NULL));
    insert_node(&list2, NULL, create_node(70, NULL));
    insert_node(&list2, NULL, create_node(80, NULL));
	display(list2);

	// list2 = list2 + list1
    list2 = concat(list2, list1);
	display(list2);


	// list2를 역순으로 
    list2 = reverse(list2);
	display(list2);


	// list1에서 20 탐색
    p = search(list1, 20);
	printf("탐색 성공: %d\n", p->data);

	return 0;
}


// phead: 리스트의 헤드 포인터의 포인터
// p : 선행 노드
// new_node : 삽입될 노드 
void insert_node(ListNode** phead, ListNode* p,
	ListNode* new_node)
{
	if (*phead == NULL) {	// 공백리스트인 경우
        new_node->link = NULL;
        *phead = new_node;
	}
	else if (p == NULL) { // p가 NULL이면 첫번째 노드로 삽입
        new_node->link = *phead;
        *phead = new_node;
	}
	else {			 // p 다음에 삽입
        new_node->link = p->link;
        p->link = new_node;
	}
}
// phead : 헤드 포인터에 대한 포인터 
// p: 삭제될 노드의 선행 노드
// removed: 삭제될 노드 
void remove_node(ListNode** phead, ListNode* p, ListNode* removed)
{
    if (p == NULL)
        *phead = (*phead)->link;
    else
        p->link = removed->link;    
    free(removed);
}



void display(ListNode* head)
{
	ListNode* p = head;
	while (p != NULL) {
        printf("%d->", p->data);
        p = p->link;
	}
	printf("\n");
}

void display_recur(ListNode* head)
{
	ListNode* p = head;
	if (p != NULL) {
        printf("%d->", p->data);
        display_recur(p->link);
	}
}

ListNode* search(ListNode* head, int x)
{
    ListNode *p = head;
    while (p != NULL && p->data != x)
        p = p->link;
    return p;
}

ListNode* concat(ListNode* head1, ListNode* head2)
{
    ListNode *p;
    if (head1 == NULL) return head2;
    p = head1;
    while (p->link != NULL)
        p = p->link;
    p->link = head2;
    return head1;
}

ListNode* reverse(ListNode* head)
{
    ListNode *p, *q, *r;
    p = head;
    q = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}

// 노드를 동적으로 생성하는 프로그램
ListNode* create_node(element data, ListNode* link)
{
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		fprintf(stderr, "메모리 할당 에러\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = link;

	return(new_node);
}