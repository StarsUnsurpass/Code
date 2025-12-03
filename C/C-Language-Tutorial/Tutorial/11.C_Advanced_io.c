#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SIZE 50
#define BUFFER_SIZE 1024

typedef struct GameSettings {
	float volume;
	int resolution_x;
	int resolution_y;
	int difficulty;
} GameSettings;

void read_config_safe(const char* filename);

void append_log_safe(const char* filename, const char* msg);

void clear_log(const char* filename);

errno_t update_log_record_s(const char* filename, const char* search_str, const char* replace_str);

void save_game_settings(const GameSettings* settings, const char* filename);

void load_game_settings(GameSettings* settings, const char* filename);

int main5(void) {
	SetConsoleOutputCP(CP_UTF8);
	//input stream
	//output stream
	//buffer
	//输入流的数据首先被暂存到一个叫缓冲区的内存区

	//_s避免缓冲区溢出
	//scanf_s
	//早期微软使用宏_countof
	/*char name[SIZE];

	printf("Enter your name: ");
	scanf_s("%49s", name, (unsigned int)sizeof(name));

	printf("Hello, %s!", name);*/

	/*char ch;

	printf("Enter a character: ");
	scanf_s("%c", &ch, 1);

	printf("you entered: %c", ch);*/

	/*int age;
	
	printf("Enter an age:\n");

	scanf_s("%d", &age);

	printf("you entered: %d\n", age);*/


	//可通过#define scanf_s scanf


	//scanf_s返回值
	//返回值为1时成功，用来检测输入问题
	//EOF: End of file -1, int类型
	//专门用来指示文件读取或输入操作已经达到了数据源的末尾
	//Ctrl Z回车
	/*int number;
	int result;

	puts("Enter an integer:");

	result = scanf_s("%d", &number);
	if (result == 1) {
		printf("You entered the integer: %d\n", number);
	}
	else if (result == EOF) {
		printf("An error occurred or end of file was reached.\n");
		return 1;
	}
	else {
		printf("Invalid input for integer.\n");
		return 1;
	}*/


	//文件输入未保存时存在缓冲区内，保存后释放缓冲区，存入硬盘
	//stream流
	//1.文件流：磁盘，用于读取与写入在磁盘上的文件
	//2.标准I/O流
	//stdin：默认连接到键盘，用于程序输入	scanf_s
	//stdout：默认连接到控制台或屏幕，用于程序输出	printf
	//stderr：默认连接到控制台或屏幕，专门输出错误信息和警告，使得其能够被区分开来或者重定向到不同的目的地
	//3.管道流：用于进程之间的通信（IPC），允许一个进程的输入成为另一个进程的输出	popen（）
	//4.内存流：允许将流与内存缓冲区关联，可以向内存中读写数据，像操作文件一样	POSIX -> fmemopen
	//5.网络流：套接字（Sockets）
	//6.设备流：特殊文件或设备（打印机）
	//通过FILE* stream使用各种流


	//fopen_s, fgetc, fgets, fclose读取r模式
	/*FILE* file_stream = NULL;

	char buffer[256];

	// 打开文件，设定文件路径要读取的文件，设定文件操作模式r
	errno_t err = fopen_s(&file_stream, "E:\\MyDoc\\Obsidian\\my_article\\时滞瞬间\\时滞瞬间_终稿.md", "r");

	// 错误处理
	// 文件路径不对，文件不存在，文件出现异常，文件没有权限访问...
	if (err != 0 || file_stream == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	// 读取一行
	fgets(buffer, sizeof(buffer), file_stream);

	printf("%s\n", buffer);

	// 一行一行读，不能超出缓冲区
	while (fgets(buffer, sizeof(buffer), file_stream) != NULL) {
		printf("%s", buffer);
	}

	// 关闭
	fclose(file_stream);*/
	/*FILE* file_stream = NULL;

	char buffer[256];

	// 打开文件，设定文件路径要读取的文件，设定文件操作模式r
	errno_t err = fopen_s(&file_stream, "E:\\MyDoc\\Obsidian\\my_article\\时滞瞬间\\时滞瞬间_终稿.md", "r");

	// 错误处理
	// 文件路径不对，文件不存在，文件出现异常，文件没有权限访问...
	if (err != 0 || file_stream == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	// 读取一个字符
	int ch;
	ch = fgetc(file_stream);
	putchar(ch);

	// 一个字符一个字符读，速度比一行一行读慢
	while ((ch = fgetc(file_stream)) != EOF) {
		putchar(ch);
	}

	// 关闭
	fclose(file_stream);*/
	/*FILE* file_stream = NULL;

	char buffer[256];

	errno_t err = fopen_s(&file_stream, "E:\\MyDoc\\Obsidian\\my_article\\时滞瞬间\\时滞瞬间_终稿.md", "r");

	if (err != 0 || file_stream == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}
	fgets(buffer, sizeof(buffer), file_stream);

	printf("%s\n", buffer);

	while (fgets(buffer, sizeof(buffer), file_stream) != NULL) {
		printf("%s", buffer);
	}


	//读完一次后file_stream指针已经把所有文件都循环读完了，指针指到最后一个位置
	//再往下读，什么也没有，只能读一次

	//重新设置缓冲区
	memset(buffer, 0, sizeof(buffer));

	//指针指向最初位置
	printf("\n");
	rewind(file_stream);

	int ch;
	ch = fgetc(file_stream);
	putchar(ch);

	while ((ch = fgetc(file_stream)) != EOF) {
		putchar(ch);
	}

	//文件关闭报错提示
	if (fclose(file_stream) != 0) {
		perror("Error closing file");
		return EXIT_FAILURE;
	}*/

	
	//fputs, fputc与w模式
	//w覆盖写入
	/*FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\test.txt", "w");

	if (err != 0 || file_ptr == NULL) {
		perror("Failed to open file");
		return EXIT_FAILURE;
	}

	fputc('H', file_ptr);
	fputc('i', file_ptr);
	fputc('\n', file_ptr);

	fputs("This is a line written by fputs.\n", file_ptr);

	double pi = 3.14;

	fprintf_s(file_ptr, "Numbers: %d, %lf, %s\n", 10, pi, "\nEnd of example.");

	fputs("hello", file_ptr);

	fclose(file_ptr);

	puts("File test.txt has been written successfully.\n");*/

	
	//ftell, fseek, rewind
	//r+打开以便文件读取和写入，文件必须存在
	//中文冒号和英文冒号区别，中文输出乱码
	/*FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\test.txt", "r+");

	if (err != 0 || file_ptr == NULL) {
		perror("无法打开文件");
		return EXIT_FAILURE;
	}

	// 使用ftell获取当前文件指针的位置
	long position = ftell(file_ptr);
	printf("当前位置: %ld\n", position);

	// 开始读取
	char buffer[100];
	if (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
		printf("从文件读取: %s", buffer);
		// 再次使用ftell获取新位置，\r\n换行
		position = ftell(file_ptr);
		printf("读取后的新位置: %ld\n", position);
	}
	// 使用fseek后移动到开始的位置
	fseek(file_ptr, 0, SEEK_SET);
	printf("使用fseek后移动到开始的位置，SEEK_SET = 0: %ld\n", ftell(file_ptr));
	//rewind
	rewind(file_ptr);
	printf("使用rewind直接移动到开始的位置: %ld\n", ftell(file_ptr));

	fclose(file_ptr);*/


	//fscanf_s
	//读取最后一个字符时需要加空格
	/*FILE* stream = NULL;
	long l;
	float fp;
	char s[81];
	char c;

	errno_t err = fopen_s(&stream, "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\test.txt", "r");
	if (err) {
		printf_s("The file wasn't opened\n");
	}
	else {
		if (fscanf_s(stream, "%80s", s, (unsigned)_countof(s)) != 1) {
			printf("error in reading string\n");
		}
		if (fscanf_s(stream, "%ld", &l) != 1) {
			printf("error in reading ld\n");
		}
		if (fscanf_s(stream, "%f", &fp) != 1) {
			printf("error in reading lf\n");
		}
		if (fscanf_s(stream, " %c", &c, 1) != 1) {
			printf("error in reading c\n");
		}
	}

	printf("%s\n", s);
	printf("%ld\n", l);
	printf("%f\n", fp);
	printf("%c\n", c);

	fclose(stream);*/


	//fprintf
	//格式化写入文件
	/*FILE* stream;

	int id = 1;
	float temperature = 36.5f;
	char name[] = "Ace";
	char grade = 'S';

	errno_t err = fopen_s(&stream, "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\test.txt", "w+");

	if (err != 0) {
		printf_s("error in opening file!\n");
		return EXIT_FAILURE;
	}

	fprintf(stream, "ID: %d\n", id);
	fprintf(stream, "Name: %s\n", name);
	fprintf(stream, "Temperature: %.1f\n", temperature);
	fprintf(stream, "Grade: %c\n", grade);

	fclose(stream);

	printf("data written ended!\n");*/


	//ferror 检查文件流是否有错误发生，如果有，返回一个非零值，否则返回零，检查文件读写操作错误，和文件打开错误不同
	//feof 检查文件流是否到达了末尾，如果文件指针到达了末尾，返回一个非零值，否则返回零
	//clearerr 清除与文件流相关的错误和标志
	/*FILE* file_ptr;

	errno_t err = fopen_s(&file_ptr, "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\test.txt", "w+");

	if (err != 0) {
		printf_s("error in opening file!\n");
		return EXIT_FAILURE;
	}

	char buffer[100];

	while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
		printf("%s", buffer);
	}

	if (ferror(file_ptr)) {
		perror("error in reading file!");
		clearerr(file_ptr);
	}

	if (feof(file_ptr)) {
		printf("already reached the end of file...\n");
	}

	else {
		printf("already reached the end of file, but with error!\n");
	}

	fclose(file_ptr);*/


	//抽离读写函数
	/*const char* filename = "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\game_config.txt";

	read_config_safe(filename);*/


	//a模式追加
	//_fcloseall把所有流全部关闭，保险操作
	/*const char* config_filename = "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\config.txt";
	
	const char* log_filename = "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\log.txt";

	read_config_safe(config_filename);

	const char* str = "create";

	append_log_safe(log_filename, str);

	int numclosed = _fcloseall();

	printf("Number of files closed by _fcloseall: %u\n", numclosed);*/


	//w模式清空
	//clear_log(log_filename);


	//企业实际案例：修改log, r+模式
	/*const char* log_file = "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\Ace.log";
	const char* search_str = "FAILED (remote: 'unknown command')";
	const char* replace_str = "[2025-10-21T12:33:20Z] [INFO] Command found.\n";

	errno_t result = update_log_record_s(log_file, search_str, replace_str);

	if (result != 0) {
		char error_msg[256];
		strerror_s(error_msg, sizeof(error_msg), result);
		fprintf(stderr, "Am error occurred: %s\n", error_msg);
	}
	else {
		printf("Record update successfully.\n");
	}

	_fcloseall();*/


	//fflush 立刻保存
	//多线程
	//单线程防止程序崩溃未保存
	//错误日志


	//fread, fwrite
	//读写二进制文件，图像、音频等
	/*GameSettings settings = { 0.75, 1920, 1080, 2 };

	save_game_settings(&settings, "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\game_settings.bin");

	GameSettings loaded_settings;

	load_game_settings(&loaded_settings, "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\game_settings.bin");

	printf("game loaded!\n");
	printf("Volume: %f\nResolution: %d x %d\nDifficult: %d\n",
		loaded_settings.volume,
		loaded_settings.resolution_x,
		loaded_settings.resolution_y,
		loaded_settings.difficulty);*/


	//复制文件
	/*FILE* source_file, * target_file;

	char source_path[] = "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\test.txt";
	char target_path[] = "E:\\MyDoc\\Programs\\VS\\C_Learning\\file_testing\\QI.txt";

	char buffer[1024];

	size_t bytes_read;

	errno_t err = fopen_s(&source_file, source_path, "rb");
	if (err != 0 || source_file == NULL) {
		perror("error in opening source file!\n");
		return EXIT_FAILURE;
	}

	err = fopen_s(&target_file, target_path, "wb");
	if (err != 0 || target_file == NULL) {
		perror("error in opening target file!\n");
		fclose(source_file);
		return EXIT_FAILURE;
	}

	while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
		fwrite(buffer, 1, bytes_read, target_file);
	}

	_fcloseall();

	puts("file copying complicated!");*/



	return 0;
}

