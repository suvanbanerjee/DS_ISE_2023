#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the front of the doubly linked list
struct Node* addToFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

// Function to insert a new node to the left of the node with a given key
struct Node* insertToLeft(struct Node* head, int key, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        printf("List is empty. Cannot insert to the left.\n");
        return head;
    }

    struct Node* current = head;

    // Find the node with the given key
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with key %d not found. Cannot insert to the left.\n", key);
        return head;
    }

    // Insert the new node to the left
    if (current->prev != NULL) {
        current->prev->next = newNode;
        newNode->prev = current->prev;
    } else {
        head = newNode;
    }

    newNode->next = current;
    current->prev = newNode;

    return head;
}

// Function to delete a node with a given data
struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    struct Node* current = head;

    // Find the node with the given data
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found. Cannot delete.\n", data);
        return head;
    }

    // Adjust the pointers to skip the current node
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);

    printf("Node with data %d deleted.\n", data);

    return head;
}

// Function to display the contents of the doubly linked list
void displayList(struct Node* head) {
    printf("\nDoubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the doubly linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, key, data;

    do {
        printf("\nOperations:\n");
        printf("1. Add to Front\n");
        printf("2. Insert to Left\n");
        printf("3. Delete Node\n");
        printf("4. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add to front: ");
                scanf("%d", &data);
                head = addToFront(head, data);
                break;

            case 2:
                printf("Enter key value: ");
                scanf("%d", &key);
                printf("Enter data to insert to the left: ");
                scanf("%d", &data);
                head = insertToLeft(head, key, data);
                break;

            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;

            case 4:
                displayList(head);
                break;

            case 0:
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    // Free the memory allocated for the doubly linked list
    freeList(head);

    return 0;
}
