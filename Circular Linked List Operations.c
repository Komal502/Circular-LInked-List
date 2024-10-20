#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *s = NULL;

// Function to insert a node at the beginning of the circular linked list
struct node* Insert_Beg(struct node *top) {
    struct node *r = (struct node*)malloc(sizeof(struct node));  // Corrected memory allocation
    if (r == NULL) {
        printf("Memory allocation failed!\n");
        return top;
    }

    printf("Enter data: ");
    scanf("%d", &r->data);

    if (top == NULL) {
        r->next = r;  // Circular link to itself
        return r;
    }

    struct node *t = top;
    while (t->next != top) {
        t = t->next;  // Traverse to the last node
    }
    t->next = r;  // Last node now points to the new node
    r->next = top;  // New node points to the old head

    return r;  // Return the new node as the new head
}

// Function to insert a node at the end of the circular linked list
struct node* Insert_End(struct node *top) {
    struct node *r = (struct node*)malloc(sizeof(struct node));  // Corrected memory allocation
    if (r == NULL) {
        printf("Memory allocation failed!\n");
        return top;
    }

    printf("Enter data: ");
    scanf("%d", &r->data);

    if (top == NULL) {
        r->next = r;  // Circular link to itself
        return r;
    }

    struct node *t = top;
    while (t->next != top) {
        t = t->next;  // Traverse to the last node
    }

    t->next = r;  // Last node points to the new node
    r->next = top;  // New node points to the head

    return top;  // Return the unchanged head
}

// Function to delete the node at the beginning of the circular linked list
struct node* Delete_Beg(struct node *top) {
    if (top == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (top->next == top) {
        free(top);
        return NULL;  // List is now empty
    }

    struct node *r = top;
    struct node *last = top;
    while (last->next != top) {
        last = last->next;  // Traverse to the last node
    }

    last->next = top->next;  // Last node points to the second node
    free(top);  // Free the old head
    top = last->next;  // Update the head

    return top;
}

// Function to delete the node at the end of the circular linked list
struct node* Delete_End(struct node *top) {
    if (top == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    if (top->next == top) {
        free(top);
        return NULL;  // List is now empty
    }

    struct node *r = top;
    struct node *t = NULL;
    while (r->next != top) {
        t = r;
        r = r->next;  // Traverse to the second-last node
    }

    t->next = top;  // Second-last node points to the head
    free(r);  // Free the last node

    return top;
}

// Function to display the circular linked list
void Display_List(struct node *top) {
    if (top == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *current = top;
    do {
        printf("%d\t", current->data);
        current = current->next;
    } while (current != top);
    printf("\n");
}

int main() {
    struct node *p, *q;
    char ch;
    int op;

    // Create the circular linked list initially
    printf("Enter the first node data: ");
    p = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &p->data);
    s = p;
    p->next = s;  // First node points to itself

    // Ask if user wants to continue adding nodes
    printf("Do you want to add more nodes? (y/n): ");
    ch = getchar();  // Consume the newline from previous input
    ch = getchar();  // Read actual input

    while (ch == 'y' || ch == 'Y') {
        q = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for next node: ");
        scanf("%d", &q->data);
        p->next = q;  // Previous node points to the new node
        q->next = s;  // New node points to the head
        p = q;  // Move to the new node

        printf("Do you want to add more nodes? (y/n): ");
        ch = getchar();  // Consume the newline from previous input
        ch = getchar();  // Read actual input
    }

    // Now show the operations menu
    do {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                s = Insert_Beg(s);
                printf("Current list: ");
                Display_List(s);
                break;
            case 2:
                s = Insert_End(s);
                printf("Current list: ");
                Display_List(s);
                break;
            case 3:
                s = Delete_Beg(s);
                printf("Current list: ");
                Display_List(s);
                break;
            case 4:
                s = Delete_End(s);
                printf("Current list: ");
                Display_List(s);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, try again.\n");
        }
    } while (op != 5);

    return 0;
}
