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

//int lomutoPartition(ArrADT *A, int low, int high){
//	int pivot = A->data[high];
//	int x = low - 1;
//	int y;
//	int temp;
//
//	for(y = low; y < high; y++){
//		if(A->data[y] <= pivot){
//			x++;
//			temp = A->data[x];
//			A->data[x] = A->data[y];
//			A->data[y] = temp;
//		}
//	}
//
//	temp = A->data[x + 1];
//	A->data[x + 1] = A->data[high];
//	A->data[high] = temp;
//
//	return x + 1;
//}

int lomutoPartition(ArrADT *A, int low, int high){
	int pivot = A->data[high];
	int x = low - 1;
	int y, temp;
	
	for(y = low; y < high; y++){
		if(A->data[y] <= pivot){
			x++;
			temp = A->data[x];
			A->data[x] = A->data[y];
			A->data[y] = temp;
		}
	}
	temp = A->data[x + 1];
	A->data[x + 1] = A->data[high];
	A->data[high] = temp;
	
	return x + 1;
}

void quickSortLomuto(ArrADT *A, int low, int high){
	if(low < high){
		int p = lomutoPartition(A, low, high);
		
		quickSortLomuto(A, low, p - 1);
		quickSortLomuto(A, p + 1, high);
	}
}

//void quickSortLomuto(ArrADT *A, int low, int high){
//	if(low < high){
//		int p = lomutoPartition(A, low, high);
//
//		quickSortLomuto(A, low, p - 1);
//		quickSortLomuto(A, p + 1, high);
//	}
//}

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

	quickSortLomuto(&A, 0, A.count);
	display(A);

	return 0;
}
