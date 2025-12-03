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

int main01(void) {
	// 设置控制台页为UTF-8
	SetConsoleOutputCP(65001);

	// 设置区域为当前系统默认
	setlocale(LC_ALL, "");

	wchar_t board[board_size][board_size];
	uint8_t x, y;

	// 状态
	wchar_t current_player = 0x25CF;

	// 初始化棋盘
	for (uint32_t i = 0; i < board_size; i++) {
		for (uint32_t j = 0; j < board_size; j++) {
			board[i][j] = 0x00B7; // ·
		}
	}

	

	wchar_t control = L'y';
	while (control == L'y' || control == L'Y') {
		system("cls"); // 清屏

		for (uint32_t i = 0; i < board_size; i++) {
			for (uint32_t j = 0; j < board_size; j++) {
				wprintf(L"%lc", board[i][j]);
			}
			wprintf(L"\n");
		}
		while (1) {

			wprintf(L"玩家 %lc 请输入坐标（0 - %d），中间用空格隔开：\n", current_player, board_size - 1);

			// 判断两个值是否没有读到
			if (scanf_s("%" SCNu8 " %" SCNu8, &x, &y) != 2) {
				while (getchar() != '\n');
				wprintf(L"输入无效，请重新输入。\n");
				continue;
			}

			if (x < board_size && y < board_size && board[x][y] == 0x00B7) {
				board[x][y] = current_player;
				current_player = (current_player == 0x25CF) ? 0x25CB : 0x25CF;
				break;
			}
			else {
				wprintf(L"无效的移动，请重试！\n");
				while (getchar() != '\n'); // 清空输入缓存
			}
		}

		system("cls");
		for (uint32_t i = 0; i < board_size; i++) {
			for (uint32_t j = 0; j < board_size; j++) {
				wprintf(L"%lc", board[i][j]);
			}
			wprintf(L"\n");
		}

		wprintf(L"是否继续？（y/n）:\n");
		while (getchar() != '\n'); // 清空输入缓存
		wscanf_s(L" %lc", &control, 1);
	}

	wprintf(L"游戏结束！\n");

	

	return 0;
}