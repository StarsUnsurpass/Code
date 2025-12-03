#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

#define EXP_PER_LEVEL 100	// 每个等级所需要的经验值
#define MAX_LEVEL 10		// 最高等级假设是10
#define HINTS_COUNT 10		// 宝藏提示的数量

void increase_exp(int32_t* exp, int32_t amount);
bool check_level_up(int32_t* player_exp, int32_t* player_level);
const char* get_treasure_hint(int32_t level);

int main02(void) {
	/*
		游戏概念：

		玩家属性 exp, level

		解谜

		等级提升

		游戏的目标
	*/

	int32_t player_exp = 0;

	int32_t player_level = 1;

	// 模拟玩家解谜获得的经验值
	increase_exp(&player_exp, 50);
	increase_exp(&player_exp, 75);

	if (check_level_up(&player_exp, &player_level)) {
		printf("%s\n", get_treasure_hint(player_level));
	}
	else {
		printf("you need more exp to level up\n");
	}

	return 0;
}

void increase_exp(int32_t* exp, int32_t amount) {
	*exp += amount;
}

bool check_level_up(int32_t* player_exp, int32_t* player_level) {
	while (*player_exp > EXP_PER_LEVEL && *player_level < MAX_LEVEL) {
		*player_exp -= EXP_PER_LEVEL;
		(*player_level)++;
		printf("Congratulations to level%" PRIu32 "\n", *player_level);
		return true;
	}

	return false;
}

const char* get_treasure_hint(int32_t level) {
	static const char* hints[HINTS_COUNT] = {
		"tip one: the hint is behind the waterfall, please back to home",
		"tip two: found the lost sword",
		"tip three"
	};

	if (level > 0 && (size_t)level <= HINTS_COUNT) {
		return hints[(size_t)level - 1];
	}

	return "unknown tips";
}