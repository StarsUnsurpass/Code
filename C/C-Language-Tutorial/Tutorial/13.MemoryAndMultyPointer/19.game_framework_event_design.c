// 游戏架构事件设计：事件类型、事件处理函数、事件注册、事件分发机制
// 键盘或鼠标控制游戏人物移动时不是if-else或switch，而是函数回调
// 1.定义事件类型和事件处理函数签名：首先我们定义游戏中可能发生的事件类型，以及处理这些函数的签名
// 2.实现事件注册和分发机制：实现一个机制，允许为不同类型的事件注册处理函数，并在相应的事件发生时调用这些函数
// 3.定义事件处理函数：现在我们为游戏中的每一个事件类型定义具体的事件处理函数
// 4.在游戏中使用事件处理系统：main中注册事件处理函数，并模拟事件的发生来演示系统的工作流程

// 企业中可能是数据处理的机制
// 客户端代码生成特定的事件处理函数
// 数据是否已到达，是否已处理完成，是否泄露
// 到达、处理完成、泄露各发生什么事件
// 都是函数指针和回调的应用

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	PLAYER_ATTACK,
	PLAYER_MOVE,

	EVENT_COUNT	// 记录事件的总数
} GameEventType;

typedef void(*EventHandler)(const char* playerName);

EventHandler eventHandlers[EVENT_COUNT]; // 事件处理函数的数组
// 声明了一个数组，这个数组的每一个元素都是EventHandler类型的函数指针，意味着每个数组元素都可以存储一个指向函数的指针
// 这个函数复合EventHandler的签名，它接受一个const char*的参数类型并返回void

// 注册事件处理函数
void registerEventHandler(GameEventType eventType, EventHandler handler);

// 分发函数
void dispatchEvent(GameEventType eventType, const char* playerName);

void handlePlayerAttack(const char* playerName);

void handlePlayerMove(const char* playerName);

int main19(void) {
	// 注册事件处理函数
	registerEventHandler(PLAYER_ATTACK, handlePlayerAttack);
	registerEventHandler(PLAYER_MOVE, handlePlayerMove);

	// ......
	// 加入中间有各种处理
	// 突然！事件发生了
	// 正常传入的应该是结构体
	dispatchEvent(PLAYER_ATTACK, "Hero");
	dispatchEvent(PLAYER_MOVE, "Hero");

	return EXIT_SUCCESS;
}

void registerEventHandler(GameEventType eventType, EventHandler handler) {
	if (eventType >= 0 && eventType < EVENT_COUNT) { // 枚举类型数量，防止越界报错
		eventHandlers[eventType] = (EventHandler)handler; // 不明确转换会有警告，暂不清楚原因

		// TODO...
	}
	else {
		// 可以在这里处理无效的eventType，比如打印
		// TODO...
		fprintf(stderr, "Invalid eventType: %d\n", eventType);
	}
}

void dispatchEvent(GameEventType eventType, const char* playerName) {
	if (eventHandlers[eventType] != NULL) {
		eventHandlers[eventType](playerName);
	}
}

void handlePlayerAttack(const char* playerName) {
	printf("%s attacks!\n", playerName);
}

void handlePlayerMove(const char* playerName) {
	printf("%s moves!\n", playerName);
}