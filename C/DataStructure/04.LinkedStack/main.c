#include <stdio.h>
#include "LinkedStack.h"

typedef struct {
	int id;
	char name[20];
} Record;

void print_record(const Record* r) {
	if (r) {
		printf("Recode(id: %d, name: %s)", r->id, r->name);
	}
}

void test_record_stack() {
	printf("--- Testing Struct (Record) Linked Stack ---\n");

	Stack* record_stack = stack_create(sizeof(Record));

	if (!record_stack) {
		printf("Failed to create record stack.\n");

		return;
	}

	printf("Stack created. Is empty? %s\n", stack_is_empty(record_stack) ? "Yes" : "No");

	Record r1 = { 1, "Alice" };

	Record r2 = { 2, "Bob" };

	Record r3 = { 3, "Charlie" };



	printf("Pushing "); print_record(&r1); printf("...\n");

	stack_push(record_stack, &r1);



	printf("Pushing "); print_record(&r2); printf("...\n");

	stack_push(record_stack, &r2);



	printf("Pushing "); print_record(&r3); printf("...\n");

	stack_push(record_stack, &r3);



	printf("Current stack size: %zu\n", stack_get_size(record_stack));



	Record peeked_record;


	if (stack_peek(record_stack, &peeked_record)) {

		printf("Peek at top: ");

		print_record(&peeked_record);

		printf("\n");

	}


	printf("\nPopping all elements:\n");

	while (!stack_is_empty(record_stack)) {

		Record popped_record;

		if (stack_pop(record_stack, &popped_record)) {

			printf("Popped: ");

			print_record(&popped_record);

			printf(" | New size: %zu\n", stack_get_size(record_stack));

		}

	}



	printf("\nIs stack empty now? %s\n", stack_is_empty(record_stack) ? "Yes" : "No");


	stack_destroy(&record_stack);

	printf("Stack destroyed. Pointer is now %s\n", record_stack == NULL ? "NULL" : "Not NULL");
}

int main() {
	test_record_stack();

	return 0;
}