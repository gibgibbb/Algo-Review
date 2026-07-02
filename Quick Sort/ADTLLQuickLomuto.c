#include <stdio.h>
#include <stdlib.h>

// Implemented using Doubly Linked List
typedef struct node {
	int data;
	struct node *prev, *next;
}*ADTLL;

void init(ADTLL *LL){
	*LL = NULL;
}

void insertFirst(ADTLL *LL, int val){
	ADTLL temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->data = val;
		temp->prev = NULL;
		temp->next = *LL;

		if(*LL != NULL){
			(*LL)->prev = temp;
		}
		*LL = temp;
	}
}

ADTLL lomutoPartition(ADTLL low, ADTLL high){
	int pivot = high->data;
	
	ADTLL x = low->prev;
	ADTLL y;
	int temp;
	
	for(y = low; y != high; y = y->next){
		if(y->data <= pivot){
			if(x != NULL){
				x = x->next;
			} else {
				x = low;
			}
			
			temp = x->data;
			x->data = y->data;
			y->data = temp;
		}
	}
	
	if(x != NULL){
		x = x->next;
	} else {
		x = low;
	}
	
	temp = x->data;
	x->data = high->data;
	high->data = temp;
	
	return x;
}

void quickSortListLomuto(ADTLL low, ADTLL high){

	if(high != NULL && low != high && low != high->next){
		ADTLL p = lomutoPartition(low, high);
		
		quickSortListLomuto(low, p->prev);
		quickSortListLomuto(p->next, high);
	}

}

void display(ADTLL LL){
	for(;LL != NULL; LL = LL->next){
		printf("%d ", LL->data);
	}
}

int main(){

	ADTLL LL;
	init(&LL);

	insertFirst(&LL, 5);
    insertFirst(&LL, 2);
    insertFirst(&LL, 100);
    insertFirst(&LL, 30);
    insertFirst(&LL, 19);
    
    ADTLL tail = LL;
    while(tail->next != NULL){
        tail = tail->next;
    }

	quickSortListLomuto(LL, tail);
	display(LL);

	return 0;
}
