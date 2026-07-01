#include <stdio.h>
#define MAX 5

typedef struct {
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

void bubbleSort(ArrADT *A){
	int x, y;
	for(x = 0; x < A->count - 1; x++){
		for(y = 0; y < A->count - x - 1; y++){
			if(A->data[y] > A->data[y + 1]){
				int temp = A->data[y];
				A->data[y] = A->data[y + 1];
				A->data[y + 1] = temp;
			}
		}
	}
}

void printSort(ArrADT A){
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
	insertFirst(&A, 3);
	
	//bubbleSort(&A);

	printSort(A);
	
	return 0;
}
