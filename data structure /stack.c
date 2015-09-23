#include <stdio.h>
#include <stdlib.h>

#define STACK_N 15
#define STACK_MAX 1000

typedef struct Stack {
	int data[STACK_N];
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
	int data[STACK_N];
	int i;
	int size = STACK_N;

	for (i = 0; i < STACK_N; i++) data[i] = rand() % STACK_MAX;

	Stack stack = {data[STACK_N], size};
	//Stack *s = &stack;
	stack_init(&stack);	
	stack_push(&stack, 9);
	stack_push(&stack, 8);
	stack_push(&stack, 10);
	printf("%d\n", stack_top(&stack));
	stack_pop(&stack);
	printf("%d\n", stack_top(&stack));
	stack_pop(&stack);
	printf("%d\n", stack_top(&stack));
	stack_pop(&stack);
	printf("%d\n", stack_top(&stack));

	return EXIT_SUCCESS;
}



