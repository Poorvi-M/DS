#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node* createHeader();
struct node* insertFront(struct node *h, int val);
struct node* insertAtPosition(struct node *h, int val, int pos);
struct node* deleteByPosition(struct node *h, int pos);
void searchByKey(struct node *h, int key);
void display(struct node *h);

int main()
{
    struct node *h = createHeader();
    int ch, val, pos, key;

    do {
        printf("\nLP-7 MENU");
        printf("\n1.Insert Front");
        printf("\n2.Insert at Position");
        printf("\n3.Delete by Position");
        printf("\n4.Search by Key");
        printf("\n5.Display");
        printf("\n0.Exit");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: scanf("%d",&val); h=insertFront(h,val); break;
            case 2: scanf("%d%d",&val,&pos); h=insertAtPosition(h,val,pos); break;
            case 3: scanf("%d",&pos); h=deleteByPosition(h,pos); break;
            case 4: scanf("%d",&key); searchByKey(h,key); break;
            case 5: display(h); break;
        }
    } while(ch!=0);

    return 0;
}

struct node* createHeader()
{
    struct node *h = malloc(sizeof(struct node));
    h->next = h;
    h->prev = h;
    return h;
}

struct node* insertFront(struct node *h, int val)
{
    struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->next = h->next;
    n->prev = h;
    h->next->prev = n;
    h->next = n;
    return h;
}

struct node* insertAtPosition(struct node *h, int val, int pos)
{
    struct node *t = h->next;
    int i=0;
    while(t!=h && i<pos){ t=t->next; i++; }
    if(t==h) return h;
    struct node *n = malloc(sizeof(struct node));
    n->data = val;
    n->next = t;
    n->prev = t->prev;
    t->prev->next = n;
    t->prev = n;
    return h;
}

struct node* deleteByPosition(struct node *h, int pos)
{
    struct node *t = h->next;
    int i=0;
    while(t!=h && i<pos){ t=t->next; i++; }
    if(t==h) return h;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
    return h;
}

void searchByKey(struct node *h, int key)
{
    struct node *t=h->next;
    int pos=0;
    while(t!=h){
        if(t->data==key){
            printf("Found at %d\n",pos);
            return;
        }
        t=t->next; pos++;
    }
    printf("Not found\n");
}

void display(struct node *h)
{
    struct node *t=h->next;
    while(t!=h){ printf("%d ",t->data); t=t->next; }
}
