#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *left, *right;
} *BST;

void init(BST *T){
	*T = NULL;
}

void insertElem(BST *T, int elem){
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

void deleteElem(BST *T, int elem){
	BST *trav, temp;
	for(trav = T; *trav != NULL && (*trav)->data != elem;){
		trav = (elem < (*trav)->data) ? &(*trav)->left : &(*trav)->right;
	}
	if(*trav != NULL){
		temp = *trav;
		if(temp->left != NULL && temp->right != NULL){ // if right ako understanding, this means two children
			BST *curr;
			for(curr = &temp->left; *curr != NULL && (*curr)->right != NULL; curr = &(*curr)->right){}
			temp->data = (*curr)->data;
			temp = *curr;
			*curr = temp->left;
		} else {
			*trav = (temp->left != NULL) ? (*trav)->left : (*trav)->right;
		}
		free(temp);
	}
}

void inOrder(BST T){
	if(T != NULL){
		inOrder(T->left);
		printf("%d ", T->data);
		inOrder(T->right);
	}
}

int main(){
	
	BST T;
	
	init(&T);
	
	insertElem(&T, 20);
	insertElem(&T, 10);
	insertElem(&T, 5);
	insertElem(&T, 25);
	insertElem(&T, 30);
	
	inOrder(T);
	printf("\n");
	
	deleteElem(&T, 10);
	printf("deleted 10\n");
	inOrder(T);
	
	return 0;
}
