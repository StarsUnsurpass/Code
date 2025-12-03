// 游戏案例：游戏服务器动态玩家列表管理之realloc与多级指针的应用
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char name[30];
} Player;

void updatePlayerList1(Player** players, int* currentSize, int newSize, Player newPlayer);

void printPlayers1(Player* players, int size);

int main09(void) {
	Player* players = NULL; // 玩家列表初始化为空
	int currentSize = 0; // 当前玩家数量

	// 初始化了三个结构体，模拟玩家进入
	Player newPlayer1 = { 1, "PlayerOne" };
	updatePlayerList1(&players, &currentSize, currentSize + 1, newPlayer1);

	Player newPlayer2 = { 2, "PlayerTwo" };
	updatePlayerList1(&players, &currentSize, currentSize + 1, newPlayer2);

	Player newPlayer3 = { 3, "PlayerThree" };
	updatePlayerList1(&players, &currentSize, currentSize + 1, newPlayer3);

	printPlayers1(players, currentSize);

	return EXIT_SUCCESS;
}

void updatePlayerList1(Player** players, int* currentSize, int newSize, Player newPlayer) {
	Player* temp = realloc(*players, newSize * sizeof(Player));
	// realloc(NULL, size) 等价于 malloc(size)；realloc(ptr, 0) 等价于 free(ptr)

	if (temp != NULL) {
		*players = temp;
		// 如果是扩容，则添加新玩家到列表
		if (newSize > *currentSize) {
			(*players)[*currentSize] = newPlayer; // 添加新玩家
		}
		*currentSize = newSize; // 更新当前大小
	}
	else {
		printf("Error rellocing memory!\n");
	}
}

void printPlayers1(Player* players, int size) {
	printf("Current Players:\n");
	for (size_t i = 0; i < size; i++) {
		printf("ID: %d, Name: %s\n", players[i].id, players[i].name);
	}
}