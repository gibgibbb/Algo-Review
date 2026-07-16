#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *left, *right;
} *BST;

typedef struct listNode {
    char data;
    struct listNode *next;
} *LinkedList;

void initBST(BST *T) {
    *T = NULL;
}

void initList(LinkedList *L) {
    *L = NULL;
}

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

void inOrderBST(BST T) {
    if (T != NULL) {
        inOrderBST(T->left);
        printf("%c ", T->data);
        inOrderBST(T->right);
    }
}

// Converts the BST to a Linked List in alphabetical order.
void bstToLinkedList(BST T, LinkedList *L) {
    if (T != NULL) {
        bstToLinkedList(T->right, L); //Right subtree first since it has the larger value elements

        LinkedList temp = (LinkedList)malloc(sizeof(struct listNode));
        if (temp != NULL) {
            temp->data = T->data;
            temp->next = *L;
            *L = temp;
        }

        bstToLinkedList(T->left, L);
    }
}

// if we just want to use the same BST data definition
//void bstToLinkedListBST(BST T, BST *LL){
//	if(T != NULL){
//		bstToLinkedListBST(T->right, LL);
//		
//		BST leftSubtree = T->left;
//		// Rewriting the BST to a LL setup
//		T->right = *LL;
//		T->left = NULL;
//		*LL = T;
//		
//		bstToLinkedListBST(leftSubtree, LL);
//	}
//}

void displayList(LinkedList L) {
    LinkedList trav = L;
    while (trav != NULL) {
        printf("%c -> ", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
}

int main() {
    BST T, LL;
    LinkedList L;

    initBST(&T);
    // initBST(&LL);
    initList(&L);

    insertBST(&T, 'M');
    insertBST(&T, 'B');
    insertBST(&T, 'Z');
    insertBST(&T, 'A');
    insertBST(&T, 'G');
    insertBST(&T, 'T');
    insertBST(&T, 'Y');

    printf("BST (In-Order Traversal): ");
    inOrderBST(T);
    printf("\n\n");

	bstToLinkedList(T, &L);
	// bstToLinkedListBST(T, &LL);

    printf("Converted Linked List (Alphabetical): \n");
    displayList(L);

    return 0;
}
