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

void selectionSort(ArrADT *A){
	int x, y, min, temp;
	for(x = 0; x < A->count; x++){
		min = x;
		for(y = x + 1; y <= A->count; y++){
			if(A->data[y] < A->data[min]){
				min = y;
			}
		}
		if(min != x){
			temp = A->data[x];
			A->data[x] = A->data[min];
			A->data[min] = temp;
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

	selectionSort(&A);
	display(A);

	return 0;
}
