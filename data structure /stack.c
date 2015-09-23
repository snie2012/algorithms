#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 100

typedef struct Stack {
	int data[STACK_MAX];
	int size;
} Stack;

void stack_init (Stack *S){
	S->size = 0;
}

int stack_top(Stack *S) {
	if (S->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return -1;
	}
	
	return S->data[S->size-1];
}

void stack_push(Stack *S, int d) {
	if (S->size < STACK_MAX) S->data[S->size++] = d;
	else fprintf(stderr, "Error: stack full\n");
}

void stack_pop(Stack *S) {
	if (S->size == 0) fprintf(stderr, "Error: stack empty\n");
	else S->size--;
}

int main() {
	int data[STACK_MAX] = [];
	int size = 100;
	Stack S = {data, size}
}