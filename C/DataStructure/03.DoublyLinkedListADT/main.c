#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedList.h"

typedef struct {
	int id;
	char* name;
} Employee;

// ±ãÐ¯µÄ×Ö·û´®¸´ÖÆº¯Êý
char* portable_strdup(const char* str) {
	if (str == NULL) {
		return NULL;
	}

	size_t len = strlen(str);
	char* copy = (char*)malloc(len + 1);
	if (copy) {
		strcpy(copy, str);
	}
	return copy;
}

void free_employee(void* data) {
	if (data) {
		Employee* emp = (Employee*)data;
		printf("Freeing Employee ID: %d, Name: %s\n", emp->id, emp->name);
		free(emp->name);
		free(emp);
	}
}

int compare_employee_by_id(const void* data1, const void* data2) {
	const Employee* emp1 = (const Employee*)data1;
	const Employee* emp2 = (const Employee*)data2;
	return (emp1->id - emp2->id);
}

void print_employee_action(void* data, void* context) {
	const Employee* emp = (const Employee*)data;

	if (emp) {
		printf("Employee ID: %d, Name: %s\n", emp->id, emp->name);
		return;
	}

	printf("Null Employee Data\n");
}

int main(void) {
	printf("---- Architecture of Doubly Linked List in C ----\n");

	printf("Setup 1: Creating a list with a memory pool of 10 nodes...\n");

	DoublyLinkedList* emp_list = List_Create(10, free_employee);

	if (!emp_list) {
		fprintf(stderr, "Failed to create the doubly linked list.\n");
		return 1;
	}
	printf("List created successfully.\n");

	printf("Setup 2: Adding Employees to the list...\n");
	for (int i = 1; i <= 5; ++i) {
		Employee* emp = (Employee*)malloc(sizeof(Employee));
		
		if (emp == NULL) {
			fprintf(stderr, "Memory allocation failed for Employee %d\n", i);
			continue;
		}

		emp->id = 101 + i;
		char buffer[50];
		sprintf(buffer, "Employee_%d", emp->id);
		emp->name = portable_strdup(buffer);
		if (emp->name == NULL) {
			fprintf(stderr, "Memory allocation failed for Employee name %d\n", i);
			free(emp);
			continue;
		}

		List_Append(emp_list, emp);
	}
	printf("Employees added successfully.\n");

	printf("Setup 3: Printing all Employees in the list...\n");
	List_ForEach(emp_list, print_employee_action, NULL);
	printf("Current list size: %zu\n", List_GetSize(emp_list));
	printf("All Employees printed successfully.\n");

	printf("Step 4: Finding an Employee with ID 103...\n");
	Employee search_key = { 103, NULL };
	DListNode* found_node = List_Find(emp_list, &search_key, compare_employee_by_id);

	return 0;
}