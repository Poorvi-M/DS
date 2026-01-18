#include <stdio.h>
#include <stdlib.h>

/* FUNCTION DECLARATIONS */
int* readArray(int *arr, int *n);
void displayArray(int *arr, int n);
int* insertByPosition(int *arr, int *n, int pos, int val);
int* deleteByKey(int *arr, int *n, int key);
void searchByPosition(int *arr, int n, int pos);
void reverseArray(int *arr, int n);

/* MAIN FUNCTION */
int main()
{
    int *arr = NULL;
    int n = 0;
    int choice, pos, val, key;

    do
    {
        printf("\n===== LP-2 : DYNAMIC ARRAY MENU =====");
        printf("\n1. Read Array");
        printf("\n2. Display Array");
        printf("\n3. Insert by Position");
        printf("\n4. Delete by Key");
        printf("\n5. Search by Position");
        printf("\n6. Reverse Array");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                arr = readArray(arr, &n);
                break;

            case 2:
                displayArray(arr, n);
                break;

            case 3:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                arr = insertByPosition(arr, &n, pos, val);
                break;

            case 4:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                arr = deleteByKey(arr, &n, key);
                break;

            case 5:
                printf("Enter position to search: ");
                scanf("%d", &pos);
                searchByPosition(arr, n, pos);
                break;

            case 6:
                reverseArray(arr, n);
                printf("Array reversed.\n");
                break;

            case 0:
                free(arr);
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 0);

    return 0;
}

/* FUNCTION DEFINITIONS */

int* readArray(int *arr, int *n)
{
    int i;
    printf("Enter number of elements: ");
    scanf("%d", n);

    arr = (int *)malloc((*n) * sizeof(int));

    printf("Enter elements:\n");
    for(i = 0; i < *n; i++)
        scanf("%d", &arr[i]);

    return arr;
}

void displayArray(int *arr, int n)
{
    int i;
    if(n == 0)
    {
        printf("Array is empty\n");
        return;
    }

    printf("Array elements: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int* insertByPosition(int *arr, int *n, int pos, int val)
{
    int i;
    if(pos < 0 || pos > *n)
    {
        printf("Invalid position\n");
        return arr;
    }

    arr = (int *)realloc(arr, (*n + 1) * sizeof(int));

    for(i = *n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = val;
    (*n)++;

    printf("Element inserted.\n");
    return arr;
}

int* deleteByKey(int *arr, int *n, int key)
{
    int i, found = 0;

    for(i = 0; i < *n; i++)
    {
        if(arr[i] == key)
        {
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("Key not found\n");
        return arr;
    }

    for(; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;

    arr = (int *)realloc(arr, (*n) * sizeof(int));

    printf("Element deleted.\n");
    return arr;
}

void searchByPosition(int *arr, int n, int pos)
{
    if(pos < 0 || pos >= n)
    {
        printf("Invalid position\n");
        return;
    }

    printf("Element at position %d is %d\n", pos, arr[pos]);
}

void reverseArray(int *arr, int n)
{
    int i, temp;
    for(i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
