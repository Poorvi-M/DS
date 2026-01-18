// #include <stdio.h>
// #include <stdlib.h>

// int *q, front = -1, rear = -1, size;

// void enqueue(int x)
// {
//     if(rear == size - 1) return;
//     if(front == -1) front = 0;
//     q[++rear] = x;
// }

// void dequeue()
// {
//     if(front == -1) return;
//     front++;
//     if(front > rear) front = rear = -1;
// }

// void display()
// {
//     if(front == -1) return;
//     for(int i = front; i <= rear; i++)
//         printf("%d ", q[i]);
// }

// int main()
// {
//     int choice, x;

//     printf("Enter queue size: ");
//     scanf("%d", &size);
//     q = malloc(size * sizeof(int));

//     do
//     {
//         printf("\nLP-12 MENU");
//         printf("\n1.Enqueue");
//         printf("\n2.Dequeue");
//         printf("\n3.Display");
//         printf("\n0.Exit");
//         scanf("%d", &choice);

//         switch(choice)
//         {
//             case 1: scanf("%d", &x); enqueue(x); break;
//             case 2: dequeue(); break;
//             case 3: display(); break;
//         }
//     } while(choice != 0);

//     free(q);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

/* ================= ORDINARY QUEUE ================= */

struct Queue {
    int *arr;
    int front, rear, size;
};

void initQueue(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(size * sizeof(int));
}

int isFull(struct Queue *q) {
    return (q->rear == q->size - 1);
}

int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue *q, int val) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = val;
    printf("Inserted %d\n", val);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted %d\n", q->arr[q->front++]);

    if (q->front > q->rear)
        q->front = q->rear = -1;
}

void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

/* ================= DOUBLE ENDED QUEUE ================= */

struct Deque {
    int *arr;
    int front, rear, size;
};

void initDeque(struct Deque *dq, int size) {
    dq->size = size;
    dq->front = dq->rear = -1;
    dq->arr = (int *)malloc(size * sizeof(int));
}

int isDEmpty(struct Deque *dq) {
    return (dq->front == -1);
}

int isDFull(struct Deque *dq) {
    return (dq->front == 0 && dq->rear == dq->size - 1);
}

void insertFront(struct Deque *dq, int val) {
    if (isDFull(dq)) {
        printf("Deque Overflow\n");
        return;
    }

    if (dq->front == -1)
        dq->front = dq->rear = 0;
    else
        dq->front--;

    dq->arr[dq->front] = val;
    printf("Inserted %d at front\n", val);
}

void insertRear(struct Deque *dq, int val) {
    if (isDFull(dq)) {
        printf("Deque Overflow\n");
        return;
    }

    if (dq->rear == -1)
        dq->front = dq->rear = 0;
    else
        dq->rear++;

    dq->arr[dq->rear] = val;
    printf("Inserted %d at rear\n", val);
}

void deleteFront(struct Deque *dq) {
    if (isDEmpty(dq)) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted %d from front\n", dq->arr[dq->front]);

    if (dq->front == dq->rear)
        dq->front = dq->rear = -1;
    else
        dq->front++;
}

void deleteRear(struct Deque *dq) {
    if (isDEmpty(dq)) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted %d from rear\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear)
        dq->front = dq->rear = -1;
    else
        dq->rear--;
}

void displayDeque(struct Deque *dq) {
    if (isDEmpty(dq)) {
        printf("Deque Empty\n");
        return;
    }

    printf("Deque: ");
    for (int i = dq->front; i <= dq->rear; i++)
        printf("%d ", dq->arr[i]);
    printf("\n");
}

/* ================= MAIN MENU ================= */

int main() {
    struct Queue q;
    struct Deque dq;
    int choice, sub, val, size;

    printf("Enter queue size: ");
    scanf("%d", &size);

    initQueue(&q, size);
    initDeque(&dq, size);

    do {
        printf("\n===== MAIN MENU =====");
        printf("\n1. Ordinary Queue");
        printf("\n2. Double Ended Queue");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            do {
                printf("\n--- Ordinary Queue ---");
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
                    enqueue(&q, val);
                    break;
                case 2:
                    dequeue(&q);
                    break;
                case 3:
                    displayQueue(&q);
                    break;
                }
            } while (sub != 0);
            break;

        case 2:
            do {
                printf("\n--- Deque ---");
                printf("\n1. Insert Front");
                printf("\n2. Insert Rear");
                printf("\n3. Delete Front");
                printf("\n4. Delete Rear");
                printf("\n5. Display");
                printf("\n0. Back");
                printf("\nEnter choice: ");
                scanf("%d", &sub);

                switch (sub) {
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
                    displayDeque(&dq);
                    break;
                }
            } while (sub != 0);
            break;
        }
    } while (choice != 0);

    free(q.arr);
    free(dq.arr);
    return 0;
}
