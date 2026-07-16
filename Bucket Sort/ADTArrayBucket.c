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

void bucketSort(ArrADT *A){
	
	int bucket[10][A->count + 1];
	int bucketCount[10] = {0};
	int x, y, z;
	int max = A->data[0];
	
	for(int i = 0; i < A->count + 1; i++){
		if(max < A->data[i]){
			max = A->data[i];
		}
	}
	
	for(x = 0; x <= A->count; x++){
		int bIdx = (A->data[x] * 9) / max;
		
		bucket[bIdx][bucketCount[bIdx]] = A->data[x];
		bucketCount[bIdx]++;
 	}
 	
 	for(x = 0; x < 10; x++){
 		for(y = 1; y < bucketCount[x]; y++){
 			int key = bucket[x][y];
			z = y - 1;
			
			for(; z >= 0 && bucket[x][z] > key; z--){
				bucket[x][z + 1] = bucket[x][z];
			}
			
			bucket[x][z + 1] = key;
		}
	}
	 
	z = 0;
	
	for(x = 0; x < 10; x++){
		for(y = 0; y < bucketCount[x]; y++){
			A->data[z++] = bucket[x][y];
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

	bucketSort(&A);
	display(A);

	return 0;
}
