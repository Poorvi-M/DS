// #include <stdio.h>
// #include <stdlib.h>

// int *cq, size, front = -1, rear = -1;

// void cEnqueue(int x)
// {
//     if((rear + 1) % size == front) return;
//     if(front == -1) front = 0;
//     rear = (rear + 1) % size;
//     cq[rear] = x;
// }

// void cDequeue()
// {
//     if(front == -1) return;
//     if(front == rear) front = rear = -1;
//     else front = (front + 1) % size;
// }

// void cDisplay()
// {
//     int i;
//     if(front == -1) return;
//     i = front;
//     while(1)
//     {
//         printf("%d ", cq[i]);
//         if(i == rear) break;
//         i = (i + 1) % size;
//     }
// }

// int main()
// {
//     int choice, x;

//     printf("Enter size: ");
//     scanf("%d", &size);
//     cq = malloc(size * sizeof(int));

//     do
//     {
//         printf("\nLP-13 MENU");
//         printf("\n1.Circular Enqueue");
//         printf("\n2.Circular Dequeue");
//         printf("\n3.Display");
//         printf("\n0.Exit");
//         scanf("%d", &choice);

//         switch(choice)
//         {
//             case 1: scanf("%d", &x); cEnqueue(x); break;
//             case 2: cDequeue(); break;
//             case 3: cDisplay(); break;
//         }
//     } while(choice != 0);

//     free(cq);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

/* ===================== CIRCULAR QUEUE ===================== */

struct CQueue {
    int *arr;
    int front, rear, size;
};

/* Initialize Circular Queue */
void initCQueue(struct CQueue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(size * sizeof(int));
}

/* Check if full */
int isCFull(struct CQueue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

/* Check if empty */
int isCEmpty(struct CQueue *q) {
    return (q->front == -1);
}

/* Enqueue */
void enqueueC(struct CQueue *q, int val) {
    if (isCFull(q)) {
        printf("Circular Queue Overflow\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = val;

    printf("Inserted %d\n", val);
}

/* Dequeue */
void dequeueC(struct CQueue *q) {
    if (isCEmpty(q)) {
        printf("Circular Queue Underflow\n");
        return;
    }

    int val = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % q->size;

    printf("Deleted %d\n", val);
}

/* Display */
void displayC(struct CQueue *q) {
    if (isCEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }

    int i = q->front;
    printf("Queue: ");
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

/* ===================== PRIORITY QUEUE ===================== */

struct PQueue {
    int *arr;
    int size;
    int count;
};

/* Initialize Priority Queue */
void initPQueue(struct PQueue *pq, int size) {
    pq->size = size;
    pq->count = 0;
    pq->arr = (int *)malloc(size * sizeof(int));
}

/* Enqueue (higher value = higher priority) */
void enqueueP(struct PQueue *pq, int val) {
    if (pq->count == pq->size) {
        printf("Priority Queue Overflow\n");
        return;
    }

    int i = pq->count - 1;
    while (i >= 0 && pq->arr[i] < val) {
        pq->arr[i + 1] = pq->arr[i];
        i--;
    }

    pq->arr[i + 1] = val;
    pq->count++;

    printf("Inserted %d\n", val);
}

/* Dequeue */
void dequeueP(struct PQueue *pq) {
    if (pq->count == 0) {
        printf("Priority Queue Underflow\n");
        return;
    }

    int val = pq->arr[0];
    for (int i = 0; i < pq->count - 1; i++)
        pq->arr[i] = pq->arr[i + 1];

    pq->count--;
    printf("Deleted %d\n", val);
}

/* Display */
void displayP(struct PQueue *pq) {
    if (pq->count == 0) {
        printf("Queue Empty\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < pq->count; i++)
        printf("%d ", pq->arr[i]);
    printf("\n");
}

/* ===================== MAIN MENU ===================== */

int main() {
    struct CQueue cq;
    struct PQueue pq;
    int choice, sub, val, size;

    printf("Enter Queue Size: ");
    scanf("%d", &size);

    initCQueue(&cq, size);
    initPQueue(&pq, size);

    do {
        printf("\n===== MAIN MENU =====");
        printf("\n1. Circular Queue");
        printf("\n2. Priority Queue");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            do {
                printf("\n--- Circular Queue ---");
                printf("\n1. Enqueue");
                printf("\n2. Dequeue");
                printf("\n3. Display");
                printf("\n0. Back");
                printf("\nEnter choice: ");
                scanf("%d", &sub);

                switch (sub) {
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
            } while (sub != 0);
            break;

        case 2:
            do {
                printf("\n--- Priority Queue ---");
                printf("\n1. Enqueue");
                printf("\n2. Dequeue");
                printf("\n3. Display");
                printf("\n0. Back");
                printf("\nEnter choice: ");
                scanf("%d", &sub);

                switch (sub) {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", &val);
                    enqueueP(&pq, val);
                    break;
                case 2:
                    dequeueP(&pq);
                    break;
                case 3:
                    displayP(&pq);
                    break;
                }
            } while (sub != 0);
            break;
        }
    } while (choice != 0);

    free(cq.arr);
    free(pq.arr);
    return 0;
}
