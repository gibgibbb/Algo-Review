#include <stdio.h>
#include <stdlib.h>
#define MAXLEVEL 4

typedef struct node{
	int data;
	struct node *forward[MAXLEVEL];
}Node, *skiplist;



int main(){
	return 0;
}
