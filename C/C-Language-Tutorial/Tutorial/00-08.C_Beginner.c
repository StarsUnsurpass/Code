//define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>

#define STUDENT_COUNT 5
#define LETTER_COUNT 26
#define PI 3.14
#define MONTH_COUNT 12
#define GRADE_COUNT 11

double square_area(double side);

double rectangle_area(double length, double width);

double circle_area(double redius);

bool is_leap_year(int year);

bool check_component_health(uint32_t component_id);

int get_days_in_month(int month, int year);

char get_grade(int score);

int factorial(uint32_t num, uint32_t acc);

uint32_t fibonacci_interative(uint32_t num);

void greet1(void);

void greet2();

void increment_counter1(void);

void increment_counter2(void);

void demo_reg_var(void);

bool find_index_of_value(const int32_t* array, size_t size, int32_t target_value, size_t* index);

void add_ten_by_values(int32_t* value);



int main0() {


	//printf函数的使用
	/*
	//int number = 155;

	//// 十进制表示
	//printf("Decimal: %d\n", number);

	//// 八进制表示
	//printf("Octala: %o\n", number);

	//// 十六进制表示
	//printf("Hexadecimal (lowercase): %x\n", number);
	//printf("Hexadecimal (uppercase): %X\n", number);
	//printf("Hexadecimal (lowercase): %#x\n", number);
	//printf("Hexadecimal (uppercase): %#X\n", number);

	//// 对齐
	//printf("Left aligned  : %-10d|\n", number);
	//printf("Right aligned : %10d|\n", number);


	//printf("Show plus : %+d\n", number);

	//// 前导零
	//printf("Leading zeros : %010d\n", number);
	*/


	// scanf_s函数的使用
	/*printf("Please input your number :\n");

	int number;
	int number1, number2, number3;

	scanf_s("%d", &number);
	scanf_s("%d,%d,%d", &number1, &number2, &number3);

	printf("Your number is : %d\n", number);
	printf("Your number is : %d %d %d", number1, number2, number3);*/


	// unsigned迭代、数组索引无符号类型
	/*unsigned int number = -123;

	printf("unsigned int: %u\n", number);
	printf("unsigned int (hex): %x\n", number);
	printf("unsigned int: %d\n", number);*/
	

	// short处理像素数据(一般以左上角开始，不会有负数，ushort),RGB颜色值
	// 4K: 3860 x 2160
	/*short myshort = 100;

	unsigned short screenWidth = 800;
	unsigned short screenHeight = 600;

	unsigned x = 400;
	unsigned y = 300;

	printf("myshort = %hd\n", myshort);
	printf("The Screen resolution is: %hu X %hu\n", screenWidth, screenHeight);
	printf("Current position is: (%u, %u)\n", x, y);

	unsigned short color = 0b1111100000000000;

	printf("Red : 0x%X\n", color);*/


	// long类型，CPU位数越大，承载数据越大
	// Intel 8086处理器32位，历史意义，x86架构（公司->业界），RAM<4G
	// x86-64（x64架构），向下兼容32位，16、8需要调整
	// 32位下long占4字节，64位下long占8字节，；long long都是8，适配，c99标准之后


	// sizeof编译时测量类型的大小
	// size_t无符号整型
	// windows上visual studio上，long无论32位或64位，一律为4字节，linux、unix、类unix上long64位为8字节
	/*printf("Size of short: %zu bytes(s)\n", sizeof(short));

	printf("Size of unsigned short: %zu byte(s)\n", sizeof(unsigned short));

	printf("Size of int: %zu bytes(s)\n", sizeof(int));

	printf("Size of unsigned int: %zu byte(s)\n", sizeof(unsigned int));

	printf("Size of long: %zu byte(s)\n", sizeof(long));

	printf("Szie of unsigned long: %zu byte(s)\n", sizeof(unsigned long));

	printf("Size of long long: %zu byte(s)\n", sizeof(long long));

	printf("Size of unsigned long long: %zu byte(s)\n", sizeof(unsigned long long));*/


	// 微软与跨平台的int标准
	// Windows上、visual studio上，int、short、long、long long不用
	// <stdint.h>，c99标准之后，int8_t、int16_t、int32_t、int64_t
	/*__int16 myint16 = 100;
	__int32 myint32 = 100;

	printf("%hd\n", myint16);
	printf("%d\n", myint32);
	*/


	// stdint.h的引用
	/*int16_t myInt16 = 32767; // hd
	uint16_t myUInt16 = 65535; // hu

	int32_t myInt32 = 2147483647; // ld, li
	uint32_t myUInt32 = 4294967295U; // lu 后缀U不能少，32以后都有，避免不同平台溢出

	int64_t myInt64 = 9223372036854775807LL; // lld, lli 后缀LL表示long long，无long
	uint64_t myUInt64 = 18446744073709551615ULL; // llu 后缀ULL表示unsigned long long

	printf("Size of int16_t: %zu byte(s)\n", sizeof(int16_t));
	printf("Size of uint16_t: %zu byte(s)\n", sizeof(uint16_t));

	printf("Size of int32_t: %zu byte(s)\n", sizeof(int32_t));
	printf("Size of uint32_t: %zu byte(s)\n", sizeof(uint32_t));

	printf("Size of int64_t: %zu byte(s)\n", sizeof(int64_t));
	printf("Size if uint64_t: %zu byte(s)\n", sizeof(uint64_t));*/


	// 显式与隐式类型转换
	/*int16_t smallNum1 = 32767;
	int32_t bigNum1;
	int16_t smallNum2;
	int32_t bigNum2 = 9999999;
	
	// 隐式转换
	bigNum1 = smallNum1;

	// 显示转换（强制转换）
	smallNum2 = bigNum2;

	printf("bigNum1 = %d\n", bigNum1);
	printf("smallNum2 = %d\n", smallNum2);

	uint32_t uNum = UINT32_MAX;
	int32_t sNum1 = uNum;
	int32_t sNum2 = (int32_t)uNum; // 无符号到有符号 强制转换 显式类型转换
	int64_t lNum = 50000;
	int16_t sNum = (int16_t)lNum; // 大范围到小范围
	int16_t sNum3 = -1;
	uint32_t lNum1 = (uint32_t)sNum3; // 小范围到大范围（扩展负数）
	// 显式转换使代码更清晰，避免隐式转换可能导致的错误

	printf("uint32_t = %u\n", uNum);
	printf("converted to int32_t: %d\n", sNum1);
	printf("converted to int32_t with explicit cast: %d\n", sNum2);
	printf("int64_t = %lld\n", lNum);
	printf("converted to int16_t: %hd\n", sNum);
	printf("int16_t: %hd\n", sNum3);
	printf("converted to uint_32: %u\n", lNum1);*/

	
	// 固定宽度整数类型的格式化宏输出 企业开发中不使用%d、llu等格式化输出
	/*int32_t myInt32 = INT32_MAX;
	int64_t myInt64 = INT64_MAX;
	uint64_t myUInt64 = UINT64_MAX;

	printf("int32_: %" PRId32 "\n", myInt32);
	printf("int64_t: %" PRId64 "\n", myInt64);
	printf("uint64_t: %" PRIu64 "\n", myUInt64);*/

	
	// least和fast整型的企业用途与区别
	// int_leastN_t 
	// 至少有N位，可能更多，适用于需要保证最小存储容量的可移植代码
	// int_fastN_t
	// 至少有N位，但是选择运算最快的类型，适用于需要性能敏感的场景
	// 标准整数类型->固定宽度整数类型，固定的位数，不可以越界，适用于需要精确数据大小的场景，如网络协议、文件格式等
	/*int_least32_t playerScore = 5000;
	int_fast32_t pixelValue = 128;
	printf("pixelValue: %" PRIdFAST32 "\n", pixelValue);*/

	
	// 浮点数
	// 实际中银行余额不用浮点数存储，精度问题
	// 若存储比精度重要，使用float，若精度比存储重要，使用double
	/*float temperature = 36.5f;

	float humidity = 48.3f;

	float speed_of_sound = 3.435e2f;

	float length = 12.34f, width = 23.45f, height = 34.56f;

	printf("Temperature: %f\n", temperature);
	printf("Humidity: %f\n", humidity); // 丢失精度
	printf("Humidity: %.2f\n", humidity);
	printf("Humidity: %.20f\n", humidity);
	printf("Speed of sound:%f\n", speed_of_sound);
	printf("Dimensions(LxWxH):%f x %f x %f\n", length, width, height);

	float num = 123.456f;

	// %f
	printf("Using %%f: %f\n", num);

	// %e %E 科学计数法格式化输出
	printf("Using %%e: %e\n", num);
	printf("Using %%E: %E\n", num); 

	// %a %A 十六进制浮点数 p计数法
	printf("Using %%a: %a\n", num);
	printf("Using %%A: %A\n", num);*/
	

	// float溢出
	/*float max_float = FLT_MAX;

	float overflow = max_float * 1000.0f; // OverFlow 上溢 inf: infinity

	float min_float = FLT_MIN;

	float underflow = min_float / 1000.0f; // UnderFlow 下溢

	printf("Msximum Float: %e\n", max_float);
	
	printf("Overflow: %e\n", overflow);

	printf("Minmum Positive Float: %e\n", min_float);

	printf("Underflow: %e\n", underflow);

	float positive_infinity = INFINITY;
	printf("Positive Infinity: %f\n", positive_infinity); // 正无穷大

	float negative_infinity = -INFINITY;
	printf("Negative Infinity: %f\n", negative_infinity); // 负无穷大

	float num = 1.0f; // 除以零产生无穷大
	float infinity = num / 0.0f;
	printf("1.0 / 0.0 = %f\n", infinity);

	float negative_sqrt = sqrt(-1.0f); // Nan: Not a number
	printf("sqrt(1.0f) = %f\n", negative_sqrt);*/


	// 浮点数四舍五入 IEEE 754
	// 最近偶数舍入（银行家舍入） round to nearest, ties to even
	/*printf("%.4f\n", 3.14159);
	printf("%.1f\n", 3.15);
	printf("%.1f\n", 3.15f);
	printf("%.1f\n", 3.25);

	float number = 3.15f; // 奇数向上舍入变为偶数
	printf("1 -> %.1f\n", number);
	number = 3.25f; // 偶数保持不变
	printf("2 -> %.1f\n", number);*/


	// double, long double科研与企业用途的区别
	// float处理速度快，占用内存小，3D图形渲染，精度足够
	// double精度高，占用资源, 利息，NASA轨迹运算，C语言中常量，金融领域够用
	// float和double在各平台上都一样，没有int32、int64等
	/*double num1 = 123.456;
	double num2 = 76.543;

	double sum = num1 + num2;
	double difference = num1 - num2;
	double product = num1 * num2;
	double quotient = num1 / num2;

	long double ld_val = 123.4353646452674532L; // 加L，否则默认double，double: lf

	printf("Sum: %f\n", sum);
	printf("Difference: %f\n", difference);
	printf("Product: %f\n", product);
	printf("Quotient: %f\n", quotient);

	printf("ld_val: %Lf\n", ld_val);*/


	// float和double的精度对比（保守）
	/*float float_num = 1.0 / 3.0;
	double double_num = 1.0 / 3.0;

	printf("Float precision: %.20f\n", float_num);
	printf("Double precision: %.20lf\n", double_num);

	printf("Defined max precision for float: %d\n", FLT_DIG);
	printf("Defined max precision for double: %d\n", DBL_DIG);*/


	// Decimal保存金钱、货币，定点数，C语言中没有，GMP项目


	// char与ASCII
	/*char mych = 'A';
	int mych1 = 98;
	int mych2 = 27;
	int mych3 = 10;

	printf("mych: %c\n", mych);
	printf("mych1: %c\n", mych1);
	printf("mych2: %c\n", mych2);
	printf("mych3: %c\n", mych3);*/


	// 转义序列
	// /少用，定为转义序列开头
	// 早期Windows中\r\n，Linux中\n，早期Mac\r
	/*printf("\"\n");
	printf("\\\n");
	printf("\a");
	printf("第一行文本\n\t第二行文本，带有缩进\n\t\t第三行文本，缩进更多\n");

	printf("\033[2J"); // 清除屏幕*/
	/*printf("AAAAAAA\n");
	printf("AAAAAAA\n");
	printf("AAAAAAA\n");
	printf("AAAAAAA\n");
	printf("AAAAAAA\n");
	printf("AAAAAAA\n");
	printf("AAAAAAA\n");
	printf("AAAAAAA\n");

	printf("\033[%d;%dH", 3, 3);*/


	// bool类型与实际案例，bool类型只占一位，不需要输出
	/*bool is_game_over = false;
	bool is_game_won = true;*/


	// char范围与无符号char
	// uint8（用于数字的计算）可替代unsigned char（用于数字的处理），log用ucher而不是uint


	// 常量
	/*const int MAX_USERS = 100;
	printf("MAX_USERS: %d\n", MAX_USERS);*/


	// VS没有引入C11标准，不支持复数、虚数


	// 运算符：算数运算符、关系运算符、逻辑运算符、赋值运算符
	// 数据对象、左值（Lvalue）、右值（Rvalue）、运算符
	/*uint32_t apple_box = 5;
	uint32_t orange_box = 10;

	printf("苹果盒子里有 %" PRIu32 "个苹果\n", apple_box);
	printf("橘子盒子里有 %" PRIu32 "个苹果\n", orange_box);

	uint32_t total_fruit = apple_box + orange_box;

	printf("盒子里总共有 %" PRIu32 "个水果\n", total_fruit);*/

	//多重赋值（长链式赋值）
	/*uint32_t x, y, z;

	x = y = z = 10; // 从右往左，C语言支持三层以上，开发时三层，可读性差*/

	//按位移位运算符很少用，左移会导致溢出，右移可能变成有符号的，位移运算可代替加减乘除优化性能
	/*uint8_t num = 22;
	printf("Original number: %" PRIu8 "(binary: 00010110)\n", num);

	uint8_t left_shifted = num << 2;
	printf("Left Shifted by 2: %" PRIu8 "(binary: 01011000)\n", left_shifted);

	uint8_t right_shifted = num >> 2;
	printf("Right Shifted by 2: %" PRIu8 "(binary: 00000101)\n", right_shifted);

	uint8_t num1 = right_shifted << 2;
	printf("num1 = %" PRIu8 "\n", num1);

	uint32_t num2 = 25;
	uint32_t result1 = num2 * 1024;
	uint32_t result2 = num2 << 10;
	printf("num = %" PRIu32 "\n", num2);
	printf("num = %" PRIu32 "\n", result1);
	printf("num = %" PRIu32 "\n", result2);*/

	
	//位移使用
	/*
	//设置寄存器初始状态
	uint32_t device_config = 0;
	
	//定义每个选项的掩码
	const uint32_t option1_mask = 1 << 0;
	const uint32_t option2_mask = 1 << 1;
	const uint32_t option3_mask = 1 << 2;
	
	device_config |= option1_mask | option3_mask;
	
	uint32_t option2_status = (device_config & option2_mask) >> 1;
	
	device_config &= ~option1_mask;*/

	
	//位移溢出
	/*uint32_t num = -75;
	
	uint32_t no = num << 30;

	printf("no = %d", no);*/

	
	//逻辑真假，关系运算符
	/*int a = 10;
	int b = 20;

	bool greater = a > b;
	printf("a > b : %d\n", greater);

	bool less = a < b;
	printf("a < b : %d\n", less);

	bool equal = a == b;
	printf("a == b : %d\n", equal);
	
	bool not_equal = a != b;
	printf("a != b : %d\n", not_equal);

	bool less_or_equal = a <= b;
	printf("a <= b : %d\n", less_or_equal);

	bool greater_or_equal = a >= b;
	printf("a >= b : %d\n", greater_or_equal);*/
	

	//三元运算符
	/*int a = 10;
	int b = 20;

	bool greater = a > b;
	printf("a > b : %s\n", greater ? "true" : "false");

	bool less = a < b;
	printf("a < b : %s\n", less ? "true" : "false");

	bool equal = a == b;
	printf("a == b : %s\n", equal ? "true" : "false");

	bool not_equal = a != b;
	printf("a != b : %s\n", not_equal ? "true" : "false");

	bool less_or_equal = a <= b;
	printf("a <= b : %s\n", less_or_equal ? "true" : "false");

	bool greater_or_equal = a >= b;
	printf("a >= b : %s\n", greater_or_equal ? "true" : "false");*/

	
	//按位“与”运算符，将一个数的特定位置清零，检查某个位置是否为1
	/*int i = 25;
	int j = 46;
	int k = i & j;
	printf("%d\n", k);*/
	
	
	//按位“与或”运算符，让二进制数某一位变成1，组合标志位
	/*int i = 2;
	int j = 5;
	int k = i | j;
	printf("%d\n", k);*/


	//按位异或，逻辑异或（XOR），翻转特定位，检测不同
	/*int i = 2;
	int j = 10;
	int k = i ^ j;
	printf("%d\n", k);*/	
	/*int a;
	int b;
	int temp;
	temp = a;
	a = b;
	b = temp;

	a = a + b;
	b = a - b;
	a = a - b;
	
	a = a ^ b;
	b = a ^ b;
	a = a ^ b*/


	//按位取反，按位运算符用于判断，按位移位用于计算
	/*uint8_t status1 = 0b00001100;

	printf("Inistial status\t: 0b");
	for (int i = 7; i >= 0; i--) {
		printf("%d", (status1 >> i) & 1);
	}
	printf("\t(Binary)\n");

	uint8_t status2 = 0b00001100;
	status2 = ~status2;

	printf("Final status\t: 0b");
	for (int i = 7; i >= 0; i--) {
		printf("%d", (status2 >> i) & 1);
	}
	printf("\t(Binary)\n");*/


	//逻辑运算符，&&，||
	/*int condition_a = 1;
	int condition_b = 0;

	int res1 = condition_a && condition_b;
	int res2 = condition_a || condition_b;

	printf("res1 = %d\n", res1);
	printf("res2 = %d\n", res2);*/


	//复合赋值，原地修改赋值(In-place Modification)，而不是在另一个位置简单创建一个新的值做出计算然后再将新的值赋给原先的值，
	// 性能更好，更直观，不必拷贝
	/*int base_number = 8;
	int add_number = 2;
	int sub_number = 7;
	int mul_number = 5;
	int div_number = 4;
	int mod_number = 5;
	int left_shift_number = 1;
	int right_shift_number = 2;
	int and_number = 0b1010;
	int or_number = 0b0101;
	int xor_number = 0b1111;

	printf("base_number = %d\n", base_number);

	base_number += add_number;
	printf("base_number = %d\n", base_number);

	base_number -= sub_number;
	printf("base_number = %d\n", base_number);

	base_number *= mul_number;
	printf("base_number = %d\n", base_number);

	base_number /= div_number;
	printf("base_number = %d\n", base_number);

	base_number %= mod_number;
	printf("base_number = %d\n", base_number);

	base_number <<= left_shift_number;
	printf("base_number = %d\n", base_number);

	base_number >>= right_shift_number;
	printf("base_number = %d\n", base_number);

	base_number &= and_number;
	printf("base_number = %d\n", base_number);

	base_number |= or_number;
	printf("base_number = %d\n", base_number);

	base_number ^= xor_number;
	printf("base_number = %d\n", base_number);*/


	//逗号运算符，都会运算，只赋值最后一个表达式，谨慎使用或不要使用，可读性差
	/*uint32_t a = 1, b = 2, c = 1;
	uint32_t res = (a += 1, b += 2, c += 3);

	printf("a = %d, b = %d, c = %d, res = %d\n", a, b, c, res);*/


	//过多的嵌套层次使代码难以阅读和维护
	//企业使用策略模式（Strategy Pattern）避免if else行为（面向对象），结构体，规则引擎
	//使用逻辑AND OR && || 来处理if-else的短路行为，第一个不满足，第二个不执行
	/*bool is_weather_sunny = true;
	bool is_venue_availiable = false;

	if (is_weather_sunny && is_venue_availiable) {
		printf("正常进行！\n");
	}
	else {
		printf("无法进行！\n");

		if (!is_weather_sunny) {
			printf("原因：天气不好！\n");
		}

		if (!is_venue_availiable) {
			printf("原因：场地不可用！\n");
		}
	}*/


	//访问权限简单案例
	/*uint8_t role = 2;;

	uint8_t completed_tasks = 6;

	bool is_manager_approved = false;

	bool access_allowed = (role == 1) || (role == 2 && completed_tasks > 5) ||
		(role == 3 && completed_tasks > 10 && is_manager_approved);

	if (access_allowed) {
		puts("允许访问！");
	}
	else {
		puts("拒绝访问！");
	}*/
	
	
	//switch case
	

	//三元运算符，避免if else的使用
	/*uint8_t score = 96;

	char grade;

	grade = (score > 90) ? 'A' :
			(score > 80) ? 'B' :
			(score > 70) ? 'C' : 'D';

	printf("得分：%u, 等级：%c\n", score, grade);*/


	//卫语句的使用
	/*uint8_t age = 28;
	uint8_t driving_exp_years = 1;

	if (age < 21) {
		puts("不符合条件，年龄不足");
		return 0;
	}

	if (driving_exp_years < 1) {
		puts("不符合条件，经验不足");
		return 0;
	}

	puts("条件满足");*/


	//简化逻辑表达式，逻辑简化
	
	
	//状态机，枚举类型
	/*uint8_t traffic_light_state = 0;

	switch (traffic_light_state) {
	case 0:
		puts("red");
		traffic_light_state = 1;
		break;

	case 1:
		puts("green");
		traffic_light_state = 2;
		break;
		
	case 2:
		puts("yellow");
		traffic_light_state = 0;
		break;

	default:
		puts("wrong");
		break;
	}*/


	//switch-case与if-else的根本区别
	//switch表达式必须为一个整型，而且对应，理论上比if快


	//while循环
	/*const uint8_t PRICE = 5;

	uint8_t balance = 0;

	uint8_t coin;

	while (balance < PRICE) {
		puts("钱不够，请投币");

		scanf_s("%" PRIu8, &coin);

		if (coin == 1 || coin == 2 || coin == 5) {
			balance += coin;
			printf("您已经投入了￥%" PRIu8 "\n", balance);
		}
		else {
			printf("对不起，我们不接受￥%" PRIu8 "的硬币，请重新投币\n", coin);
		}
	}

	if (balance > PRICE) {
		printf("请收好找零￥%" PRIu8 "\n", balance - PRICE);
	}*/


	//死循环的利用
	/*uint32_t sum = 0;

	uint32_t num;

	puts("请输入一个数，用回车隔开，我们将计算它们的和，输入0结束");

	while (true) {
		puts("请输入一个数");

		scanf_s("%" PRIu32, &num); // 不能处理预期输入以外的内容

		if (num == 0) {
			break;
		}

		sum += num;
	}

	printf("所求的和是%" PRIu32 "\n", sum);*/
	
	/*uint32_t sum = 0;

	char input;

	puts("请输入一个数（0-9），用回车隔开，我们将计算它们的和，输入q结束");

	while (true) {
		puts("请输入一个数或q退出");

		scanf_s(" %c", &input, 1); //scanf_s微软独有，%c前面加上空格

		if (input == 'q') {
			break;
		}

		if (input >= '0' && input <= '9') {
			sum += input - '0';
		}
		else {
			puts("请输入0-9之间的数字");
		}
	}

	printf("您输入的数字之和为%" PRIu32 "\n", sum);*/


	//do-while和while的区别
	/*uint32_t choice;

	do {
		puts("******主菜单******");
		puts("1.新游戏");
		puts("2.载入游戏");
		puts("3.退出");
		puts("4.请选择一个选项");
		
		scanf_s("%" PRIu32, &choice);

		switch(choice) {
		case 1:
			puts("游戏已经启动");
			puts("…………………………");
			puts("游戏已经结束，返回菜单重新选择");
			break;
		case 2:
			puts("载入存档中……");
			puts("存档已载入");
			puts("…………………………");
			puts("游戏已结束，返回菜单重新选择");
			break;
		case 3:
			puts("感谢游玩，再见！");
			puts("游戏已结束，返回菜单重新选择");
			break;
		default:
			puts("无效选项，请重新选择");
		}
	} while (choice != 3);*/


	//生成随机数
	/*uint8_t secret_num, guess;

	srand(time(NULL));

	secret_num = rand() % 100 + 1;

	puts("猜一猜是哪个数(1-100)");

	do {
		puts("请输入你的猜测：");
		scanf_s("%d", &guess);

		if (guess < secret_num) {
			puts("太小了，再猜一猜！");
		}
		else if (guess > secret_num) {
			puts("太大了，再猜一猜");
		}
	} while (guess != secret_num);

	printf("恭喜你，猜对了！答案就是%" PRIu8 "\n", secret_num);*/


	//continue
	/*uint32_t sum = 0;

	int32_t number;

	puts("请输入一系列正数来计算它们的和");
	puts("可以输入复数，但不会被添加到总和之中");
	puts("输入0表示结束并显示总和");

	while (true) {
		puts("请输入一个数：");
		scanf_s("%d", &number);

		if (number == 0) {
			break; // 放前面，提前结束
		}

		if (number < 0) {
			continue;
		}

		sum += number;
	}

	printf("总和为：%" PRIu32 "\n", sum);*/


	//变量 计次 （迭代点）


	//for
	/*uint32_t start_number;

	puts("请输入一个数，我们将从该数开始倒数至1：");
	scanf_s("%" SCNu32, &start_number);

	puts("倒数开始！");

	for (uint32_t index = start_number; index > 0; index--) {
		printf("%" PRIu32 "\n", index);
		Sleep(1000); // 延迟毫秒
	}

	puts("倒数结束！");*/

	/*uint32_t number;

	uint32_t factorial = 1;

	puts("请输入一个数，我们将计算阶乘：");
	scanf_s("%" SCNu32, &number);

	for (uint32_t index = 1; index <= number; index++) {
		factorial *= index;
	}

	printf("!%" PRIu32 " = " "%" PRIu32, number, factorial);*/

	/*uint32_t num;

	bool is_prime = true;

	puts("请输入一个数，我们将判断它是否为素数：");

	scanf_s("%" SCNu32, &num);

	if (num <= 1) {
		is_prime = false;
	}
	else {
		for (uint32_t i = 2; i <= sqrt(num); i++) {
			if (num % i == 0) {
				is_prime = 0;
				break;
			}
		}
	}

	if (is_prime) {
		printf("%" PRIu32 "是素数", num);
	}
	else {
		printf("%" PRIu32 "不是素数", num);
	}*/

	/*uint32_t number;

	puts("输入一个正整数，我们将为您生成一个乘法口诀表：");

	scanf_s("%" SCNu32, &number);

	for (uint32_t index = 1; index <= number; index++) {
		for (uint32_t j = 1; j <= index; j++) {
			printf("%" PRIu32 " * %" PRIu32 " = %" PRIu32 "\t", j, index, j * index);
		}
		printf("\n");
	}*/

	/*uint32_t levels;

	puts("请输入你的层数：");

	scanf_s("%" SCNu32, &levels);

	puts("金字塔图案如下：");

	for (uint32_t i = 1; i <= levels; i++) {

		uint32_t k = 0;

		for (uint32_t j = 1; j <= levels * 2 - 1; j++) {
			if (j <= levels - i) {
				printf("  ");
				continue;
			}

			if (j > levels - i && j <= levels) {
				k++;
				printf("%" PRIu32 " ", k);
				continue;
			}

			if (j > levels && j <= levels + i && k > 1) {
				printf("%" PRIu32 " ", k - 1);
				k--;
			}
		}

		printf("\n");
	}*/

	/*uint32_t levels;

	puts("请输入金字塔的层数：");
	scanf_s("%" SCNu32, &levels);

	puts("金字塔图案如下：");

	for (uint32_t i = 1; i <= levels; i++) {

		uint32_t spaces = levels - i;

		for (uint32_t j = 1; j <= spaces; j++) {
			printf("  ");
		}

		for (uint32_t j = 1; j <= i; j++) {
			printf("%" PRIu32 " ", j);
		}

		for (uint32_t j = i - 1; j >= 1; j--) {
			printf("%" PRIu32 " ", j);
		}

		printf("\n");
	}*/

	
	//打印进度条
	/*const uint32_t total_steps = 50;

	puts("处理中，请稍后……");

	for (uint32_t i = 1; i <= total_steps; i++) {
		printf("\r[");

		for (uint32_t j = 0; j < i; j++) {
			printf("#");
		}

		for (uint32_t j = i; j < total_steps; j++) {
			printf(" ");
		}

		printf("] %" PRIu32 "%%", (i * 100) / total_steps);

		fflush(stdout);

		Sleep(100);
	}
	
	puts("处理完成！");*/	


	//检查组件故障
	/*const uint32_t total_components = 5;

	srand(time(NULL));

	puts("开始健康检查...");

	for (uint32_t i = 0; i < total_components; i++) {
		printf("检查组件 %" PRIu32 "...", i + 1);

		if (check_component_health(i + 1)) {
			printf("组件 %" PRIu32 " 状态良好.\n", i + 1);
		}
		else {
			printf("组件 %" PRIu32 " 出现故障.\n", i + 1);

			printf("修复方案及选择.\n");
		}
	}

	puts("健康检查已完成！");*/


	// 调试输出
	// 从内到外剖析循环，把变量i j k输出，if之前之后，跟踪循环的执行情况，监测每一个循环变量的变化
	// 逐步增加复杂性


	//数组定义时下表需为常量，const也不可以，define可以
	/*uint32_t grades[STUDENT_COUNT] = { 98, 99, 94, 96, 100 };

	uint32_t sum = 0;

	uint32_t max_grade = grades[0];

	uint32_t min_grade = grades[0];

	puts("所有人的成绩如下：");

	for (uint32_t index = 0; index < STUDENT_COUNT; index++) {
		printf("学生%" PRIu32 "的成绩是：%" PRIu32 "\n", index + 1, grades[index]);

		sum += grades[index];

		if (grades[index] > max_grade) {
			max_grade = grades[index];
		}

		if (grades[index] < min_grade) {
			min_grade = grades[index];
		}
	}

	double average_grade = (double)sum / STUDENT_COUNT;

	printf("五个学生的总成绩为：%" PRIu32 "\n", sum);
	printf("平均成绩为：%.2f\n", average_grade);
	printf("最高成绩：%" PRIu32 "\n", max_grade);
	printf("最低成绩：%" PRIu32 "\n", min_grade);*/


	//统计字母出现频率
	/*uint32_t frequency[LETTER_COUNT] = { 0 };

	char text[] = "Example text for frequency analysis.";

	for (uint32_t index = 0; text[index] != '\0'; index++) {
		char ch = tolower(text[index]);

		if (ch >= 'a' && ch <= 'z') {
			frequency[ch - 'a']++;
		}
	}

	puts("字母频率：");

	for (uint32_t index = 0; index < LETTER_COUNT; index++) {
		if (frequency[index] > 0) {
			printf("%c: %d\n", 'a' + index, frequency[index]);
		}
	}*/


	//隐式确定数组大小的初始化
	/*int arr1[] = { 1, 2, 3, 4 };

	int arr2[] = { 0 };

	printf("%d\n", arr2[1]); // debug和release结果不同
	*/


	//二维数组隐式初始化
	/*int matrix[][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		{0, 0, 0}
	}*/


	//五子棋棋盘绘制
	


	//农场作物成长
	


	//函数
	/*printf("%lf\n", square_area(6.6));

	printf("%lf\n", rectangle_area(3.5, 9.6));

	printf("%lf\n", circle_area(7.8));

	int year = 2025;

	printf("%d年%s", year, is_leap_year(year) ? "是闰年" : "不是闰年");*/


	//石头剪刀布与软件工程的规则映射
	


	//表驱动法
	//使用数据结构（srray，hash）替代复杂的逻辑语言
	//核心思想：很多程序行为可以通过查表获取，而不是复杂的条件语句
	//1.识别：确定程序中可以用查表替代的逻辑部分
	//2.设计：创建包含所有可能输入和对应输出的表（数组或hash）
	//3.实现：编写代码，使用输入作为索引或者键来查找表中相应输出
	//4.优化：根据需要，调整表的结构以提高效率或者可读性
	/*int res_day = get_days_in_month(2, 2024);

	printf("%d\n", res_day);

	printf("%c\n", get_grade(98));*/


	//尾递归
	//printf("%" PRIu32 "\n", factorial(11, 1));

	
	//企业使用迭代方法替代递归
	//printf("%u对应的斐波那契数为：%u\n", 17, fibonacci_interative(17));

	
	 //企业规范，void作为函数参数的必要性
	/*greet1();
	greet2();*/


	//作用域Scope，函数，文件，整个程序（配置文件）


	//生命周期
	//内存泄漏、访问已经被销毁的变量（悬挂引用）、过度消耗资源


	//局部变量（Local Variables）
	//作用域限定
	//自动存储期
	//初始值未定义


	//全局变量
	//程序范围的可见性
	//静态存储期
	//默认初始化
	//跨越函数边界，共享数据
	//减少函数的边界，使用全局变量可以减少需要传递给函数的参数变量，简化调用
	//减低代码的可读性，难以追踪
	//增加错误的风险
	//线程安全问题：在多线程环境中，未加锁的全局变量可能会导致数据竞争和不一致问题


	//静态变量（static variables）
	//静态局部变量
	//静态局部变量在函数内部声明，并且程序执行的期间只初始化一次，即使函数执行结束，它的值也不会消失
	//而是保持到下一次函数的调用，跨函数调用保持状态和计数
	/*for (int i = 0; i < 3; i++) {
		increment_counter1();
	}
	printf("\n");

	for (int i = 0; i < 3; i++) {
		increment_counter2();
	}
	printf("\n");*/


	//通过extern关键字声明对外部文件的全局变量访问
	//extern int g_static_var
	//静态全局变量只在本文件可用


	//register寄存器声明
	//demo_reg_var();


	//作用域
	//链接性（Linkage）：外部、内部、无
	//块作用域（Block Scope）


	//函数的注释


	//取地址
	/*int building_floors[5] = { 101, 102, 103, 104, 105 };

	int target_floor = 103;

	bool found = 0;

	printf("开始寻找目标用户%d\n", target_floor);

	for (int i = 0; i < 5; i++) {
		printf("用户%d的地址为：%p\n", building_floors[i], (void*)&building_floors[i]);
	}

	for (int i = 0; i < 5; i++) {
		if (building_floors[i] == target_floor) {
			printf("目标用户%d的地址为：%p\n", target_floor, (void*)building_floors[i]);
		}
	}*/


	//指针与修改
	/*int building_floors[3] = { 101, 102, 103 };

	int *ptr_floor_103 = &building_floors[2];

	printf("building_floor[2]的地址是：%p\n", &building_floors[2]);

	printf("ptr_floor_103指针变量保存的地址是：%p\n", ptr_floor_103);

	printf("ptr_floor_103指针变量的地址是：%p\n", &ptr_floor_103);

	printf("通过 * 去找变量：%d\n", *ptr_floor_103);

	printf("没有 * 输出地址：%p\n", ptr_floor_103);

	int* ptr_new_106 = ptr_floor_103;

	*ptr_new_106 = 106;

	printf("修改后的building_floor[2]值：%d\n", building_floors[2]);*/


	//指针星号的企业风格规范以及容易引发的问题
	/*int* p; // 微软写法，表明强调p这个变量是一个int*（整型指针）类型的变量
	
	int *p; // 更强调这个变量实际上是一个指针
	
	int* p, q;

	int value = 100;

	p = &value;

	q = value;

	printf("p指向的地址为：%p, q的值为：%d\n", p, q);

	int* p, * q; // 微软规范
	int *p, *q;*/


	//野指针和空指针
	//野指针：指向了一个无效的内存地址或者是已经释放内存地址的指针，非常危险，
	//野指针会访问一个不可描述的内存空间，会导致不可预测的行为
	//空指针：通常指没有指向任何有效内存地址的指针
	

	//空指针初始化
	/*uint32_t* ptr_to_floor = NULL;

	uint32_t num = 100;

	ptr_to_floor = &num;

	if (ptr_to_floor == NULL) {
		printf("没有指定地址的数据\n");
	}
	else {
		printf("地址%p的数据为：%" PRIu32 "\n", (void*)ptr_to_floor, *ptr_to_floor);
	}*/


	//从代码上尝试认识野指针
	/*int floor_number = 103;

	int* ptr_to_floor = &floor_number;

	printf("当前数据为：%d，地址为：%p\n", *ptr_to_floor, (void*)ptr_to_floor);

	{
		int temp = 104;

		ptr_to_floor = &temp;
	}

	printf("尝试访问新的数据，地址为：%p，数据为：%d\n", (void*)ptr_to_floor, *ptr_to_floor);*/


	//数组的首地址，指针的算术运算与比较运用
	//数组的运算结果是ptrdiff_t类型
	/*int numbers[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	int* ptr = numbers;

	int size = sizeof(numbers) / sizeof(numbers[0]);

	printf("size = %d\n", size);

	printf("数组数据为：\nnumbers[] = { ");

	for (int i = 0; i < size; i++) {
		printf("%d ", numbers[i]);
	}

	printf("}\n\n");

	printf("使用指针加法访问第5个元素：\n");

	ptr += 4;

	printf("numbers[ptr += 4] = %d\n\n", *ptr);

	printf("使用指针减法访问第1个元素：\n");

	ptr -= 4;

	printf("numbers[ptr -= 4] = %d\n\n", *ptr);

	int* start_ptr = &numbers[0];

	int* end_ptr = &numbers[size - 1];

	printf("数组之间的距离是：%td\n\n", end_ptr - start_ptr);

	puts("比较指向的元素：");
	if (start_ptr < end_ptr) {
		printf("start_ptr指向的元素在end_ptr指向的元素之前\n");
	}

	if (end_ptr > start_ptr) {
		printf("end_ptr指向的元素在start_ptr指向的元素之后\n");
	}

	printf("使用指针遍历数组\n外部指针遍历*p = { ");
	for (int* p = start_ptr; p <= end_ptr; p++) {
		printf("%d ", *p);
	}
	printf(" }\n\n");

	printf("使用指针减法逐个访问数组中每个元素的反向顺序\n*p = { ");
	for (int* p = end_ptr; p >= start_ptr; p--) {
		printf("%d ", *p);
	}
	printf(" }\n\n");

	puts("指针加法访问特定元素：");
	int offset = 3;
	printf("第四个元素（使用加法）：*（start_ptr + offset） = %d\n\n", *(start_ptr + offset));

	printf("回退到第三个元素（从第四个元素开始回退）：*（start_ptr + offset - 1） =%d\n\n", *(start_ptr + offset - 1));

	int* middle_ptr = &numbers[size / 2];

	puts("比较两个指针的位置：");
	if (start_ptr < middle_ptr) {
		puts("start_ptr指向的元素在middle_ptr所指向的元素之前\n");
	}
	if (end_ptr > middle_ptr) {
		puts("end_ptr指向的元素在middle_ptr所指向的元素之后\n");
	}*/


	//size_t与指针和数组的使用
	//seze_t是一个无符号的整数类型，专门用来表示大小、长度和索引，
	//提高程序在不同平台（跨平台）的可移植性和安全性
	/*int32_t arrays[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	int32_t* ptr = arrays;

	puts("输出数组：");

	size_t arrays_size = sizeof(arrays) / sizeof(arrays[0]);

	for (size_t i = 0; i < arrays_size; ++i) {
		printf("%" PRIu32 " ", arrays[i]);
	}

	printf("\n");

	for (size_t i = 0; i < arrays_size; ++i) {
		*(ptr + i) += 5;
	}

	printf("修改后的数组：\n");

	for (size_t i = 0; i < arrays_size; ++i) {
		printf("%" PRIu32 " ", *(ptr + i));
	}

	printf("\n");*/


	//指针查找特定元素的索引并返回
	/*int32_t values[] = { 10, 20, 30, 40, 50 };

	int32_t* start_ptr = values;

	size_t values_size = sizeof(values) / sizeof(values[0]);

	int32_t target_values = 30;
	int32_t* target_ptr = NULL;

	size_t index = 0;

	bool found = false;

	for (size_t i = 0; i < values_size; ++i) {
		if (*(start_ptr + i) == target_values) {
			target_ptr = start_ptr + i;

			index = i;

			found = true;

			break;
		}
	}

	if (found) {
		printf("元素 %" PRIu32 " 的INDEX：%zu\n", target_values, index);
	}
	else {
		printf("元素 %" PRIu32 " 未找到！\n", target_values);
	}*/

	/*int32_t values[] = { 10, 20, 30, 40, 50 };

	int32_t* start_ptr = values;

	size_t values_size = sizeof(values) / sizeof(values[0]);

	int32_t target_values = 30;
	int32_t* target_ptr = NULL;

	size_t index = 0;

	bool found = find_index_of_value(values, values_size, target_values, &index);

	if (found) {
		printf("元素 %" PRIu32 " 的INDEX：%zu\n", target_values, index);
	}
	else {
		printf("元素 %" PRIu32 " 未找到！\n", target_values);
	}*/


	//指针访问多维数组
	/*int matrix[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	int(*ptr)[3] = matrix;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d ", ptr[i][j]);
		}
	}
	printf("\n");*/


	//指针数组
	/*int32_t department1[] = { 1001, 1002, 1003, 1004 };
	int32_t department2[] = { 2001, 2002, 2003 };
	int32_t department3[] = { 3001, 3002 };

	int32_t* department_ptrs[3] = {
		department1, department2, department3
	};

	size_t department_sizes[3] = {
		sizeof(department1) / sizeof(int32_t),
		sizeof(department2) / sizeof(int32_t),
		sizeof(department3) / sizeof(int32_t)
	};

	for (size_t i = 0; i < 3; i++) {
		printf("Department %zu: ", i + 1);
		for (size_t j = 0; j < department_sizes[i]; j++) {
			printf("%" PRId32 " ", department_ptrs[i][j]);
		}
		printf("\n");
	}*/


	//函数的值传递与地址引用传递
	/*int32_t my_value = 5;

	printf("原值：%" PRId32 "\n", my_value);

	add_ten_by_values(&my_value);

	printf("现值：%" PRId32 "\n", my_value);*/


	






	return 0;
}



