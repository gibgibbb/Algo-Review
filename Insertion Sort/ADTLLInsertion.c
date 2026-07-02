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

//void insertionSortList(ADTLL *LL){
//	ADTLL curr, trav;
//	int temp;
//	if(*LL != NULL){
//		for(curr = (*LL)->next; curr != NULL; curr = curr->next){
//			temp = curr->data;
//			for(trav = *LL; trav != NULL; trav = trav->next){
//				if(trav->data > temp){
//					int holder = trav->data;
//					trav->data = temp;
//					temp = holder;
//				}
//			}
//			curr->data = temp;
//		}
//	}
//}

void insertionSortList(ADTLL *LL){
	ADTLL trav, curr;
	int temp;
	for(curr = (*LL)->next; curr != NULL; curr = curr->next){
		temp = curr->data;
		for(trav = *LL; trav != NULL; trav = trav->next){
			if(trav->data > temp){
				int holder = trav->data;
				trav->data = temp;
				temp = holder;
			}
		}
		curr->data = temp;
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

	insertionSortList(&LL);
	displayList(LL);

	return 0;
}