void save_game_settings(const GameSettings* settings, const char* filename) {
	FILE* file;
	errno_t err = fopen_s(&file, filename, "wb");

	if (err != 0 || file == NULL) {
		perror("error in opening the file and write!");
		return;
	}

	fwrite(settings, sizeof(GameSettings), 1, file);

	fclose(file);
}

void load_game_settings(GameSettings* settings, const char* filename) {
	FILE* file;
	errno_t err = fopen_s(&file, filename, "rb");

	if (err != 0 || file == NULL) {
		perror("error in reading the file and write!");
		return;
	}

	fread(settings, sizeof(GameSettings), 1, file);

	fclose(file);
}

errno_t update_log_record_s(const char* filename, const char* search_str, const char* replace_str) {
	if (filename == NULL || search_str == NULL || replace_str == NULL) {
		return EINVAL;
	}

	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, filename, "r+");

	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];
		strerror_s(error_msg, sizeof(error_msg), errno);

		fprintf(stderr, "Failed to open config file for reading: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	char buffer[BUFFER_SIZE];
	long position = 0;
	int found = 0;

	while (fgets(buffer, BUFFER_SIZE, file_ptr) != NULL) {
		if (strstr(buffer, search_str) != NULL) {
			found = 1;
			position = ftell(file_ptr) - (long)strlen(buffer) - 1;
			break; // 找到第一项立刻停止
		}
	}

	if (found) {
		fseek(file_ptr, position, SEEK_SET); // 移动回到找到记录之前的位置

		// 计算替换文本与源文本的长度差异
		size_t replace_len = strlen(replace_str);
		size_t search_len = strlen(search_str);

		if (replace_len > BUFFER_SIZE - 1 || search_len > BUFFER_SIZE - 1) {
			fclose(file_ptr);

			return ERANGE; // 返回错误码，表示字符串长度超出范围
		}

		// 写入新纪录之前，清除所在位置的行数据
		memset(buffer, ' ', strlen(buffer) - 1); // 用空格填充，保持源文件大小不变

		buffer[strlen(buffer) - 1] = '\n'; // 保留换行符

		fseek(file_ptr, position, SEEK_SET); // 重新回到标记行的开始

		fputs(buffer, file_ptr); // 清除原来行的内容

		fseek(file_ptr, position, SEEK_SET); // 重新回到标记行的开始

		int result = fputs(replace_str, file_ptr); // 写入替换的字符串

		if (result == EOF) {
			fclose(file_ptr);
			return errno;
		}
	}

	else {
		fclose(file_ptr);
		return ENOENT; // 返回未找到的匹配项
	}

	fclose(file_ptr);

	return 0;
}

