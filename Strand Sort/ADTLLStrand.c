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

ADTLL merge(ADTLL A, ADTLL B){

    ADTLL dummy;
    ADTLL tail = dummy;

    dummy->next = NULL;

    while(A != NULL && B != NULL){

        if(A->data <= B->data){
            tail->next = A;
            A = A->next;
        }else{
            tail->next = B;
            B = B->next;
        }

        tail = tail->next;
    }

    if(A != NULL){
        tail->next = A;
    }else{
        tail->next = B;
    }

    return dummy->next;
}

ADTLL strandSort(ADTLL *head){

    ADTLL sorted = NULL;

    while(*head != NULL){

        ADTLL strand = *head;
        ADTLL curr = *head;
        ADTLL prev = NULL;

        *head = (*head)->next;
        strand->next = NULL;

        while(*head != NULL){

            if((*head)->data >= curr->data){

                ADTLL temp = *head;

                if(prev == NULL){
                    *head = (*head)->next;
                }else{
                    prev->next = (*head)->next;
                    *head = (*head)->next;
                }

                temp->next = NULL;

                curr->next = temp;
                curr = temp;

            }else{

                prev = *head;
                *head = (*head)->next;

            }
        }

        sorted = merge(sorted, strand);

        *head = *head;
    }

    return sorted;
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

	strandSort(&LL);
	display(LL);

	return 0;
}
