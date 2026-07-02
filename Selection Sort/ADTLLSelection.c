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

//void selectionSortList(ADTLL *LL){
//	ADTLL curr, trav, min;
//	int temp;
//	
//	if(*LL != NULL){
//		for(curr = *LL; curr != NULL; curr = curr->next){
//			min = curr;
//			for(trav = curr->next; trav != NULL; trav = trav->next){
//				if(trav->data < min->data){
//					min = trav;
//				}
//			}
//			if(min != curr){
//				temp = curr->data;
//				curr->data = min->data;
//				min->data = temp;
//			}
//		}
//	}
//}

void selectionSortList(ADTLL *LL){
	ADTLL curr, trav, min;
	int temp;
	for(curr = *LL; curr != NULL; curr = curr->next){
		min = curr;
		for(trav = curr->next; trav != NULL; trav = trav->next){
			if(trav->data < min->data){
				min = trav;
			}
		}
		if(min != curr){
			temp = curr->data;
			curr->data = min->data;
			min->data = temp;
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

	selectionSortList(&LL);
	displayList(LL);

	return 0;
}
