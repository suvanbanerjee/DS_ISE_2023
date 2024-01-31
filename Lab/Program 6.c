#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new element at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Set the data and next pointer of the new node
    newNode->data = value;
    newNode->next = head;

    // Update the head to point to the new node
    head = newNode;

    printf("Element %d inserted at the beginning.\n", value);

    return head;
}

// Function to delete an element from the linked list
struct Node* deleteElement(struct Node* head, int value) {
    // If the list is empty, nothing to delete
    if (head == NULL) {
        printf("List is empty. Cannot delete element.\n");
        return head;
    }

    // If the element to be deleted is the first element
    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Element %d deleted from the list.\n", value);
        return head;
    }

    // Traverse the list to find the element to be deleted
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    // If the element is not found
    if (current == NULL) {
        printf("Element %d not found in the list.\n", value);
        return head;
    }

    // Element found, delete it
    prev->next = current->next;
    free(current);
    printf("Element %d deleted from the list.\n", value);

    return head;
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert elements at the beginning
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    // Display the initial linked list
    displayList(head);

    // Delete an element from the list
    head = deleteElement(head, 20);

    // Display the updated linked list
    displayList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
