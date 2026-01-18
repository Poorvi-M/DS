#include <stdio.h>
#include <stdlib.h>

/* ========== NODE STRUCTURE ========== */

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* ========== DISPLAY LIST ========== */

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* ========== INSERT BY POSITION ========== */

void insertAtPos(int val, int pos) {
    struct node *newnode;
    struct node *temp;
    int i;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (pos == 1) {
        if (head == NULL) {
            head = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        display();
        return;
    }

    temp = head;
    i = 1;

    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
    newnode->prev = temp;

    display();
}

/* ========== DELETE REAR ========== */

void deleteRear() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (temp->next == NULL) {
        printf("Deleted %d\n", temp->data);
        free(temp);
        head = NULL;
        display();
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted %d\n", temp->data);
    temp->prev->next = NULL;
    free(temp);

    display();
}

/* ========== DELETE AT POSITION ========== */

void deleteAtPos(int pos) {
    struct node *temp;
    int i;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        printf("Deleted %d\n", temp->data);
        free(temp);
        display();
        return;
    }

    temp = head;
    i = 1;

    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    printf("Deleted %d\n", temp->data);
    free(temp);

    display();
}

/* ========== SEARCH BY VALUE ========== */

void search(int key) {
    struct node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element %d not found\n", key);
}

/* ========== MAIN FUNCTION ========== */

int main() {
    int choice;
    int val;
    int pos;

    do {
        printf("\n===== DOUBLY LINKED LIST MENU =====\n");
        printf("1. Insert by position\n");
        printf("2. Delete rear\n");
        printf("3. Delete at position\n");
        printf("4. Search by value\n");
        printf("5. Display list\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPos(val, pos);
        }

        if (choice == 2) {
            deleteRear();
        }

        if (choice == 3) {
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPos(pos);
        }

        if (choice == 4) {
            printf("Enter value to search: ");
            scanf("%d", &val);
            search(val);
        }

        if (choice == 5) {
            display();
        }

    } while (choice != 0);

    return 0;
}
