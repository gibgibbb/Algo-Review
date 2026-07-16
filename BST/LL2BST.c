#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *prev, *next; // prev acts as 'left', next acts as 'right'
} *BST;

void init(BST *T) {
    *T = NULL;
}

// Helper function to insert into the Linked List (Appends to the end)
// Rule 1 & 2 applied: Positive checks, no early returns
void insertList(BST *head, char elem) {
    BST temp = (BST)malloc(sizeof(struct node));
    if (temp != NULL) {
        temp->data = elem;
        temp->next = NULL;
        temp->prev = NULL;

        if (*head == NULL) {
            *head = temp;
        } else {
            BST trav = *head;
            while (trav->next != NULL) {
                trav = trav->next;
            }
            trav->next = temp;
            temp->prev = trav; // Creating a doubly linked list connection
        }
    }
}

// Helper to count the number of nodes in the Linked List
// Rule 1 & 2 applied: Positive loop logic, single return
int countNodes(BST head) {
    int count = 0;
    BST trav = head;
    while (trav != NULL) {
        count++;
        trav = trav->next;
    }
    return count;
}

// Recursive function to construct the BST bottom-up
// Rule 1 & 2 applied: Positive block execution, single return at the end
BST listToBSTRecur(BST *head_ref, int n) {
    BST root = NULL;

    if (n > 0) {
        // 1. Recursively construct the left subtree (using prev)
        BST leftSubtree = listToBSTRecur(head_ref, n / 2);

        // 2. Set the current node as the root of this subtree
        root = *head_ref;
        root->prev = leftSubtree; // prev acts as the left child

        // Advance the head pointer down the linked list
        *head_ref = (*head_ref)->next;

        // 3. Recursively construct the right subtree (using next)
        BST rightSubtree = listToBSTRecur(head_ref, n - (n / 2) - 1);
        root->next = rightSubtree; // next acts as the right child
    }

    return root; // Single return statement
}

// Wrapper function to initiate the conversion
void convertListToBST(BST *head) {
    if (*head != NULL) {
        int n = countNodes(*head);

        // We use a separate pointer to traverse so we can safely
        // reassign *head to the newly constructed tree root.
        BST current_head = *head;
        *head = listToBSTRecur(&current_head, n);
    }
}

// Traversal to verify it is a valid Linked List
void displayList(BST head) {
    BST trav = head;
    while (trav != NULL) {
        printf("%c -> ", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
}

// Pre-Order Traversal (Root, Left/Prev, Right/Next) to verify BST structure
void preOrderBST(BST T) {
    if (T != NULL) {
        printf("%c ", T->data);
        preOrderBST(T->prev); // traversing 'left'
        preOrderBST(T->next); // traversing 'right'
    }
}

int main() {
    BST listHead;
    init(&listHead);
    
    insertList(&listHead, 'A');
    insertList(&listHead, 'B');
    insertList(&listHead, 'G');
    insertList(&listHead, 'M');
    insertList(&listHead, 'T');
    insertList(&listHead, 'Y');
    insertList(&listHead, 'Z');

    // Display original Linked List
    printf("Original Linked List:\n");
    displayList(listHead);
    printf("\n");

    // Convert Linked List to a Balanced BST
    convertListToBST(&listHead);

    // If perfectly balanced, 'M' will become the root, 'B' and 'Y' its children, etc.
    // Expected Pre-Order output: M B A G Y T Z
    printf("Converted BST (Pre-Order Traversal):\n");
    preOrderBST(listHead);
    printf("\n");

    return 0;
}