void add_ten_by_values(int32_t* value) {
	*value += 10;
}

bool find_index_of_value(const int32_t* array, size_t size, int32_t target_value, size_t* index) {
	for (size_t i = 0; i < size; ++i) {
		if (*(array + i) == target_value) {
			*index = i;
			return true;
		}
	}

	return false;
}

void demo_reg_var(void) {
	//声明寄存器变量
	//建议寄存器，尽可能将counter放到寄存器中
	register int counter;

	for (counter = 0; counter < 10; counter++) {
		printf("%d\n", counter);
	}
	//不能使用&counter获得地址
}

void increment_counter1(void) {
	int counter1 = 0;

	counter1++;

	printf("%d\t", counter1);
}

void increment_counter2(void) {
	static int counter2 = 0;

	counter2++;

	printf("%d\t", counter2);
}

void greet2() {
	printf("Greeting !\n");
}

void greet1(void) {
	printf("Greeting !\n");
}

uint32_t fibonacci_interative(uint32_t num) {
	if(num <= 1){
		return num;
	}

	uint32_t fib_n_minus_2 = 0;
	uint32_t fib_n_minus_1 = 1;

	uint32_t fib_n = 0;

	for (uint32_t i = 2; i <= num; ++i) {
		fib_n = fib_n_minus_1 + fib_n_minus_2;
		fib_n_minus_2 = fib_n_minus_1;
		fib_n_minus_1 = fib_n;
	}

	return fib_n;
}

int factorial(uint32_t num, uint32_t acc) {
	if (num == 0) {
		return acc;
	}
	
	return factorial(num - 1, num * acc);
}

char get_grade(int score) {
	const char grades[GRADE_COUNT] = {
		'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'S'
	};

	return grades[score / 10];
}

int get_days_in_month(int month, int year) {
	const int days_in_month[MONTH_COUNT] = {
		31,
		is_leap_year(year) + 28,
		31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	return days_in_month[month - 1];
}

bool is_leap_year(int year) {
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

double square_area(double side) {
	return side * side;
}

double rectangle_area(double length, double width) {
	return length * width;
}

double circle_area(double redius) {
	return redius * redius * PI;
}

void print_binary(uint8_t num) {
	for (int index = 7; index >= 0; index--) {
		printf("%d", (num >> index) & 1);
	}
}

bool check_component_health(uint32_t component_id) {
	if (rand() % 10 < 2) {
		return false;
	}

	return true;
}