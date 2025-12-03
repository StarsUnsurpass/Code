// malloc与结构体的使用以及防止内存泄漏
#include <stdio.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

typedef struct Character {
	char* name;
	int level;
	int hp;
} Character;

Character* create_character(const char* name, int level, int hp);

void free_character(Character* character);

int main05(void) {
	Character* hero = create_character("Hero", 1, 100);

	if (hero == NULL) {
		return EXIT_FAILURE;
	}

	printf("Hero's name is %s, level is %d, hp is %d.\n", hero->name, hero->level, hero->hp);

	free_character(hero);

	return EXIT_SUCCESS;
}

Character* create_character(const char* name, int level, int hp) {
	Character* new_character = (Character*)malloc(sizeof(Character));

	if (new_character == NULL) {
		perror("Failed to cllocate memory for new character.");
		// 创建失败返回一个空指针
		return NULL;
	}

	new_character->name = (char*)malloc(strlen(name) + 1);

	if (new_character->name == NULL) {
		perror("Failed to allocate memory for new character name.");
		free(new_character); // 防止内存泄漏，给结构体分配内存，最近的退出点要释放内存动态内存的分配要跟踪管理
		return NULL;
	}

	strcpy_s(new_character->name, strlen(name) + 1, name);
	new_character->level = level;
	new_character->hp = hp;

	return new_character;
}

void free_character(Character* character) {
	if (character != NULL) {
		free(character->name); // 释放名字字符串占用的内存
		free(character);
	}
}