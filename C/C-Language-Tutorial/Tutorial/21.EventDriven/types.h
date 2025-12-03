#pragma once
#include <stdint.h>

#define EXP_PER_LEVEL 100	// 每个等级所需要的经验值
#define MAX_LEVEL 10		// 最高等级假设是10
#define HINTS_COUNT 10		// 宝藏提示的数量
#define MAX_LISTENERS 10	// 最大监听器数量

typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef struct {
	i32 exp;
	i32 level;
} Player;

extern const char* levelAtc[MAX_LEVEL];

typedef void(*LevelUpListener)(Player*);

typedef struct {
	LevelUpListener listeners[MAX_LISTENERS];
	int listenerCount;
} EventSystem;

extern EventSystem eventSystem;
