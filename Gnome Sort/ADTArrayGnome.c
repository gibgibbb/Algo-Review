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

//void gnomeSort(ArrADT *A){
//	int pos, temp;
//	for(pos = 0; pos <= A->count;){
//		if(pos == 0 || A->data[pos] >= A->data[pos - 1]){
//			pos++;
//		} else {
//			temp = A->data[pos];
//			A->data[pos] = A->data[pos - 1];
//			A->data[pos - 1] = temp;
//			pos--;
//		}
//	}
//}

void gnomeSort(ArrADT *A){
	int pos, temp;
	for(pos = 0; pos <= A->count;){
		if(pos == 0 || A->data[pos] >= A->data[pos - 1]){
			pos++;
		} else {
			temp = A->data[pos];
			A->data[pos] = A->data[pos - 1];
			A->data[pos - 1] = temp;
			pos--;
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

	gnomeSort(&A);
	display(A);

	return 0;
}
