#include <stdio.h>
#include <stdlib.h>

/* FUNCTION DECLARATIONS */
int* insertByOrder(int *arr, int *n, int val);
int* deleteByPosition(int *arr, int *n, int pos);
void searchByKey(int *arr, int n, int key);
void reverseArray(int *arr, int n);
void displayArray(int *arr, int n);

/* MAIN FUNCTION */
int main()
{
    int *arr = NULL;
    int n = 0;
    int choice, val, pos, key;

    do
    {
        printf("\n===== LP-3 : DYNAMIC ORDERED ARRAY MENU =====");
        printf("\n1. Insert by Order");
        printf("\n2. Delete by Position");
        printf("\n3. Search by Key");
        printf("\n4. Reverse Array");
        printf("\n5. Display Array");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                arr = insertByOrder(arr, &n, val);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                arr = deleteByPosition(arr, &n, pos);
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                searchByKey(arr, n, key);
                break;

            case 4:
                reverseArray(arr, n);
                printf("Array reversed.\n");
                break;

            case 5:
                displayArray(arr, n);
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

int* insertByOrder(int *arr, int *n, int val)
{
    int i;
    arr = (int *)realloc(arr, (*n + 1) * sizeof(int));

    for(i = *n - 1; i >= 0 && arr[i] > val; i--)
        arr[i + 1] = arr[i];

    arr[i + 1] = val;
    (*n)++;

    return arr;
}

int* deleteByPosition(int *arr, int *n, int pos)
{
    int i;

    if(pos < 0 || pos >= *n)
    {
        printf("Invalid position\n");
        return arr;
    }

    for(i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;

    arr = (int *)realloc(arr, (*n) * sizeof(int));
    return arr;
}

void searchByKey(int *arr, int n, int key)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Key found at position %d\n", i);
            return;
        }
    }
    printf("Key not found\n");
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
