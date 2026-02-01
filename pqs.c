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
