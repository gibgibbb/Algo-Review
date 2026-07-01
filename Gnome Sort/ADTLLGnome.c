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

void gnomeSortList(ADTLL *LL){
	ADTLL pos;
	int temp;
	if(*LL != NULL){
		pos = (*LL)->next;
		
		for(;pos != NULL;){
			if(pos->prev == NULL || pos->data >= pos->prev->data){
				pos = pos->next;
			} else {
				temp = pos->data;
				pos->data = pos->prev->data;
				pos->prev->data = temp;
				pos = pos->prev;
			}
		}
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
	
	gnomeSortList(&LL);
	display(LL);
	
	return 0;
}
