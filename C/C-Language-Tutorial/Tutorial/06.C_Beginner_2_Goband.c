// Unicode编码与wchar
// 特殊字符⭕●等
// wchar.h   local.h
// ASCII码
// GBK
// Unicode
// utf-8, utf-16, utf-32
// locale.h本地化函数
// 1.234,56
// 1,234.56
// ￥ ＄ € ￡
// 年/月/日 00：00 24h 12h
// MM/DD/YYYY	DD/MM/YYYY
#pragma execution_character_set("utf-8")

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>

#define board_size 15

int main(void) {
	// 设置控制台页为UTF-8
	SetConsoleOutputCP(65001);

	// 设置区域为当前系统默认
	setlocale(LC_ALL, "");

	wchar_t board[board_size][board_size];
	uint8_t x, y;

	// 状态
	wchar_t current_player = 0x25CF;

	for (uint32_t i = 0; i < board_size; i++) {
		for (uint32_t j = 0; j < board_size; j++) {
			board[i][j] = 0x00B7;
		}
	}

	for (uint32_t i = 0; i < board_size; i++) {
		for (uint32_t j = 0; j < board_size; j++) {
			wprintf(L"%lc", board[i][j]);
		}
		wprintf(L"\n");
	}

	wchar_t control = L'y';

	return 0;
}