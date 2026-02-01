
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *lptr;
    struct Node *rptr;
};

/* Function prototypes */
struct Node* insertByPosition(struct Node *head, int data, int pos);
struct Node* deleteRear(struct Node *head);
struct Node* deleteByPosition(struct Node *head, int pos);
void searchByValue(struct Node *head, int key);
void display(struct Node *head);
int length(struct Node *head);

/* MAIN */
int main()
{
    struct Node *head = NULL;
    int choice, data, pos, key;

    do {
        printf("\n--- CIRCULAR DOUBLY LINKED LIST MENU ---");
        printf("\n1. Insert by Position");
        printf("\n2. Delete Rear");
        printf("\n3. Delete by Position");
        printf("\n4. Search by Value");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                head = insertByPosition(head, data, pos);
                display(head);
                break;

            case 2:
                head = deleteRear(head);
                display(head);
                break;

            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                head = deleteByPosition(head, pos);
                display(head);
                break;

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &key);
                searchByValue(head, key);
                display(head);
                break;
        }

    } while(choice != 0);

    return 0;
}
struct Node* insertByPosition(struct Node *head, int data, int pos)
{
    int i, len = length(head);

    if(pos < 0 || pos > len) {
        printf("Invalid position\n");
        return head;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    /* Empty list */
    if(head == NULL) {
        newNode->lptr = newNode->rptr = newNode;
        return newNode;
    }

    /* Insert at beginning */
    if(pos == 0) {
        struct Node *last = head->lptr;
        newNode->rptr = head;
        newNode->lptr = last;
        last->rptr = newNode;
        head->lptr = newNode;
        return newNode;
    }

    struct Node *temp = head;
    for(i = 0; i < pos - 1; i++)
        temp = temp->rptr;

    newNode->rptr = temp->rptr;
    newNode->lptr = temp;
    temp->rptr->lptr = newNode;
    temp->rptr = newNode;

    return head;
}
struct Node* deleteRear(struct Node *head)
{
    if(head == NULL) {
        printf("List empty\n");
        return head;
    }

    /* Only one node */
    if(head->rptr == head) {
        free(head);
        printf("Rear deleted\n");
        return NULL;
    }

    struct Node *last = head->lptr;
    struct Node *prev = last->lptr;

    prev->rptr = head;
    head->lptr = prev;
    free(last);

    printf("Rear deleted\n");
    return head;
}
struct Node* deleteByPosition(struct Node *head, int pos)
{
    int i, len = length(head);

    if(pos < 0 || pos >= len) {
        printf("Invalid position\n");
        return head;
    }

    /* Only one node */
    if(len == 1) {
        free(head);
        printf("Node deleted\n");
        return NULL;
    }

    /* Delete first node */
    if(pos == 0) {
        struct Node *last = head->lptr;
        struct Node *temp = head;
        head = head->rptr;
        last->rptr = head;
        head->lptr = last;
        free(temp);
        printf("Node deleted\n");
        return head;
    }

    struct Node *curr = head;
    for(i = 0; i < pos; i++)
        curr = curr->rptr;

    curr->lptr->rptr = curr->rptr;
    curr->rptr->lptr = curr->lptr;
    free(curr);

    printf("Node deleted\n");
    return head;
}
void searchByValue(struct Node *head, int key)
{
    if(head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node *temp = head;
    int pos = 0;

    do {
        if(temp->data == key) {
            printf("Value found at position %d\n", pos);
            return;
        }
        temp = temp->rptr;
        pos++;
    } while(temp != head);

    printf("Value not found\n");
}
void display(struct Node *head)
{
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->rptr;
    } while(temp != head);
    printf("(back to head)\n");
}
int length(struct Node *head)
{
    if(head == NULL)
        return 0;

    int count = 0;
    struct Node *temp = head;
    do {
        count++;
        temp = temp->rptr;
    } while(temp != head);
    return count;
}
