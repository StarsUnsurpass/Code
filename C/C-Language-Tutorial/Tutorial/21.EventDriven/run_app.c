// 事件驱动，注册器，触发器
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "types.h"

// 事件系统
// 监听器
// 触发器

int main(void) {
	/*
		游戏概念：

		玩家属性 exp, level

		解谜

		等级提升

		游戏的目标
	*/

	Player player = { 0, 1 };	// 初始经验为0，等级为1

	// 添加事件监听器
	addLevelUpListener(levelUpAnnouncer);
	addLevelUpListener(treasureHintProvider);
	addLevelUpListener(unlockNewAbility);
	addLevelUpListener(unlockMap);

	// 模拟游戏过程中获得经验
	increase_exp(&player, 50);
	increase_exp(&player, 75);
	increase_exp(&player, 200);
	increase_exp(&player, 125);

	printf("最终等级：%s, 剩余经验：%d\n", levelAtc[player.level], player.exp);

	return EXIT_SUCCESS;
}
