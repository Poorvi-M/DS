#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

/* Function prototypes */
struct Node* insert(struct Node*, int);
void inorder(struct Node*);
void preorder(struct Node*);
void postorder(struct Node*);
void levelOrder(struct Node*);
void findMaxWithParent(struct Node*);
int countNodes(struct Node*);
int height(struct Node*);

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
        printf("\n1. Insert (Construction)");
        printf("\n2. DFS Traversals");
        printf("\n3. BFS Traversal");
        printf("\n4. Find Maximum with Parent");
        printf("\n5. Count Nodes");
        printf("\n6. Find Height");
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
                findMaxWithParent(root);
                break;

            case 5:
                printf("Total nodes = %d\n", countNodes(root));
                break;

            case 6:
                printf("Height = %d\n", height(root));
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

/* MAX NODE WITH PARENT */
void findMaxWithParent(struct Node *root)
{
    if(root == NULL) {
        printf("Tree empty\n");
        return;
    }

    struct Node *parent = NULL;
    struct Node *curr = root;

    while(curr->right != NULL) {
        parent = curr;
        curr = curr->right;
    }

    printf("Maximum node = %d\n", curr->data);
    if(parent)
        printf("Parent = %d\n", parent->data);
    else
        printf("Parent does not exist (root)\n");
}

/* COUNT NODES */
int countNodes(struct Node *root)
{
    if(root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/* HEIGHT */
int height(struct Node *root)
{
    if(root == NULL)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh ? lh : rh) + 1;
}
