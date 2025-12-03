#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <errno.h>
#include <string.h>
#include <float.h>
#include <time.h>

void check_float(double number);

int main6(void) {
	//三角函数与M_PI
	//引入#define _USE_MATH_DEFINES
	/*double input_angle_degress = 0.0;
	double input_angle_radians = 0.0;
	double sin_value = 0.0;
	double cos_value = 0.0;
	double tan_value = 0.0;
	double arcsin_value = 0.0;
	double arccos_value = 0.0;
	double arctan_value = 0.0;

	printf("please input your degress:\n");
	scanf_s("%lf", &input_angle_degress);

	input_angle_degress = input_angle_degress * (M_PI / 180.0);

	sin_value = sin(input_angle_degress);
	cos_value = cos(input_angle_degress);
	tan_value = tan(input_angle_degress);

	arcsin_value = asin(input_angle_degress);
	arccos_value = acos(input_angle_degress);
	arctan_value = atan(input_angle_degress);

	printf("The sin of %.2f degress is: %.2f\n", input_angle_degress, sin_value);
	printf("The cos of %.2f degress is: %.2f\n", input_angle_degress, cos_value);
	printf("The tan of %.2f degress is: %.2f\n", input_angle_degress, tan_value);

	printf("The arcsin of %.2f degress is: %.2f\n", input_angle_degress, arcsin_value);
	printf("The arccos of %.2f degress is: %.2f\n", input_angle_degress, arccos_value);
	printf("The arctan of %.2f degress is: %.2f\n", input_angle_degress, arctan_value);*/
	/*double sin_value = 0.5;
	double cos_value = 0.5;
	double tan_value = 1.0;

	double asin_value = asin(sin_value) * (180.0 / M_PI);
	double acos_value = asin(cos_value) * (180.0 / M_PI);
	double atan_value = asin(tan_value) * (180.0 / M_PI);

	printf("The asin of %.2f degress is: %.2f\n", asin_value, sin_value);
	printf("The acos of %.2f degress is: %.2f\n", acos_value, cos_value);
	printf("The atan of %.2f degress is: %.2f\n", atan_value, tan_value);*/


	//双曲函数
	/*double input_value = 1.0;

	double sinh_value = sinh(input_value);

	double cosh_value = cosh(input_value);

	double tanh_value = tanh(input_value);

	printf("sinh(%f) = %f\n", input_value, sinh_value);
	printf("cosh(%f) = %f\n", input_value, cosh_value);
	printf("tanh(%f) = %f\n", input_value, tanh_value);*/


	//指数和对数
	/*double input_exp = 1.0;
	double input_log = 2.71828;
	double input_log10 = 10.0;

	double result_exp = exp(input_exp);

	double result_log = log(input_log);

	double result_log10 = log10(input_log10);

	printf("exp(%.2f) = %f\n", input_exp, result_exp);
	printf("log(%.2f) = %f\n", input_log, result_log);
	printf("log10(%.2f) = %f\n", input_log10, result_log10);*/


	//常见的math类别函数汇总
	/*double num_sqrt = 16.0;
	double num_fabs = -5.7;
	double num_ceil = 2.3;
	double num_floor = 1.7;
	double num1_fmod = 5.5;
	double num2_fmod = 2.0;

	double result_sqrt = sqrt(num_sqrt);
	double result_fabs = fabs(num_fabs);
	double result_ceil = ceil(num_ceil);
	double result_floor = floor(num_floor);
	double result_fmod = fmod(num1_fmod, num2_fmod);

	printf("sqrt(%.2f) = %f\n", num_sqrt, result_sqrt);
	printf("fabs(%.2f) = %f\n", num_fabs, result_fabs);
	printf("ceil(%.2f) = %f\n", num_ceil, result_ceil);
	printf("floor(%.2f) = %f\n", num_floor, result_floor);
	printf("fmod(%.2f, %.2f) = %f\n", num1_fmod, num2_fmod, result_fmod);*/


	//pow函数
	/*double radius = 0.0;

	double square_side = 0.0;

	double circle_area = 0.0;

	double square_area = 0.0;

	printf("please input radius of the circle:\n");
	scanf_s("%lf", &radius);

	circle_area = M_PI * pow(radius, 2);

	square_side = 2 * radius;

	square_area = pow(square_side, 2);

	printf("area of the circle is: %.2f\n", circle_area);
	printf("area of the square whose side is twice of the circle is: %.2f\n", square_area);*/


	//对于math类别的错误处理：EDOM, ERANGE, HUGE_VAL
	//#define _CRT_SECURE_NO_WARNINGS允许使用C语言中非安全的函数，忽略警告
	/*double number = 0.0;
	double result = 0.0;

	printf("please input a number:\n");
	scanf("%lf", &number);

	errno = 0;

	result = sqrt(number);

	if (errno == EDOM) {
		printf("error: the number is smaller than zero!\n");
	}
	else if(errno == ERANGE){
		printf("the number is out of range!");
	}
	else if (errno == HUGE_VAL) {
		printf("the number is out of range!");
	}
	else {
		printf("the result is: %.2f\n", result);
	}*/


	//检查浮点数类别与属性
	//编译原理 静态分析 零作为除数报错
	/*double numbers[] = { 0.0, 1.0, -1.0, HUGE_VAL, -HUGE_VAL, NAN, DBL_MIN / 2.0 };

	int size = sizeof(numbers) / sizeof(numbers[0]);

	for (size_t i = 0; i < size; i++) {
		check_float(numbers[i]);
	}*/


	//浮点数的比较与差值
	/*double group1_max_temp = 35.5;
	double group2_max_temp = 37.2;

	double group1_min_temp = -5.0;
	double group2_min_temp = -3.8;

	double max_temp = fmax(group1_max_temp, group2_max_temp);
	printf("max_temp: %.2f ℃\n", max_temp);

	printf("min_temp: %.2f ℃\n", (group1_min_temp, group2_min_temp));

	double temp_diff_max1 = fdim(group1_max_temp, group2_max_temp);
	printf("%.2f\n", temp_diff_max1);

	double temp_diff_max2 = fdim(group2_max_temp, group1_max_temp);
	printf("%.2f\n", temp_diff_max2);

	double temp_diff_min = fdim(group1_min_temp, group2_min_temp);
	printf("%.2f\n", temp_diff_min);*/


	//舍入与剩余函数
	//complex.h头文件


	//time.h与时间戳的使用
	/*time_t now = time(NULL); // 获取当前时间戳
	printf("%td\n", now);

	// 转换为本地时间
	struct tm local_time;
	localtime_s(&local_time, &now);

	// 转换为协调世界时间（UTC）
	struct tm utc_time;
	gmtime_s(&utc_time, &now);

	char local_time_str[80];
	char utc_time_str[80];

	strftime(local_time_str, sizeof(local_time_str), "%Y-%m-%d %H:%M:%S", &local_time);

	strftime(utc_time_str, sizeof(utc_time_str), "%Y-%m-%d %H:%M:%S", &utc_time);

	printf("当前时间戳：%" PRIdMAX "\n", (intmax_t)now);

	printf("本地时间：%s\n", local_time_str);

	printf("UTC时间：%s\n", utc_time_str);*/


	//错误处理函数
	//errno.h, perror()











	return 0;
}

void check_float(double number) {
	switch (fpclassify(number)) {
	case FP_INFINITE: printf("%.2f 是无穷大\n", number); break;
	case FP_NAN: printf("%.2f 不是一个数字\n", number); break;
	case FP_NORMAL: printf("%.2f 是一个正常值\n", number); break;
	case FP_SUBNORMAL: printf("% .2f 是次正规数\n", number); break;
	case FP_ZERO: printf("%.2f 是零\n", number); break;
	}

	if (isfinite(number))	printf("%.2f 是有限的\n", number);
	if (isinf(number))		printf("%.2f 是无穷大\n", number);
	if (isnan(number))		printf("%.2f 是NAN\n", number);
	if (isnormal(number))	printf("%.2f 是正常数\n", number);
	if (signbit(number))		printf("%.2f 的符号位是正或零\n", number);

	printf("\n");
}