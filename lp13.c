#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int front, rear;
} Cqueue;

void initCQueue(Cqueue *q, int size)
{
    q->size = size;
    q->arr = (int*)malloc(size * sizeof(int));
    q->front = q->rear = 0;
}

int isEmpty(Cqueue *q)
{
    return q->front == q->rear;
}

int isFull(Cqueue *q)
{
    return (q->rear + 1) % q->size == q->front;
}

void resize(Cqueue *q)
{
    int newsize = q->size * 2;
    int *newarr = (int*)malloc(newsize * sizeof(int));

    int i = 0;
    int idx = q->front;

    while(idx != q->rear) {
        newarr[i++] = q->arr[idx];
        idx = (idx + 1) % q->size;
    }

    free(q->arr);
    q->arr = newarr;
    q->front = 0;
    q->rear = i;
    q->size = newsize;

    printf("Queue resized to %d\n", newsize);
}

void enqueue(Cqueue *q, int item)
{
    if(isFull(q)){

        printf("Allocating more space");
        resize(q);
    }
      

    q->arr[q->rear] = item;
    q->rear = (q->rear + 1) % q->size;
}

void dequeue(Cqueue *q)
{
    if(isEmpty(q)) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted %d\n", q->arr[q->front]);
    q->front = (q->front + 1) % q->size;
}

void peekFront(Cqueue *q)
{
    if(isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }
    printf("Front element: %d\n", q->arr[q->front]);
}

void peekRear(Cqueue *q)
{
    if(isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }
    printf("Rear element: %d\n", q->arr[(q->rear - 1 + q->size) % q->size]);
}

void displayCQueue(Cqueue *q)
{
    if(isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }

    printf("Circular Queue: ");
    int i = q->front;
    while(i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main()
{
    Cqueue q;
    int choice, val, size;

    printf("Enter initial size: ");
    scanf("%d", &size);
    initCQueue(&q, size);

    do {
        printf("\n--- Circular Queue Menu ---");
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
                displayCQueue(&q);
        }
    } while(choice != 0);

    free(q.arr);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element *arr;
    int size;
    int capacity;
} PriorityQueue;

/* Function prototypes */
void initPQ(PriorityQueue *pq);
void insert(PriorityQueue *pq, int data, int priority);
void deleteFront(PriorityQueue *pq);
void display(PriorityQueue *pq);
int isEmpty(PriorityQueue *pq);
int isFull(PriorityQueue *pq);
void resize(PriorityQueue *pq);

/* MAIN */
int main()
{
    PriorityQueue pq;
    int choice, data, priority;

    initPQ(&pq);

    do {
        printf("\n--- PRIORITY QUEUE MENU ---");
        printf("\n1. Insert (Data + Priority)");
        printf("\n2. Delete Highest Priority");
        printf("\n3. Display");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                insert(&pq, data, priority);
                break;

            case 2:
                deleteFront(&pq);
                break;

            case 3:
                display(&pq);
                break;
        }

    } while(choice != 0);

    free(pq.arr);
    return 0;
}

/* INITIALIZE */
void initPQ(PriorityQueue *pq)
{
    pq->capacity = 4;   // small initial size
    pq->size = 0;
    pq->arr = (Element*)malloc(pq->capacity * sizeof(Element));
}

/* CHECK EMPTY */
int isEmpty(PriorityQueue *pq)
{
    return pq->size == 0;
}

/* CHECK FULL */
int isFull(PriorityQueue *pq)
{
    return pq->size == pq->capacity;
}

/* RESIZE */
void resize(PriorityQueue *pq)
{
    pq->capacity *= 2;
    pq->arr = (Element*)realloc(pq->arr, pq->capacity * sizeof(Element));
    printf("Allocating more memory...\n");
}

/* INSERT BY PRIORITY */
void insert(PriorityQueue *pq, int data, int priority)
{
    if(isFull(pq))
        resize(pq);

    int i = pq->size - 1;

    /* Shift elements based on priority */
    while(i >= 0 && pq->arr[i].priority < priority) {
        pq->arr[i + 1] = pq->arr[i];
        i--;
    }

    pq->arr[i + 1].data = data;
    pq->arr[i + 1].priority = priority;
    pq->size++;

    printf("Inserted (%d, priority %d)\n", data, priority);
}

/* DELETE HIGHEST PRIORITY */
void deleteFront(PriorityQueue *pq)
{
    if(isEmpty(pq)) {
        printf("Priority Queue is EMPTY\n");
        return;
    }

    printf("Deleted: %d (priority %d)\n",
           pq->arr[0].data,
           pq->arr[0].priority);

    for(int i = 0; i < pq->size - 1; i++)
        pq->arr[i] = pq->arr[i + 1];

    pq->size--;
}

/* DISPLAY */
void display(PriorityQueue *pq)
{
    if(isEmpty(pq)) {
        printf("Priority Queue is EMPTY\n");
        return;
    }

    printf("Priority Queue:\n");
    printf("Data  Priority\n");
    for(int i = 0; i < pq->size; i++)
        printf("%4d  %8d\n", pq->arr[i].data, pq->arr[i].priority);
}
