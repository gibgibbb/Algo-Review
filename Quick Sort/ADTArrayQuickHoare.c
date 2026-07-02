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

//int hoarePartition(ArrADT *A, int low, int high){
//	int pivot = A->data[low];
//	int x = low - 1;
//	int y = high + 1;
//	int temp;
//	
//	while(1){
//		do{
//			x++;
//		} while(A->data[x] < pivot);
//
//		do{
//			y--;
//		} while (A->data[y] > pivot);
//		
//		if(x >= y){
//			return y;
//		}
//		
//		temp = A->data[x];
//		A->data[x] = A->data[y];
//		A->data[y] = temp;
//	}
//}

int hoarePartition(ArrADT *A, int low, int high){
	int pivot = A->data[low];
	int x = low - 1;
	int y = high + 1;
	int temp;
	
	while(1) {
		do {
			x++;
		} while (A->data[x] < pivot);
		
		do {
			y--;
		} while (A->data[y] > pivot);
		
		if(x >= y){
			return y;
		}
		
		temp = A->data[x];
		A->data[x] = A->data[y];
		A->data[y] = temp;
	}
}

void quickSortHoare(ArrADT *A, int low, int high){
	if(low < high){
		int p = hoarePartition(A, low, high);
		
		quickSortHoare(A, low, p);
		quickSortHoare(A, p + 1, high);
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

	quickSortHoare(&A, 0, A.count);
	display(A);

	return 0;
}
