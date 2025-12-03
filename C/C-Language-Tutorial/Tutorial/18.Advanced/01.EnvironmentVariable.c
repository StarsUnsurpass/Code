// 环境变量的读写
#include <stdio.h>
#include <stdlib.h>

int main01(void) {
	// 读取环境变量
	/*char buffer[4096];
	size_t buffer_size = sizeof(buffer);
	errno_t err = getenv_s(&buffer_size, buffer, buffer_size, "PATH");

	if (err == 0) {
		printf("PATH: %s\n", buffer);
	}
	else {
		return EXIT_FAILURE;
	}*/

	// 写入环境变量
	/*errno_t err = _putenv_s("MY_VAR", "some_value");

	if (err == 0) {
		printf("success!\n");
	}
	else {
		return EXIT_FAILURE;
	}*/

	return EXIT_SUCCESS;
}