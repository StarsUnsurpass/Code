#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crtdbg.h>



#define SIZE 50



void my_invalid_parm_handler(const wchar_t* expression, const wchar_t* function, const wchar_t* file, unsigned int line,
	uintptr_t p_reserved) {
	wprintf(L"Invalid parameter detected in function %s. File: %s Line %d\n", function, file, line);
	wprintf(L"Expression: %s\n", expression);
}



int main3(void) {
	//字符串
	//以'\0'作为结尾
	//用字符数组定义时不要显式定义（容易忽略字符串长度）
	//用指针定义的不可被修改
	/*char c = 't';

	char arr[] = { "Hello" };

	char string[6] = "hello";

	printf("%s\n", string);

	const char arrr[] = { "Hello" };

	const char* ptr = "Hello";*/


	//strcpy_s的用法
	//引入头文件string.h
	//和输入输出以及字符串相关的加_s
	//返回值是errno_t
	/*const char src[] = "hello";

	char dest[SIZE];

	strcpy_s(dest, SIZE, src);

	printf("src = %s\n", src);

	printf("dest = %s\n", dest);

	errno_t err = strcpy_s(dest, sizeof(dest), src);*/


	//VS编译器捕获字符异常
	//strcpy_s第二个参数不满足时，debug时报错，release不报错
	//release时生效
	/*_set_invalid_parameter_handler(my_invalid_parm_handler);

	const char src[] = "hello";

	char dest[2];

	errno_t err = strcpy_s(dest, sizeof(dest), src);

	if (err != 0) {
		printf("Error copying string. Erroe code: %d\n", err);
	}
	else {
		printf("%s\n", dest);
	}*/


	//strlen
	//'\0'不计入
	/*char dest[50] = { "hello" };

	printf("%zd\n", strlen(dest));*/
	//微软建议
	/*char dest[50] = { 0 };

	strcpy_s(dest, 50, "hello");

	printf("%zd\n", strlen(dest));*/


	//strcat_s
	/*char dest[50] = { 0 };
	strcpy_s(dest, sizeof(dest), "Hello");

	const char* src = ", World!\n";

	rsize_t dest_size = sizeof(dest) - strlen(dest) - 1;

	strcat_s(dest, dest_size, src);

	printf("%s", dest);*/


	//sprintf_s
	//格式化为字符串输出
	/*char buffer[50] = { 0 };
	int number = 3;
	double pi = 3.1415926;

	int ret = sprintf_s(buffer, sizeof(buffer), "Integer: %d\tDouble: %.2f", number, pi);

	if (ret > 0) {
		printf("Formatted string: %s\n", buffer);
	}
	else {
		printf("Error Formatting string!\n");
	}*/


	//strncpy_s
	//指定复制字符数
	/*char dest[20];
	const char* src = "Hello, World!\n";

	size_t max_copy = 10;

	errno_t result = strncpy_s(dest, sizeof(dest), src, max_copy);

	if (result == 0) {
		printf("Copied string: %s\n", dest);
	}
	else {
		printf("Error copying string!\n");
	}*/


	//srcncat_s
	//限制最多添加字符数
	/*char dest[20] = { 0 };
	strcpy_s(dest, sizeof(dest), "Hello");
	const char* str = ", World!\n";

	size_t max_append = 5;

	int result = strncat_s(dest, sizeof(dest), str, max_append);

	if (result == 0) {
		printf("Concatenated string: %s\n", dest);
	}
	else {
		printf("Error concanenating string!\n");
	}*/


	//gets_s
	//注意事项：确保缓冲区足够大
	//早期：gets无限制，被舍弃，gets_s成为C11标准
	/*char buffer[100];

	printf("Enter a string:\n");

	if (gets_s(buffer, sizeof(buffer)) == NULL) {
		printf("Error or end of file encountered.\n");
	}
	else {
		printf("you entered: %s\n", buffer);
	}*/


	//strtok早期在多线程下安全性问题很大
	//strtok_s
	//按要求拆分字符串
	//chat* context保存strtok_s函数在其内部位置之间的上下文指针
	//strtok_s(NULL, delim, &context)从上一个分割的位置开始
	/*char str[] = "This is a sample string";
	char delim[] = " ";
	char* token;
	char* context = { 0 };

	token = strtok_s(str, delim, &context);

	while (token != NULL) {
		printf("Token: %s\n", token);
		token = strtok_s(NULL, delim, &context);
	}*/


	//strcmp
	/*const char* str1 = "Hello, World!";
	const char* str2 = "Hello, World!";
	const char* str3 = "Hello, Guys!";

	if (strcmp(str1, str2) == 0) {
		printf("str1 and str2 are equal!\n");
	}
	else {
		printf("str1 and str2 are not equal!\n");
	}

	if (strcmp(str1, str3) == 0) {
		printf("str1 and str3 are equal!\n");
	}
	else {
		printf("str1 and str3 are not equal!\n");
	}

	if (strcmp(str2, str3) > 0) {
		printf("str2 is greater than str3!\n");
	}
	else {
		printf("str2 is less than str3!\n");
	}*/


	//strncmp
	//比较前n个字符
	/*const char* str1 = "Hello, World!";
	const char* str2 = "Hello, World!";
	const char* str3 = "Hello, Guys!";

	size_t size = 7;

	if (strncmp(str1, str2, size) == 0) {
		printf("str1 and str2 are equal!\n");
	}
	else {
		printf("str1 and str2 are not equal!\n");
	}

	if (strncmp(str1, str3, size) == 0) {
		printf("str1 and str3 are equal!\n");
	}
	else {
		printf("str1 and str3 are not equal!\n");
	}

	if (strncmp(str2, str3, size) > 0) {
		printf("str2 is greater than str3!\n");
	}
	else if (strncmp(str2, str3, size) < 0) {
		printf("str2 is less than str3!\n");
	}
	else {
		printf("str1 and str3 are equal!\n");
	}*/


	//strchr与strrchr
	//__int64
	//long ld long 32 ptrdiff_t
	/*const char* str = "Hello, Wowrlwd!";

	char to_find = 'w';

	const char* ptr_char = strchr(str, to_find);

	const char* ptr_reverse_char = strrchr(str, to_find);

	if (ptr_char) {
		printf("找到了，'%c'的位置是：%td\n", to_find, ptr_char - str + 1);
	}
	else {
		printf("没找到");
	}

	if (ptr_reverse_char) {
		printf("找到了，'%c'的位置从后往前是：%td\n", to_find, ptr_reverse_char - str + 1);
	}
	else {
		printf("没找到");
	}*/


	//strstr
	//空字符串返回NULL
	/*const char* text = "This is a simple test simple string.";
	const char* sub = "simple";

	const char* result = strstr(text, sub);

	if (result != NULL) {
		printf("Found '%s' in \"%s\" at position: %td\n", sub, text, result - text + 1);
	}
	else {
		printf("Substring '%s' not found in \"%s\".\n", sub, text);
	}*/


	//strspn开头连续包含最大相同子字符集个数
	//strcspn开头连续不包含最大相同子字符集个数
	//验证字符串是否有非法字符
	//第一个参数是被扫描的字符串，第二个参数是拒绝字符集
	/*const char* str1 = "1234567asdf890";
	const char* str2 = "1234567890";
	const char* str3 = "asdfqerutn";

	size_t len1 = strspn(str1, str2);
	size_t len2 = strcspn(str1, str3);
	size_t len3 = strcspn(str3, str1);

	printf("%zu\n", len1);
	printf("%zu\n", len2);
	printf("%zu\n", len3);

	char input1[] = "filename.txt";
	char input2[] = "fil???enmae.txt";

	char invalid_chars[] = "/\\:*?\"<>|";

	if (strcspn(input1, invalid_chars) < strlen(input1)) {
		printf("Input contains invalid characters.\n");
	}
	else {
		printf("Input is valid.\n");
	}

	if (strcspn(input2, invalid_chars) < strlen(input2)) {
		printf("Input contains invalid characters.\n");
	}
	else {
		printf("Input is valid.\n");
	}*/


	//指针修改遍历字符串
	//char* p定义的字符串不可被修改
	/*char str[] = "Hello";
	char* ptr = str;

	ptr[1] = 'a';

	printf("%s\n", str);

	while (*ptr != '\0') {
		printf("%c", *ptr);
		ptr++;
	}*/


	return 0;
}