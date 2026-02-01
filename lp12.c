#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
    int front, rear;
} Queue;

/* Function prototypes */
void initQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void resize(Queue *q);
void enqueue(Queue *q, int item);
void dequeue(Queue *q);
void peekFront(Queue *q);
void peekRear(Queue *q);
void display(Queue *q);

/* MAIN */
int main()
{
    Queue q;
    int choice, val;

    initQueue(&q);

    do {
        printf("\n--- ORDINARY QUEUE MENU ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek Front");
        printf("\n4. Peek Rear");
        printf("\n5. Display");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peekFront(&q);
                break;
            case 4:
                peekRear(&q);
                break;
            case 5:
                display(&q);
                break;
        }
    } while(choice != 0);

    free(q.arr);
    return 0;
}

/* INITIALIZE */
void initQueue(Queue *q)
{
    q->capacity = 4;
    q->size = 0;
    q->front = 0;
    q->rear = -1;
    q->arr = (int*)malloc(q->capacity * sizeof(int));
}

int isEmpty(Queue *q)
{
    return q->size == 0;
}

int isFull(Queue *q)
{
    return q->size == q->capacity;
}

void resize(Queue *q)
{
    q->capacity *= 2;
    q->arr = (int*)realloc(q->arr, q->capacity * sizeof(int));
    printf("Allocating more memory...\n");
}

/* ENQUEUE */
void enqueue(Queue *q, int item)
{
    if(isFull(q))
        resize(q);

    q->arr[++q->rear] = item;
    q->size++;
}

/* DEQUEUE */
void dequeue(Queue *q)
{
    if(isEmpty(q)) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted %d\n", q->arr[q->front]);

    for(int i = 0; i < q->rear; i++)
        q->arr[i] = q->arr[i + 1];

    q->rear--;
    q->size--;
}

/* PEEK FRONT */
void peekFront(Queue *q)
{
    if(isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }
    printf("Front element: %d\n", q->arr[q->front]);
}

/* PEEK REAR */
void peekRear(Queue *q)
{
    if(isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }
    printf("Rear element: %d\n", q->arr[q->rear]);
}

/* DISPLAY */
void display(Queue *q)
{
    if(isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue: ");
    for(int i = 0; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int front, rear;
} Deque;

/* Function prototypes */
void initDeque(Deque *dq);
int isEmpty(Deque *dq);
int isFull(Deque *dq);
void resize(Deque *dq);
void insertFront(Deque *dq, int item);
void insertRear(Deque *dq, int item);
void deleteFront(Deque *dq);
void deleteRear(Deque *dq);
void display(Deque *dq);

/* MAIN */
int main()
{
    Deque dq;
    int choice, val;

    initDeque(&dq);

    do {
        printf("\n--- DEQUE MENU ---");
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(&dq, val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(&dq, val);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
        }
    } while(choice != 0);

    free(dq.arr);
    return 0;
}

/* INITIALIZE */
void initDeque(Deque *dq)
{
    dq->capacity = 4;
    dq->front = -1;
    dq->rear = 0;
    dq->arr = (int*)malloc(dq->capacity * sizeof(int));
}

int isEmpty(Deque *dq)
{
    return dq->front == -1;
}

int isFull(Deque *dq)
{
    return (dq->front == 0 && dq->rear == dq->capacity - 1);
}

/* RESIZE */
void resize(Deque *dq)
{
    dq->capacity *= 2;
    dq->arr = (int*)realloc(dq->arr, dq->capacity * sizeof(int));
    printf("Allocating more memory...\n");
}

/* INSERT FRONT */
void insertFront(Deque *dq, int item)
{
    if(isFull(dq))
        resize(dq);

    if(isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        for(int i = dq->rear; i >= dq->front; i--)
            dq->arr[i + 1] = dq->arr[i];
        dq->rear++;
    }
    dq->arr[dq->front] = item;
}

/* INSERT REAR */
void insertRear(Deque *dq, int item)
{
    if(isFull(dq))
        resize(dq);

    if(isEmpty(dq))
        dq->front = dq->rear = 0;
    else
        dq->rear++;

    dq->arr[dq->rear] = item;
}

/* DELETE FRONT */
void deleteFront(Deque *dq)
{
    if(isEmpty(dq)) {
        printf("Deque Empty\n");
        return;
    }

    printf("Deleted %d\n", dq->arr[dq->front]);

    if(dq->front == dq->rear)
        dq->front = -1;
    else
        dq->front++;
}

/* DELETE REAR */
void deleteRear(Deque *dq)
{
    if(isEmpty(dq)) {
        printf("Deque Empty\n");
        return;
    }

    printf("Deleted %d\n", dq->arr[dq->rear]);

    if(dq->front == dq->rear)
        dq->front = -1;
    else
        dq->rear--;
}

/* DISPLAY */
void display(Deque *dq)
{
    if(isEmpty(dq)) {
        printf("Deque Empty\n");
        return;
    }

    printf("Deque: ");
    for(int i = dq->front; i <= dq->rear; i++)
        printf("%d ", dq->arr[i]);
    printf("\n");
}
