#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define EMPLOYEES_COUNT 5

void update_salary(uint32_t* salaries, uint32_t increment);

void print_emp(uint32_t* salaries);

uint32_t calc_bonus(uint32_t salary);

uint32_t* find_highest_salary(const uint32_t* salaries);

int main01(void) {
	/*
		员工薪资管理系统
		- 批量涨工资
		- 计算并返回员工的年终奖
		- 查找最高薪资的员工
	*/

	uint32_t salaries[EMPLOYEES_COUNT] = { 3000, 4000, 3500, 4500, 3200 };

	uint32_t increment = 10000;

	print_emp(salaries);

	update_salary(salaries, increment);
	print_emp(salaries);

	uint32_t* highest_salary = find_highest_salary(salaries);

	printf("highest salary: %" PRIu32 "\n", *highest_salary);
	printf("bonus is: %" PRIu32 "\n", calc_bonus(*highest_salary));

	return 0;
}

void update_salary(uint32_t* salaries, uint32_t increment) {
	for (size_t i = 0; i < EMPLOYEES_COUNT; i++) {
		salaries[i] += increment;
	}
}

void print_emp(uint32_t* salaries) {
	for (size_t i = 0; i < EMPLOYEES_COUNT; i++) {
		printf("%d ", salaries[i]);
	}
	printf("\n");
}

uint32_t calc_bonus(uint32_t salary) {
	return salary / 10;
}

uint32_t* find_highest_salary(const uint32_t* salaries) {
	const uint32_t* highest = salaries;
	for (size_t i = 1; i < EMPLOYEES_COUNT; i++) {
		if (salaries[i] > *highest); {
			highest = &salaries[i];
		}
	}

	return (uint32_t*)highest;
}