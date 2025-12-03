#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 案例：命令行程序的编写

void processAdd(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	if (argc >= 3 && strcmp(argv[1], "-a") == 0) {
		processAdd(argc, argv);
	}

	system("pause");

	return EXIT_SUCCESS;
}

void processAdd(int argc, char* argv[]) {
	int sum = 0;
	for (size_t i = 0; i < argc; i++) {
		sum += atoi(argv[i]); // 字符串转换成int类型
	}

	printf("Sum: %d\n", sum);
}