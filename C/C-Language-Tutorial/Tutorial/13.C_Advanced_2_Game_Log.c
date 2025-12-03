#include <stdio.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TIME_STRING_SIZE 26

typedef struct {
	int id;
	char name[30];
} Player;

void updatePlayerList(Player** players, int* currentSize, int newSize, Player newPlayer);

void printPlayers(Player* players, int size);

//企业开发中调用更复杂的日志系统：Log4c、Syslog、spdlog(C++)等
void logError(const char* message);
void logInfo(const char* message);
void logMessage(const char* level, const char* message);

int main8(void) {
	//游戏案例：游戏服务器动态玩家列表管理之realloc与多级指针的应用
	//卫语句与log编写
	Player* players = NULL; // 玩家列表初始化为空
	int currentSize = 0; // 当前玩家数量

	// 初始化三个结构体，模拟玩家进入
	Player newPlayer1 = { 1, "PlayerOne" };
	updatePlayerList(&players, &currentSize, currentSize + 1, newPlayer1);

	Player newPlayer2 = { 2, "PlayerTwo" };
	updatePlayerList(&players, &currentSize, currentSize + 1, newPlayer2);

	Player newPlayer3 = { 3, "PlayerThree" };
	updatePlayerList(&players, &currentSize, currentSize + 1, newPlayer3);

	printPlayers(players, currentSize);

	return EXIT_SUCCESS;
}

//如果函数不写返回值，Warining C4033 隐式声明返回一个int
void updatePlayerList(Player** players, int* currentSize, int newSize, Player newPlayer) {
	// 防止减小数组大小时丢失数据
	if (newSize < *currentSize) {
		logError("Error: newSize is smaller than currentSize.");
		return;
	}

	// 当增加玩家时，确保newSize大小大于currentSize
	if (newSize == *currentSize) {
		logInfo("No resizing needed. The newSize must be greater than currentSize to add a new player.");
		return;
	}

	Player* temp = (Player*)realloc(*players, newSize * sizeof(Player));
	// 没有malloc，第一次传递NULL时初始化
	// realloc会自动释放原来内存块

	if (temp == NULL) {
		// 在重新分配失败时，保持原始列表不变，避免数据丢失
		logError("Error reallocating memory!\n");
		// 考虑添加日志记录或错误逻辑处理
	}
	else {
		*players = temp;
		// 如果有扩容，则添加新玩家到列表
		if (newSize > *currentSize) {
			(*players)[*currentSize] = newPlayer; // 添加新玩家
		}
		*currentSize = newSize; // 更新当前大小

		logInfo("Player added successfully.");
		char infoMessage[100];
		snprintf(infoMessage, sizeof(infoMessage), "Current player count: %d", *currentSize);
		logInfo(infoMessage);
	}
}

void printPlayers(Player* players, int size) {
	printf("Current Players:\n");
	for (size_t i = 0; i < size; i++) {
		printf("ID: %d, Name: %s\n", players[i].id, players[i].name);
	}
}

void logError(const char* message) {
	logMessage("Error", message);
	// 注意，在实际企业中，并非这两行代码这么简单，应该替换为更复杂的日志系统调用
}

void logInfo(const char* message) {
	logMessage("INFO", message);
	// 注意，在实际企业中，并非这两行代码这么简单，应该替换为INFO级别日志
}

void logMessage(const char* level, const char* message) {
	time_t now = time(NULL);
	char timeStr[TIME_STRING_SIZE];

	if (ctime_s(timeStr, sizeof(timeStr), &now) == 0) {
		timeStr[24] = '\0';
		fprintf(stderr, "[%s] %s %s\n", timeStr, level, message);
	}
	else {
		fprintf(stderr, "[ERROR] Failed to get current time\n");
	}
}