void clear_log(const char* filename) {
	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, filename, "w");

	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];
		strerror_s(error_msg, sizeof(error_msg), errno);

		fprintf(stderr, "Failed to open config file for reading: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	fclose(file_ptr);
}

void append_log_safe(const char* filename, const char* msg) {
	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, filename, "a");

	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];
		strerror_s(error_msg, sizeof(error_msg), errno);

		fprintf(stderr, "Failed to open log file for appending: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	fprintf(file_ptr, "%s\n", msg);

	fclose(file_ptr);
}

void read_config_safe(const char* filename) {
	FILE* file_ptr = NULL;
	errno_t err = fopen_s(&file_ptr, filename, "r");

	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		//企业规范写法

		//将错误信息保存到字符串缓冲区，需要<string.h>头文件
		strerror_s(error_msg, sizeof(error_msg), errno);

		//不对文件进行读取，将缓冲区错误信息放到stderr，不一定是屏幕，printf只能输出到屏幕
		fprintf(stderr, "Failed to open config file for reading: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
		printf("%s", buffer);
	}

	//写操作这样对判断进行处理关闭文件，读操作非必要
	/*if (fclose(file_ptr) != 0) {
		perror("Error closing file");
		return EXIT_FAILURE;
	}*/
	fclose(file_ptr);
}