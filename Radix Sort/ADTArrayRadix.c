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

//void radixSort(ArrADT *A){
//	int max = A->data[0];
//	int x, exp;
//
//	for(x = 0; x <= A->count; x++){
//		if(max < A->data[x]){
//			max = A->data[x];
//		}
//	}
//	
//	for(exp = 1; max/exp > 0; exp *= 10){
//		int count[10] = {0};
//		int output[A->count + 1];
//		
//		for(x = 0; x <= A->count; x++){
//			int digit = (A->data[x]/exp) % 10;
//			count[digit]++;
//		}
//		
//		for(x = 0; x < 10; x++){
//			count[x] += count[x - 1];
//		}
//		
//		for(x = A->count; x >= 0; x--){
//			int digit = (A->data[x]/exp) % 10;
//			output[count[digit] - 1] = A->data[x];
//			count[digit]--;
//		}
//		
//		for(x = 0; x <= A->count; x++){
//			A->data[x] = output[x];
//		}
//	}
//}

void radixSort(ArrADT *A){
	int max = A->data[0];
	int x, exp;

	for(x = 0; x <= A->count; x++){
		if(max < A->data[x]){
			max = A->data[x];
		}
	}

	for(exp = 1; max/exp != 0; exp *= 10){
		int count[10] = {0};
		int output[A->count + 1];
		
		for(x = 0; x <= A->count; x++){
			int digit = (A->data[x]/exp) % 10;
			count[digit]++;
		}
		
		for(x = 0; x < 10; x++){
			count[x] += count[x - 1];
		}
		
		for(x = A->count; x >= 0; x--){
			int digit = (A->data[x]/exp) % 10;
			output[count[digit] - 1] = A->data[x];
			count[digit]--;
		}
		
		for(x = 0; x <= A->count; x++){
			A->data[x] = output[x];
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

	radixSort(&A);
	display(A);

	return 0;
}
