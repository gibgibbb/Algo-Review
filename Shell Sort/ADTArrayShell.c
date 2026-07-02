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

//void shellSort(ArrADT *A){
//	int x, y, gap, temp;
//	for(gap = A->count/2; gap != 0; gap /= 2){
//		for(x = gap; x <= A->count; x++){
//			temp = A->data[x];
//			for(y = x - 1; y >= 0 && A->data[y] > temp; y--){
//				A->data[y + 1] = A->data[y];
//			}
//			A->data[y + 1] = temp;
////			temp = A->data[x];
////			for(y = x; y >= gap && A->data[y - gap] > temp; y -= gap){
////				A->data[y] = A->data[y - gap];
////			}
////			A->data[y] = temp; //This also works//
//		}
//	}
//}

void shellSort(ArrADT *A){
	int x, y, gap, temp;
	for(gap = A->count/2; gap != 0; gap /= 2){
		for(x = gap; x <= A->count; x++){
			temp = A->data[x];
			for(y = x - 1; y >= 0 && A->data[y] > temp; y--){
				A->data[y + 1] = A->data[y];
			}
			A->data[y + 1] = temp;
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

	shellSort(&A);
	display(A);

	return 0;
}
