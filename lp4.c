#include <stdio.h>
#include <stdlib.h>

/* NODE DEFINITION */
struct node {
    int data;
    struct node *next;
};

/* FUNCTION DECLARATIONS */
struct node* insertByOrder(struct node *head, int val);
struct node* deleteAtBeginning(struct node *head);
void searchByKey(struct node *head, int key);
struct node* deleteByKey(struct node *head, int key);
void displayList(struct node *head);

/* MAIN FUNCTION */
int main()
{
    struct node *head = NULL;
    int choice, val, key;

    do
    {
        printf("\n===== LP-4 : SINGLY LINKED LIST MENU =====");
        printf("\n1. Insert by Order");
        printf("\n2. Delete at Beginning");
        printf("\n3. Search by Key");
        printf("\n4. Delete by Key");
        printf("\n5. Display List");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                head = insertByOrder(head, val);
                break;

            case 2:
                head = deleteAtBeginning(head);
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                searchByKey(head, key);
                break;

            case 4:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                head = deleteByKey(head, key);
                break;

            case 5:
                displayList(head);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 0);

    return 0;
}

/* FUNCTION DEFINITIONS */

struct node* insertByOrder(struct node *head, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;

    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL || val < head->data)
    {
        newNode->next = head;
        return newNode;
    }

    while(temp->next != NULL && temp->next->data < val)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct node* deleteAtBeginning(struct node *head)
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted\n");
    return head;
}

void searchByKey(struct node *head, int key)
{
    int pos = 0;
    while(head != NULL)
    {
        if(head->data == key)
        {
            printf("Key found at position %d\n", pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Key not found\n");
}

struct node* deleteByKey(struct node *head, int key)
{
    struct node *temp = head, *prev = NULL;

    if(head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if(head->data == key)
    {
        head = head->next;
        free(temp);
        printf("Node deleted\n");
        return head;
    }

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

    prev->next = temp->next;
    free(temp);
    printf("Node deleted\n");

    return head;
}

void displayList(struct node *head)
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
