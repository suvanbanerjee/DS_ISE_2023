#include <stdio.h>

#define MAX_SIZE 100

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify operation (max heap)
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as the root
    int leftChild = 2 * i + 1; // Left child
    int rightChild = 2 * i + 2; // Right child

    // If left child is larger than root
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    // If right child is larger than the largest so far
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    // If the largest is not the root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Function to insert a new element into the max heap
void insertIntoHeap(int arr[], int *n, int element) {
    if (*n == MAX_SIZE) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    // Insert the new element at the end
    (*n)++;
    int i = *n - 1;
    arr[i] = element;

    // Perform heapify operation to maintain max heap property
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to display the array representation of the max heap
void displayMaxHeap(int arr[], int n) {
    printf("Max Heap Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int heap[MAX_SIZE];
    int n = 0; // Number of elements in the heap

    // Insert elements into the max heap
    printf("Enter elements to insert into the max heap (enter -1 to stop):\n");
    int element;
    while (1) {
        scanf("%d", &element);
        if (element == -1) {
            break;
        }
        insertIntoHeap(heap, &n, element);
    }

    // Display the array representation of the max heap
    displayMaxHeap(heap, n);

    return 0;
}
