#include <stdio.h>
#include <stdlib.h>

typedef enum{
    RED,
    BLACK
}Color;

typedef struct node{
    int data;
    Color color;
    struct node *left;
    struct node *right;
    struct node *parent;
}Node, *RBTree;

RBTree createNode(int elem){
	RBTree temp;
	
	temp = (RBTree)malloc(sizeof(struct node));
	if(temp != NULL){
		temp->data = elem;
		temp->color = RED;
		temp->left = temp->right = NULL;
		temp->parent = NULL;
	}
	
	return temp;
}

RBTree leftRotate(RBTree root, RBTree x){
    RBTree y;

    y = x->right;
    x->right = y->left;

    if(y->left != NULL){
        y->left->parent = x;
    }

    y->parent = x->parent;

    if(x->parent == NULL){
        root = y;
    } else if(x == x->parent->left){
        x->parent->left = y;
    } else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;

    return root;
}

int main(){
	
	return 0;
}
