#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* createHeader();
struct node* insertByOrder(struct node *h,int val);
struct node* deleteFront(struct node *h);
struct node* deleteRear(struct node *h);
struct node* reverse(struct node *h);
void display(struct node *h);

int main()
{
    struct node *h=createHeader();
    int ch,val;

    do{
        printf("\nLP-9 MENU");
        printf("\n1.Insert by Order");
        printf("\n2.Delete Rear");
        printf("\n3.Delete Front");
        printf("\n4.Reverse");
        printf("\n5.Display");
        printf("\n0.Exit");
        scanf("%d",&ch);

        switch(ch){
            case 1: scanf("%d",&val); h=insertByOrder(h,val); break;
            case 2: h=deleteRear(h); break;
            case 3: h=deleteFront(h); break;
            case 4: h=reverse(h); break;
            case 5: display(h); break;
        }
    }while(ch!=0);

    return 0;
}

struct node* createHeader()
{
    struct node *h=malloc(sizeof(struct node));
    h->next=h;
    return h;
}

struct node* insertByOrder(struct node *h,int val)
{
    struct node *t=h;
    while(t->next!=h && t->next->data<val) t=t->next;
    struct node *n=malloc(sizeof(struct node));
    n->data=val;
    n->next=t->next;
    t->next=n;
    return h;
}

struct node* deleteFront(struct node *h)
{
    if(h->next==h) return h;
    struct node *t=h->next;
    h->next=t->next;
    free(t);
    return h;
}

struct node* deleteRear(struct node *h)
{
    struct node *t=h;
    while(t->next->next!=h) t=t->next;
    free(t->next);
    t->next=h;
    return h;
}

struct node* reverse(struct node *h)
{
    struct node *prev=h,*curr=h->next,*next;
    while(curr!=h){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    h->next=prev;
    return h;
}

void display(struct node *h)
{
    struct node *t=h->next;
    while(t!=h){ printf("%d ",t->data); t=t->next; }
}
