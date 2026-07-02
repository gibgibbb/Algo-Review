#include <stdio.h>
#define MAX 10

typedef struct{
    int data[MAX];
    int count;
}ArrADT;

void init(ArrADT *A){
	A->count = -1;
}

void insertFirst(ArrADT *A, int val){
	int x;
	if(A->count < MAX){
		for(x = A->count; x >= 0; x--){
			A->data[x + 1] = A->data[x];
		}
		A->data[0] = val;
		A->count++;
	}
}

//void combSort(ArrADT *A){
//	int gap = A->count + 1;
//	int x, temp, swapped = 1;
//	while(gap != 1 || swapped != 0){
//		gap = (gap * 10) / 13;
//		
//		if(gap < 1){
//			gap = 1;
//		}
//		
//		swapped = 0;
//		
//		for(x = 0; x < A->count + 1 - gap; x++){
//			if(A->data[x] > A->data[x + gap]){
//				temp = A->data[x];
//				A->data[x] = A->data[x + gap];
//				A->data[x + gap] = temp;
//				swapped = 1;
//			}
//		}
//	}
//}

void combSort(ArrADT *A){
	int gap = A->count + 1;
	int x, temp, swapped = 1;
	while(gap != 1 || swapped != 0){
		gap = (gap * 10) / 13;
		
		if(gap < 1){
			gap = 1;
		}
		
		swapped = 0;
		
		for(x = 0; x <= A->count - gap; x++){
			if(A->data[x] > A->data[x + gap]){
				temp = A->data[x];
				A->data[x] = A->data[x + gap];
				A->data[x + gap] = temp;
				swapped = 1;
			}
		}
	}
}

void display(ArrADT A){
	int x;
	for(x = 0; x <= A.count; x++){
		printf("%d ", A.data[x]);
	}
}

int main(){

	ArrADT A;

	init(&A);

	insertFirst(&A, 5);
	insertFirst(&A, 2);
	insertFirst(&A, 100);
	insertFirst(&A, 30);
	insertFirst(&A, 19);

	combSort(&A);
	display(A);

	return 0;
}
