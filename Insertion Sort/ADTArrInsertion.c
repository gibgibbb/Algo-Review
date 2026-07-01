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

void insertionSort(ArrADT *A){
	int x, y, temp;
	for(x = 1; x <= A->count; x++){
		temp = A->data[x];
		for(y = x - 1; y >= 0 && A->data[y] > temp; y--){
			A->data[y + 1] = A->data[y];
		}
		A->data[y + 1] = temp;
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
	
	insertionSort(&A);
	display(A);
	
	return 0;
}
