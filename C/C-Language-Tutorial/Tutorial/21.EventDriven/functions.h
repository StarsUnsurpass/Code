#pragma once
#include "types.h"

// 用于注册新的监听器
void addLevelUpListener(LevelUpListener listener);

// 函数用于在玩家升级时触发所有注册的监听器
void triggerLevelUpEvent(Player* player);

void increase_exp(Player* player, i32 amount);

// 升级监听器
void levelUpAnnouncer(Player* player);

// 升级一次宝藏提示
void treasureHintProvider(Player* player);

void unlockNewAbility(Player* player);

void unlockMap(Player* player);