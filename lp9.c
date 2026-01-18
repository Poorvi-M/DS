#include <stdio.h>
#include <stdlib.h>

/* NODE DEFINITION */
struct node {
    int data;              // header stores count
    struct node *next;
};

/* FUNCTION DECLARATIONS */
struct node* createHeader();
struct node* insertByOrder(struct node *h, int val);
struct node* deleteFront(struct node *h);
struct node* deleteRear(struct node *h);
struct node* reverse(struct node *h);
void display(struct node *h);

/* ================= MAIN FUNCTION ================= */

int main()
{
    struct node *h = createHeader();
    int ch, val;

    do
    {
        printf("\nLP-9 MENU");
        printf("\n1. Insert by Order");
        printf("\n2. Delete Rear");
        printf("\n3. Delete Front");
        printf("\n4. Reverse");
        printf("\n5. Display");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            printf("Enter value: ");
            scanf("%d", &val);
            h = insertByOrder(h, val);
        }

        if (ch == 2)
        {
            h = deleteRear(h);
        }

        if (ch == 3)
        {
            h = deleteFront(h);
        }

        if (ch == 4)
        {
            h = reverse(h);
        }

        if (ch == 5)
        {
            display(h);
        }

    } while (ch != 0);

    return 0;
}

/* ================= CREATE HEADER ================= */

struct node* createHeader()
{
    struct node *h = (struct node *)malloc(sizeof(struct node));
    h->data = 0;      // count = 0
    h->next = h;
    return h;
}

/* ================= INSERT BY ORDER ================= */

struct node* insertByOrder(struct node *h, int val)
{
    struct node *temp;
    struct node *newnode;

    temp = h;

    while (temp->next != h)
    {
        if (temp->next->data >= val)
        {
            break;
        }
        temp = temp->next;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;

    newnode->next = temp->next;
    temp->next = newnode;

    h->data = h->data + 1;

    return h;
}

/* ================= DELETE FRONT ================= */

struct node* deleteFront(struct node *h)
{
    struct node *temp;

    if (h->next == h)
    {
        printf("List is empty\n");
        return h;
    }

    temp = h->next;
    h->next = temp->next;
    free(temp);

    h->data = h->data - 1;

    return h;
}

/* ================= DELETE REAR ================= */

struct node* deleteRear(struct node *h)
{
    struct node *temp;

    if (h->next == h)
    {
        printf("List is empty\n");
        return h;
    }

    temp = h;

    if (temp->next->next == h)
    {
        free(temp->next);
        temp->next = h;
        h->data = h->data - 1;
        return h;
    }

    while (temp->next->next != h)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = h;
    h->data = h->data - 1;

    return h;
}

/* ================= REVERSE LIST ================= */

struct node* reverse(struct node *h)
{
    struct node *prev;
    struct node *curr;
    struct node *next;

    if (h->next == h)
    {
        return h;
    }

    prev = h;
    curr = h->next;

    while (curr != h)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    h->next = prev;
    return h;
}

/* ================= DISPLAY ================= */

void display(struct node *h)
{
    struct node *temp;

    if (h->next == h)
    {
        printf("List is empty\n");
        return;
    }

    temp = h->next;
    printf("List: ");

    while (temp != h)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
