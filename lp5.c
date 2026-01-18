#include <stdio.h>
#include <stdlib.h>

/* NODE STRUCTURE */
struct node {
    int data;
    struct node *prev, *next;
};

/* FUNCTION DECLARATIONS */
struct node* createHeader();
struct node* insertByOrder(struct node *head, int val);
struct node* deleteByPosition(struct node *head, int pos);
struct node* deleteByKey(struct node *head, int key);
void searchByPosition(struct node *head, int pos);
void display(struct node *head);

/* MAIN FUNCTION */
int main()
{
    struct node *head = createHeader();
    int choice, val, pos, key;

    do
    {
        printf("\n===== LP-5 : CIRCULAR DLL WITH HEADER =====");
        printf("\n1. Insert by Order");
        printf("\n2. Delete by Position");
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
                head = insertByOrder(head, val);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deleteByPosition(head, pos);
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

struct node* createHeader()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = head;
    head->prev = head;
    return head;
}

struct node* insertByOrder(struct node *head, int val)
{
    struct node *temp = head->next;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;

    while(temp != head && temp->data < val)
        temp = temp->next;

    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;

    return head;
}

struct node* deleteByPosition(struct node *head, int pos)
{
    struct node *temp = head->next;
    int i = 0;

    while(temp != head && i < pos)
    {
        temp = temp->next;
        i++;
    }

    if(temp == head)
    {
        printf("Invalid position\n");
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    printf("Node deleted\n");
    return head;
}

struct node* deleteByKey(struct node *head, int key)
{
    struct node *temp = head->next;

    while(temp != head && temp->data != key)
        temp = temp->next;

    if(temp == head)
    {
        printf("Key not found\n");
        return head;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    printf("Node deleted\n");
    return head;
}

void searchByPosition(struct node *head, int pos)
{
    struct node *temp = head->next;
    int i = 0;

    while(temp != head)
    {
        if(i == pos)
        {
            printf("Element at position %d is %d\n", pos, temp->data);
            return;
        }
        temp = temp->next;
        i++;
    }

    printf("Invalid position\n");
}

void display(struct node *head)
{
    struct node *temp = head->next;

    if(temp == head)
    {
        printf("List is empty\n");
        return;
    }

    printf("List elements: ");
    while(temp != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
