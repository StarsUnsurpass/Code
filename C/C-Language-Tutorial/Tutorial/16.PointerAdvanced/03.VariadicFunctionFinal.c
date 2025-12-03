// 可变参数Variadic function final
// printf传入的是可变参
// 格式化输出
// 日志记录
// 字符串操作，字符串拼接snprintf
// 数学中一些统计的函数
// 图形编程OpenCV一些函数
// 错误处理，异常捕获
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
*计算平均数
* @param num_args 参数的数量
* @param ... 可变参数列表，即要计算平均的数字
* @return 平均数
*/
double average(int num_args, ...);

int main03(void) {
	printf("Ave 2, 5, 7, 9 = %f\n", average(4, 2, 5, 7, 9));

	return EXIT_SUCCESS;
}

double average(int num_args, ...) {
	double sum = 0.0;

	va_list args; // 用于访问可变参数的列表

	va_start(args, num_args);

	for (size_t i = 0; i < num_args; i++) {
		sum += va_arg(args, int); // va_arg获取下一个参数
	}

	va_end(args);

	return num_args > 0 ? sum / num_args : 0;
}