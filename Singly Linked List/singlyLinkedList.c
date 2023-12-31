#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void insertNodeAtFront(struct Node** head, int nodeData) {
    // Allocate Memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Give the Node data and point to the previous head as next
    // Meaning this inserts on the front.
    newNode->data = nodeData;
    newNode->nextNode = *head;

    // Sets this Node as the new Head Node at the front.
    *head = newNode;

    free(newNode);

    // DEBUG
    // Print to show data being added. 
    // printf("%d\n", newNode->data);
    }

void insertNodeAtEnd(struct Node** head, int nodeData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    // Assert New Node Data and Next Node
    newNode->data = nodeData;
    newNode->nextNode = NULL;

    // Check if LL is empty and if so make newNode Head.
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Go to Last Node
    while (temp->nextNode != NULL) {
        temp = temp->nextNode;
    }

    // Change temp to point to newNode
    temp->nextNode = newNode;

    free(newNode);

    // DEBUG
    // Print to show data being added. 
    // printf("%d\n", newNode->data);
    }

void deleteNodes(struct Node** cursor) {
    struct Node* temp = *cursor;
    struct Node* nextNode = NULL;
    
    while (temp != NULL) {
        nextNode = temp->nextNode;
        free(temp);
        temp = nextNode;
    }

    *cursor = NULL;

    free(temp);

    printf("Cleared Node List.\n");
}

void deleteNode(struct Node** cursor, int node) {
    struct Node* previous = *cursor;
    struct Node* current = *cursor;

    if (*cursor == NULL) {
        printf("List is Empty.");
    }
    else if (node == 1) {
        *cursor = current->nextNode;
        free(current);
        current = NULL;
    }
    else {
        while (node != 1) {
            previous = current;
            current = current->nextNode;
            node--;
        }
        previous->nextNode = current->nextNode;
        free(current);
        current = NULL;
    }

    free(previous);
}

void printNodes(struct Node** cursor) {
    struct Node* tempCursor = *cursor;

    while (tempCursor != NULL) {
        printf("%d", tempCursor->data);
        tempCursor = tempCursor->nextNode;
        if (tempCursor != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int checkForNode(struct Node** cursor, int data) {
    struct Node* tempCursor = *cursor;
    bool isFound = false;

    while (tempCursor != NULL) {
        if (tempCursor->data == data) {
            isFound = true;
        }
        tempCursor = tempCursor->nextNode;
    }
    
    if (isFound) {
        printf("Node %d Found.\n", data);
    } else {
        printf("Node %d not found.\n", data);
    }
}

int main() {
    struct Node* head = NULL;

    // Line Break 
    printf("|----Testing----|\n");

    // Testing insertNodeAtFront
    insertNodeAtFront(&head, 0);
    insertNodeAtFront(&head, 1);
    insertNodeAtFront(&head, 2);
    insertNodeAtFront(&head, 3);

    // Print Insert at Front Nodes
    printNodes(&head);
    
    // Clear Node List
    deleteNodes(&head);

    // Testing insertNodeAtEnd
    insertNodeAtEnd(&head, 10);
    insertNodeAtEnd(&head, 11);
    insertNodeAtEnd(&head, 12);
    insertNodeAtEnd(&head, 13);

    // Print the List of Nodes
    printNodes(&head);

    // Does Exist
    checkForNode(&head, 12);
    
    // Does Not Exist
    checkForNode(&head, 26);

    // Delete Node 
    deleteNode(&head, 2);

    // Print the List of Nodes
    printNodes(&head);
    
    // Return
    return 0;
}