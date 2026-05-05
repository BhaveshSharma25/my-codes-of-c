#include <stdio.h>
void acceptArray(int arr[], int n);
void displayArray(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);

int main() {
    int arr[100], n = 0, choice;

    while (1) {
        printf("\n--- Array Operations Menu ---");
        printf("\n1. Accept elements of the array");
        printf("\n2. Display elements of the array");
        printf("\n3. Sort using Insertion Sort");
        printf("\n4. Sort using Selection Sort");
        printf("\n5. Sort using Bubble Sort");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                acceptArray(arr, n);
                break;
            case 2:
                if (n == 0) printf("Array is empty!\n");
                else displayArray(arr, n);
                break;
            case 3:
                if (n == 0) printf("Nothing to sort!\n");
                else {
                    insertionSort(arr, n);
                    printf("Aray sorted using Insertion Sort.\n");
                }
                break;
            case 4:
                if (n == 0) printf("Nothing to sort!\n");
                else {
                    selectionSort(arr, n);
                    printf("Array sorted using Selection Sort.\n");
                }
                break;
            case 5:
                if (n == 0) printf("Nothing to sort!\n");
                else {
                    bubbleSort(arr, n);
                    printf("Array sorted using Bubble Sort.\n");
                }
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void acceptArray(int arr[], int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}