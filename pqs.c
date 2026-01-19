#include <stdio.h>
#include <stdlib.h>

/* ===================== CIRCULAR QUEUE ===================== */

typedef struct
{
    int *arr;
    int front;
    int rear;
    int size;
} CQueue;

/* Initialize Circular Queue */
void initCQueue(CQueue *q)
{
    printf("Enter initial size of Circular Queue: ");
    scanf("%d", &q->size);

    q->arr = (int *)malloc(sizeof(int) * q->size);
    q->front = q->rear = -1;
}

/* Check if Circular Queue is empty */
int isEmptyC(CQueue *q)
{
    return q->front == -1;
}

/* Check if Circular Queue is full */
int isFullC(CQueue *q)
{
    return ((q->rear + 1) % q->size == q->front);
}

/* Resize Circular Queue */
void resizeCQueue(CQueue *q)
{
    int newSize = q->size * 2;
    int *newArr = (int *)malloc(sizeof(int) * newSize);

    int i = 0, idx = q->front;

    if (!isEmptyC(q))
    {
        do
        {
            newArr[i++] = q->arr[idx];
            idx = (idx + 1) % q->size;
        } while (idx != (q->rear + 1) % q->size);
    }

    free(q->arr);
    q->arr = newArr;
    q->size = newSize;
    q->front = 0;
    q->rear = i - 1;

    printf("Circular Queue resized to %d\n", newSize);
}

/* Enqueue Circular Queue */
void enqueueC(CQueue *q, int val)
{
    if (isFullC(q))
    {
        printf("Queue full. Resizing...\n");
        resizeCQueue(q);
    }

    if (isEmptyC(q))
        q->front = 0;

    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = val;

    printf("%d enqueued\n", val);
}

/* Dequeue Circular Queue */
void dequeueC(CQueue *q)
{
    if (isEmptyC(q))
    {
        printf("Circular Queue is EMPTY\n");
        return;
    }

    printf("Dequeued: %d\n", q->arr[q->front]);

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % q->size;
}

/* Display Circular Queue */
void displayC(CQueue *q)
{
    if (isEmptyC(q))
    {
        printf("Circular Queue is EMPTY\n");
        return;
    }

    int i = q->front;
    printf("Circular Queue elements: ");
    while (1)
    {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

/* ===================== PRIORITY QUEUE ===================== */

typedef struct
{
    int *data;
    int *priority;
    int front;
    int rear;
    int size;
} PQueue;

/* Initialize Priority Queue */
void initPQueue(PQueue *q)
{
    printf("Enter initial size of Priority Queue: ");
    scanf("%d", &q->size);

    q->data = (int *)malloc(sizeof(int) * q->size);
    q->priority = (int *)malloc(sizeof(int) * q->size);
    q->front = q->rear = -1;
}

/* Check if Priority Queue is empty */
int isEmptyP(PQueue *q)
{
    return q->front == -1;
}

/* Check if Priority Queue is full */
int isFullP(PQueue *q)
{
    return q->rear == q->size - 1;
}

/* Resize Priority Queue */
void resizePQueue(PQueue *q)
{
    q->size *= 2;
    q->data = (int *)realloc(q->data, sizeof(int) * q->size);
    q->priority = (int *)realloc(q->priority, sizeof(int) * q->size);

    printf("Priority Queue resized to %d\n", q->size);
}

/* Insert into Priority Queue */
void insertP(PQueue *q, int item, int pr)
{
    if (isFullP(q))
        resizePQueue(q);

    if (isEmptyP(q))
    {
        q->front = q->rear = 0;
        q->data[0] = item;
        q->priority[0] = pr;
        return;
    }

    int i = q->rear;

    while (i >= q->front && q->priority[i] > pr)
    {
        q->data[i + 1] = q->data[i];
        q->priority[i + 1] = q->priority[i];
        i--;
    }

    q->data[i + 1] = item;
    q->priority[i + 1] = pr;
    q->rear++;
}

/* Delete from Priority Queue */
void deleteP(PQueue *q)
{
    if (isEmptyP(q))
    {
        printf("Priority Queue UNDERFLOW\n");
        return;
    }

    printf("Deleted: %d (Priority %d)\n",
           q->data[q->front], q->priority[q->front]);

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
}

/* Display Priority Queue */
void displayP(PQueue *q)
{
    if (isEmptyP(q))
    {
        printf("Priority Queue is EMPTY\n");
        return;
    }

    printf("Priority Queue elements:\n");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d(P=%d) ", q->data[i], q->priority[i]);
    printf("\n");
}

/* ===================== MAIN MENU ===================== */

int main()
{
    int mainChoice;

    while (1)
    {
        printf("\n====== MENU ======\n");
        printf("1. Circular Queue\n");
        printf("2. Priority Queue\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &mainChoice);

        if (mainChoice == 1)
        {
            CQueue cq;
            int ch, val;
            initCQueue(&cq);

            do
            {
                printf("\n-- Circular Queue Menu --\n");
                printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
                scanf("%d", &ch);

                switch (ch)
                {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", &val);
                    enqueueC(&cq, val);
                    break;
                case 2:
                    dequeueC(&cq);
                    break;
                case 3:
                    displayC(&cq);
                    break;
                }
            } while (ch != 4);

            free(cq.arr);
        }

        else if (mainChoice == 2)
        {
            PQueue pq;
            int ch, item, pr;
            initPQueue(&pq);

            do
            {
                printf("\n-- Priority Queue Menu --\n");
                printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
                scanf("%d", &ch);

                switch (ch)
                {
                case 1:
                    printf("Enter element and priority: ");
                    scanf("%d %d", &item, &pr);
                    insertP(&pq, item, pr);
                    break;
                case 2:
                    deleteP(&pq);
                    break;
                case 3:
                    displayP(&pq);
                    break;
                }
            } while (ch != 4);

            free(pq.data);
            free(pq.priority);
        }

        else
            break;
    }

    return 0;
}
