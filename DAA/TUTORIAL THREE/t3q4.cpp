#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
//Stack using queue
// O(2n)
// O(2n)
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

bool isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

bool isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(q))
        q->front = q->rear = 0;
    else
        q->rear = (q->rear + 1) % MAX_SIZE;

    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value = q->data[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX_SIZE;

    return value;
}

typedef struct {
    Queue queue1;
    Queue queue2;
} Stack;

void initStack(Stack *s) {
    initQueue(&s->queue1);
    initQueue(&s->queue2);
}

void push(Stack *s, int value) {                   //O(1)       
    if (isFull(&s->queue1)) {
        printf("Stack is full. Cannot push.\n");
        return;
    }

    enqueue(&s->queue1, value);
}

int pop(Stack *s) {                                //O(n)
    if (isEmpty(&s->queue1)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }

    while (s->queue1.front != s->queue1.rear) {
        int value = dequeue(&s->queue1);
        enqueue(&s->queue2, value);
    }

    int poppedValue = dequeue(&s->queue1);

    Queue temp = s->queue1;
    s->queue1 = s->queue2;
    s->queue2 = temp;

    return poppedValue;
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));

    return 0;
}

