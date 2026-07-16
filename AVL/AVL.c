#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} Node, *AVL;

// --- Helper Functions ---

void initAVL(AVL *T) {
    *T = NULL;
}

int max(int a, int b) {
    int retVal = a;
    if (b > a) {
        retVal = b;
    }
    return retVal;
}

// Provided height function following the positive condition & single return rule
int height(AVL T) {
    int retVal = 0;
    if (T != NULL) {
        retVal = T->height;
    }
    return retVal;
}

int getBalance(AVL T) {
    int retVal = 0;
    if (T != NULL) {
        retVal = height(T->left) - height(T->right);
    }
    return retVal;
}

AVL createNode(int data) {
    AVL newNode = (AVL)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1; // New nodes are added as leaves
    }
    return newNode;
}

// --- Rotation Functions ---

AVL rightRotate(AVL y) {
    AVL x = NULL;
    if (y != NULL && y->left != NULL) {
        x = y->left;
        AVL T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
    }
    return x;
}

AVL leftRotate(AVL x) {
    AVL y = NULL;
    if (x != NULL && x->right != NULL) {
        y = x->right;
        AVL T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
    }
    return y;
}

// --- Void Insertion Function ---

void insertElem(AVL *T, int data) {
    if (*T == NULL) {
        *T = createNode(data);
    } else {
        // Standard BST Insertion
        if (data < (*T)->data) {
            insertElem(&((*T)->left), data);
        } else if (data > (*T)->data) {
            insertElem(&((*T)->right), data);
        }

        // Update height of the current node
        (*T)->height = max(height((*T)->left), height((*T)->right)) + 1;

        // Get the balance factor to check if it became unbalanced
        int balance = getBalance(*T);

        // Positive conditions to handle Rotations
        if (balance > 1) {
            // Left Left Case
            if (data < (*T)->left->data) {
                *T = rightRotate(*T);
            }
            // Left Right Case
            else if (data > (*T)->left->data) {
                (*T)->left = leftRotate((*T)->left);
                *T = rightRotate(*T);
            }
        } else if (balance < -1) {
            // Right Right Case
            if (data > (*T)->right->data) {
                *T = leftRotate(*T);
            }
            // Right Left Case
            else if (data < (*T)->right->data) {
                (*T)->right = rightRotate((*T)->right);
                *T = leftRotate(*T);
            }
        }
    }
}

// --- Traversal for Verification ---

void preOrder(AVL T) {
    if (T != NULL) {
        printf("%d ", T->data);
        preOrder(T->left);
        preOrder(T->right);
    }
}

// --- Main Execution ---

int main() {
    AVL root;
    initAVL(&root);

    // Populating the tree exactly as requested
    insertElem(&root, 20);
    insertElem(&root, 10);
    insertElem(&root, 5);  // Will trigger a Right Rotation
    insertElem(&root, 25);
    insertElem(&root, 30); // Will trigger a Left Rotation

    printf("Pre-order traversal of the populated AVL tree:\n");
    preOrder(root);
    printf("\n");

    return 0;
}
