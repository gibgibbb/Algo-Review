#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *left, *right;
} *LinkedList, *BST;

void insertBST(BST *T, char elem) {
    BST *trav, temp;
    for(trav = T; *trav != NULL && (*trav)->data != elem;){
        trav = (elem < (*trav)->data) ? &(*trav)->left : &(*trav)->right;
    }
    if(*trav == NULL){
        temp = (BST)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->data = elem;
            temp->left = temp->right = NULL;
            *trav = temp;
        }
    }
}

LinkedList bstToLinkedList(BST *T) {
	LinkedList retVal = NULL;

	if(*T != NULL){
		LinkedList left = bstToLinkedList(&(*T)->left);

		LinkedList temp = malloc(sizeof(struct node));

		if(temp != NULL){
			LinkedList right = bstToLinkedList(&(*T)->right);

			temp->data = (*T)->data;
			temp->left = NULL;
			temp->right = right;

			if(left != NULL){
				LinkedList trav = left;
				for(;trav->right != NULL; trav = trav->right){}
				trav->right = temp;
				retVal = left;
			} else {
				retVal = temp;
			}
		}
		free(*T);
		*T = NULL;
	}

	return retVal;
}

void displayList(LinkedList L) {
    LinkedList trav = L;
    while (trav != NULL) {
        printf("%c -> ", trav->data);
        trav = trav->right; // 'right' is used as the 'next' pointer
    }
    printf("NULL\n");
}

// --- Main Execution ---
int main() {
    BST T = NULL;
    LinkedList L = NULL;

    // Populating the BST
    insertBST(&T, 'M');
    insertBST(&T, 'B');
    insertBST(&T, 'Z');
    insertBST(&T, 'A');
    insertBST(&T, 'G');
    insertBST(&T, 'T');
    insertBST(&T, 'Y');

    printf("Converting BST to Singly Linked List...\n");

    // Convert the BST, delete its old nodes, and return the new list
    L = bstToLinkedList(&T);

    // Verify it is alphabetically ordered
    printf("Resulting Alphabetical List: \n");
    displayList(L);

    // Verify original BST is empty
    if (T == NULL) {
        printf("\nOriginal BST pointer successfully nullified and memory freed.\n");
    }

    return 0;
}
