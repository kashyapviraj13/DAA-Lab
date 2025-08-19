#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    // Taking size of array from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Taking elements of array from user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("Original array: ");
    printArray(arr, n);

    // Sorting the array using Bubble Sort
    bubbleSort(arr, n);

    // Display sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
