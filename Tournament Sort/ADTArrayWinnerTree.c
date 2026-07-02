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

void buildWinnerTree(ArrADT *A, int tree[]){
	int n = A->count + 1;
	int x;

	for(x = 0; x < n; x++){
		tree[n + x] = x;
	}

	for(x = n; x > 0; x--){
		int left = tree[2 * x];
		int right = tree[2 * x + 1];

		if(A->data[left] < A->data[right]){
			tree[x] = left;
		} else {
			tree[x] = right;
		}
	}
}

void winnerTreeSort(ArrADT *A){
	int n = A->count + 1;
	int tree[2 * MAX];
	int output[MAX];
	int winner;
	int x;

	for(x = 0; x < n; x++){
		buildWinnerTree(A, tree);

		winner = tree[1];

		output[x] = A->data[winner];

		A->data[winner] = INT_MAX;
	}

	for(x = 0; x < n; x++){
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

	winnerTreeSort(&A);
	display(A);

	return 0;
}
