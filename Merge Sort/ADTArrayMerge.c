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

void merge(ArrADT *A, int left, int mid, int right){
	int temp[MAX];
	int x = left;
	int y = mid + 1;
	int z = left;
	
	while(x <= mid && y <= right){
		if(A->data[x] < A->data[y]){
			temp[z++] = A->data[x++];
		} else {
			temp[z++] = A->data[y++];
		}
	}
	
	while(x <= mid){
		temp[z++] = A->data[x++];
	}
	
	while(y <= right){
		temp[z++] = A->data[y++];
	}
	
	for(x = left; x <= right; x++){
		A->data[x] = temp[x];
	}
}

//void mergeSort(ArrADT *A, int left, int right){
//	if(left < right){
//		int mid = (left + right) / 2;
//		mergeSort(A, left, mid);
//		mergeSort(A, mid + 1, right);
//		merge(A, left, mid, right);
//	}
//}

void mergeSort(ArrADT *A, int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid + 1, right);
		merge(A, left, mid, right);
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

	mergeSort(&A, 0, A.count);
	display(A);

	return 0;
}
