#include <stdio.h>
#include <limits.h>
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

int findMin(ArrADT *A){
	int x;
	int min = 0;
	for(x = 0; x <= A->count; x++){
		if(A->data[x] < A->data[min]){
			min = x;
		}
	}
	return min;
}

//void tournamentSortSimple(ArrADT *A){
//	int output[MAX];
//	int x;
//	int minNdx;
//
//	for(x = 0; x <= A->count; x++){
//		minNdx = findMin(A);
//		output[x] = A->data[minNdx];
//		A->data[minNdx] = INT_MAX;
//	}
//
//	for(x = 0; x <= A->count; x++){
//		A->data[x] = output[x];
//	}
//}

void tournamentSortSimple(ArrADT *A){
	int output[MAX];
	int x, y;
	int minNdx;
	
	for(x = 0; x <= A->count; x++){
		minNdx = 0;
		for(y = 0; y <= A->count; y++){
			if(A->data[y] < A->data[minNdx]){
				minNdx = y;
			}
		}
		output[x] = A->data[minNdx];
		A->data[minNdx] = INT_MAX;
	}
	
	for(x = 0; x <= A->count; x++){
		A->data[x] = output[x];
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

	tournamentSortSimple(&A);
	display(A);

	return 0;
}
