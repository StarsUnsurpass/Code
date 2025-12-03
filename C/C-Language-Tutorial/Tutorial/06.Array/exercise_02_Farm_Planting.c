#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROWS 10		// 农场的行
#define COLS 10		// 农场的列
#define EMPTY 0		// 空地
#define PLANTED 1	// 已经种植（尚未成熟）
#define MATURED 2	// 成熟的作物
#define STONE 3		// 石头

void print_farm(int farm[][COLS]);

int main(void) {
	int farm[ROWS][COLS] = { [3][3] = STONE, [6][6] = STONE };
	srand((unsigned int)time(NULL));

	for (size_t i = 0; i < ROWS; i++) {
		for (size_t j = 0; j < COLS; j++) {
			farm[i][j] = (rand() % 2 == 0) ? EMPTY : PLANTED;
		}
	}

	farm[3][3] = STONE;
	farm[6][6] = STONE;

	print_farm(farm);
	Sleep(1000);

	// 模拟成熟的过程，更新农场地图，模拟作物成长
	for (size_t time = 0; time < 5; time++) {
		system("cls");

		for (size_t i = 0; i < ROWS; i++) {
			for (size_t j = 0; j < COLS; j++) {
				if (farm[i][j] == PLANTED) {
					if (rand() % 10 < 3) {
						// 假设每个时段有30%的概率作物会成熟
						farm[i][j] = MATURED;
					}
				}
			}
		}

		print_farm(farm);
		Sleep(1000);
	}

	return 0;
}

void print_farm(int farm[][COLS]) {
	for (size_t i = 0; i < ROWS; i++) {
		for (size_t j = 0; j < COLS; j++) {
			switch (farm[i][j]) {
			case EMPTY: printf(". "); break;	// 空地
			case PLANTED: printf("* "); break;	// 已种植
			case MATURED: printf("# "); break;	// 已成熟
			case STONE: printf("! "); break;
			}
		}

		printf("\n");
	}
}