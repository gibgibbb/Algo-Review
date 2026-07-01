#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}*ADTLL;

void init(ADTLL *LL){
	*LL = NULL;
}

void insertFirst(ADTLL *LL, int val){
	ADTLL temp = malloc(sizeof(struct node));
	if(temp != NULL){
		temp->data = val;
		temp->next = *LL;
		*LL = temp;
	}
}

void bubbleSortList(ADTLL *LL){
	int x, y, count = 0;
	
	ADTLL trav;
	
	for(trav = *LL; trav != NULL; trav = trav->next){
		count++;
	}
	
	for(x = 0; x < count - 1; x++){
		trav = *LL;
		for(y = 0; y < count - x - 1; y++){
			if(trav->data > trav->next->data){
				int temp = trav->data;
				trav->data = trav->next->data;
				trav->next->data = temp;
			}
			trav = trav->next;
		}
	}
}

void displayList(ADTLL LL){
	for(; LL != NULL; LL = LL->next){
		printf("%d ", LL->data);
	}
}

int main(){
	
	ADTLL LL;
	
	init(&LL);
	
	insertFirst(&LL, 1);
	insertFirst(&LL, 5);
	insertFirst(&LL, 10);
	insertFirst(&LL, 8);
	
	bubbleSortList(&LL);
	displayList(LL);
	
	return 0;
}
