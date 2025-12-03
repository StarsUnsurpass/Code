#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ACHIEVEMENTS 10

const char* achievements[MAX_ACHIEVEMENTS];
size_t achievements_count = 0;

// const¿É¶Á²»¿ÉÐ´
void add_achievement(const char* new_achievement);

void print_achievements();

int main(void) {

	add_achievement("Completed the first challenge trophy!");
	add_achievement("Found all the hidden treasure chests!");

	print_achievements();

	return 0;
}

void add_achievement(const char* new_achievement) {
	if (achievements_count < MAX_ACHIEVEMENTS) {
		achievements[achievements_count++] = new_achievement;
		printf("Added achievement: %s\n", new_achievement);
	}
	else {
		printf("The array of acievements is full, can't add ne achievement!\n");
	}
}

void print_achievements() {
	printf("Achievements list:\n");

	for (size_t i = 0; i < achievements_count; i++) {
		printf("Achievement%zu: %s\n", i + 1, achievements[i]);
	}
}