#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

/* Function prototypes */
struct Node* insert(struct Node*, int);
struct Node* deleteNode(struct Node*, int);
struct Node* findMin(struct Node*);
void inorder(struct Node*);
void preorder(struct Node*);
void postorder(struct Node*);
void levelOrder(struct Node*);

/* Queue for BFS */
struct Node* q[50];
int f = -1, r = -1;

/* MAIN */
int main()
{
    struct Node *root = NULL;
    int ch, key;

    do {
        printf("\n--- BST MENU ---");
        printf("\n1. Insert");
        printf("\n2. DFS Traversals");
        printf("\n3. BFS Traversal");
        printf("\n4. Search & Delete");
        printf("\n0. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;

            case 2:
                if(!root) { printf("Tree empty\n"); break; }
                printf("Inorder: "); inorder(root);
                printf("\nPreorder: "); preorder(root);
                printf("\nPostorder: "); postorder(root);
                printf("\n");
                break;

            case 3:
                if(!root) { printf("Tree empty\n"); break; }
                printf("Level Order: ");
                levelOrder(root);
                printf("\n");
                break;

            case 4:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
        }
    } while(ch != 0);

    return 0;
}

/* INSERT */
struct Node* insert(struct Node *root, int key)
{
    if(root == NULL) {
        struct Node *t = malloc(sizeof(struct Node));
        t->data = key;
        t->left = t->right = NULL;
        return t;
    }
    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);

    return root;
}

/* DELETE */
struct Node* deleteNode(struct Node *root, int key)
{
    if(root == NULL) {
        printf("Key not found\n");
        return root;
    }

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        if(root->left == NULL) {
            struct Node *t = root->right;
            free(root);
            printf("Deleted\n");
            return t;
        }
        else if(root->right == NULL) {
            struct Node *t = root->left;
            free(root);
            printf("Deleted\n");
            return t;
        }

        struct Node *t = findMin(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

struct Node* findMin(struct Node *root)
{
    while(root->left)
        root = root->left;
    return root;
}

/* DFS */
void inorder(struct Node *root)
{
    if(root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if(root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if(root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* BFS */
void levelOrder(struct Node *root)
{
    struct Node *t;
    f = r = 0;
    q[r] = root;

    while(f <= r) {
        t = q[f++];
        printf("%d ", t->data);
        if(t->left)  q[++r] = t->left;
        if(t->right) q[++r] = t->right;
    }
}
