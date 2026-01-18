#include <stdio.h>
#include <stdlib.h>

/* NODE STRUCTURE */
struct node {
    int data;
    struct node *next;
};

/* FUNCTION DECLARATIONS */
struct node* insertFront(struct node *head, int val);
struct node* insertAtPosition(struct node *head, int val, int pos);
struct node* deleteByKey(struct node *head, int key);
void searchByPosition(struct node *head, int pos);
void display(struct node *head);

/* MAIN FUNCTION */
int main()
{
    struct node *head = NULL;
    int choice, val, pos, key;

    do
    {
        printf("\n===== LP-6 : SINGLY LINKED LIST =====");
        printf("\n1. Insert Front");
        printf("\n2. Insert at Position");
        printf("\n3. Delete by Key");
        printf("\n4. Search by Position");
        printf("\n5. Display List");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                head = insertFront(head, val);
                break;

            case 2:
                printf("Enter value and position: ");
                scanf("%d %d", &val, &pos);
                head = insertAtPosition(head, val, pos);
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                head = deleteByKey(head, key);
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                searchByPosition(head, pos);
                break;

            case 5:
                display(head);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 0);

    return 0;
}

/* FUNCTION DEFINITIONS */

struct node* insertFront(struct node *head, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    return newNode;
}

struct node* insertAtPosition(struct node *head, int val, int pos)
{
    int i;
    struct node *temp = head;

    if(pos == 0)
        return insertFront(head, val);

    for(i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct node* deleteByKey(struct node *head, int key)
{
    struct node *temp = head, *prev = NULL;

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Key not found\n");
        return head;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Node deleted\n");
    return head;
}

void searchByPosition(struct node *head, int pos)
{
    int i = 0;

    while(head != NULL)
    {
        if(i == pos)
        {
            printf("Element at position %d is %d\n", pos, head->data);
            return;
        }
        head = head->next;
        i++;
    }

    printf("Invalid position\n");
}

void display(struct node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List elements: ");
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
