#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    struct Node* current = head;
    struct Node* index = NULL;
    int temp;

    if (head == NULL) {
        return;
    } 
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
               
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev;  
        prev = current;        
        current = next;
    }
    *head = prev;  
}
void concatenateLists(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, data, n;

    do {
        printf("\nMenu:\n");
        printf("1. Append elements to the first linked list\n");
        printf("2. Append elements to the second linked list\n");
        printf("3. Sort the first linked list\n");
        printf("4. Reverse the first linked list\n");
        printf("5. Concatenate the two linked lists\n");
        printf("6. Print the first linked list\n");
        printf("7. Print the second linked list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements for the first linked list: ");
                scanf("%d", &n);
                printf("Enter the elements for the first linked list:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    append(&list1, data);
                }
                break;

            case 2:
                printf("Enter the number of elements for the second linked list: ");
                scanf("%d", &n);
                printf("Enter the elements for the second linked list:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    append(&list2, data);
                }
                break;

            case 3:
                sortList(list1);
                printf("The first linked list has been sorted.\n");
                break;

            case 4:
                reverseList(&list1);
                printf("The first linked list has been reversed.\n");
                break;

            case 5:
                concatenateLists(&list1, list2);
                printf("The two linked lists have been concatenated.\n");
                break;

            case 6:
                printf("First Linked List: ");
                printList(list1);
                break;

            case 7:
                printf("Second Linked List: ");
                printList(list2);
                break;

            case 8:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}