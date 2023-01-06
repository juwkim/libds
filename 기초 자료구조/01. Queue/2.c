/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:26 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:26 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define FULL 10

typedef struct _node
{
    char data;
    struct _node* next;
    struct _node* prev;
} node;

node* head;
node* tail;

node* create_node(data) {
    node* newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void init(data) {
    node* Node = create_node(data);
    head = Node;
    tail = Node;
}

void insertion_front(data) {
    node* newnode = create_node(data);
    newnode->next = head;
    head->prev = newnode;
    head = head->prev;
}

void deletion_front() {
    node* tmp = head;
    head = head->next;
    free(tmp);
}

int main()
{
    char buf[300];
    printf("문자를 입력하세요: ");

    int length = 0;
    char* str = buf;
    while (1)
    {
        scanf("%c", str);
        if (*str == '\n')
            break;
        else if ('A' <= *str && *str <= 'Z')
            *str += 32;
        else if (('a' > *str || *str > 'z') && !('0' <= *str && *str <= '9'))
            continue;
        length++;
        str++;
    }
    char* ptr = buf;
    init(*ptr);
    while (ptr < str)
        insertion_front(*ptr++);

    int flag = 1;
    int i = 0;
    node* cur = head;
    while (i < length && buf[i] == cur->data)
    {
        i++;
        cur = cur->next;
    }

    if (i != length)
        printf("FALSE\n");
    else
        printf("TRUE\n");
    return 0;
}