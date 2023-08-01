#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

int lengthOfNodeList(struct Node** head) {
    struct Node* cursor = *head;
    int count = 0;

    while (cursor != NULL) {
        count++;
        cursor=cursor->nextNode;
    }

    return count;    
}

void insertNodeAtFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* cursor = *head;

    newNode->data = data;
    newNode->nextNode = *head;

    int length = lengthOfNodeList(&cursor);
    if (*head != NULL && length > 1) {
        while (cursor->nextNode != *head) {
            if (cursor->nextNode != NULL) {
                cursor = cursor->nextNode;
            } else {
                break;
            }
        }
        cursor->nextNode = newNode;
    }
    
    *head = newNode;
    printf("%d", newNode->data);
    printf(" -> ");
    if (cursor != NULL) {
        printf("%d", cursor->data);
    }
    else {
        printf("Null");
    }
    printf("\n");
}

void printNodeList(struct Node** cursor) {
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

int main() {
    struct Node* head = NULL;
    
    // Insert At The Front of Circular Linked List.
    insertNodeAtFront(&head, 1);
    insertNodeAtFront(&head, 2);
    insertNodeAtFront(&head, 3);

    // Print count
    //printf("%d", lengthOfNodeList(&head)); //Broken

    // Print Node List
    // printNodeList(&head); //Broken

    return 0;
}