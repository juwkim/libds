/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:17:21 by juwkim            #+#    #+#             */
/*   Updated: 2023/01/07 00:17:21 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#define INF 987654321
#define SIZE 10

int arr[SIZE];
int front = SIZE - 1;
int rear = SIZE - 1;

bool isEmpty() {
    return rear == front;
}

bool isFull() {
    return ((rear + 1) % SIZE) == front;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Q is full\n");
        return;
    }
    rear = (rear + 1) % SIZE;
    arr[rear] = data;
}

int dequeue() {
    if (isEmpty()) {
        printf("Q is empth\n");
        return INF;
    }
    return arr[front = (front + 1) % SIZE];
}


int main() {

    int n;
    printf("n을 입력하세요: ");
    if (scanf("%d", &n) == 1)
    {

        enqueue(0);
        enqueue(1);
        for (int i = 0; i <= n; i++)
        {
            int a = dequeue();
            int b = dequeue();
            enqueue(b);
            enqueue(a + b);

            printf("%d ", a);
        }
    }
}