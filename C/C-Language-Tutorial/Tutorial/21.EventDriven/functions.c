#include "types.h"
#include "functions.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

EventSystem eventSystem = { 0 };

const char* levelAtc[MAX_LEVEL] = {
	"白玉", "萌黄", "火磷", "翡翠", "泓蓝",
	"紫罗", "赤金", "乌金", "穹窿", "穹窿之上"
};

// 用于注册新的监听器
void addLevelUpListener(LevelUpListener listener) {
	if (eventSystem.listenerCount < MAX_LISTENERS) {
		eventSystem.listeners[eventSystem.listenerCount++] = listener;
	}
}


// 函数用于在玩家升级时触发所有注册的监听器
void triggerLevelUpEvent(Player* player) {
	for (size_t i = 0; i < eventSystem.listenerCount; i++) {
		// 调用函数
		// treasureHintProvider(Player)
		// levelUpAnnouncer(Player)
		eventSystem.listeners[i](player);
	}
}


// 经验升级
void increase_exp(Player* player, i32 amount) {
	player->exp += amount;
	printf("获得 %d 点经验，当前经验值是：%d\n", amount, player->exp);

	while (player->exp >= EXP_PER_LEVEL && player->level <= MAX_LEVEL) {
		player->exp -= EXP_PER_LEVEL;
		player->level++;
		triggerLevelUpEvent(player);
	}
}


// 升级监听器
void levelUpAnnouncer(Player* player) {
	printf("恭喜升级到了 %s 级！\n", levelAtc[player->level - 1]);
}


// 升级一次宝藏提示
void treasureHintProvider(Player* player) {
	// 实际在配置文件中读取
	static const char* hints[MAX_LEVEL] = {
		"提示1：宝藏在古老的瀑布后面",
		"提示2：寻找被遗失的失落之剑",
		"提示3：探索神秘的地下洞穴",
		"提示4：解开远古神庙的谜题",
		"提示5：寻找沙漠中的绿洲",
		"提示6：攀登雪山寻找隐藏的山洞",
		"提示7：深入海底探索沉船",
		"提示8：穿越时空裂缝",
		"提示9：收集七颗龙珠",
		"提示10：挑战最终BOSS"
	};

	if (player->level > 0 && player->level <= MAX_LEVEL) {
		printf("%s\n", hints[player->level - 1]);
	}
}


// 解锁新技能
void unlockNewAbility(Player* player) {
	printf("解锁了新能力：");

	switch (player->level) {
	case 3: printf("二段跳！\n"); break;
	case 5: printf("水下呼吸！\n"); break;
	case 7: printf("隐身五秒！\n"); break;
	case 9: printf("解锁法宝！\n"); break;
	default: printf("没有新能力！\n"); break;
	}
}


// 解锁新地图
void unlockMap(Player* player) {
	printf("解锁了新地图：\n");

	switch (player->level) {
	case 2: printf("========欢迎来到乌木森林！========\n"); break;
	case 4: printf("========欢迎来到七星宫殿！========\n"); break;
	case 6: printf("========欢迎来到魅影溶洞！========\n"); break;
	case 8: printf("========欢迎来到浮空岛！========\n"); break;
	case 10: printf("========欢迎来到失落之城！========\n"); break;
	default: printf("没有开创新地图，请继续你的冒险！\n"); break;
	}

	printf("\n");
}