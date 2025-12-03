#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

void update_score(int32_t* score, int32_t points);

int32_t* compare_score(int32_t* score1, int32_t* score2);

void double_score(int32_t* score);

int main03(void) {
	int32_t player1_score = 100;

	int32_t player2_score = 150;

	update_score(&player1_score, 50);
	update_score(&player2_score, 75);

	int32_t* higher_score = compare_score(&player1_score, &player2_score);

	printf("The higher score is %" PRIu32 ".\n", *higher_score);

	double_score(&player2_score);

	return 0;
}

void update_score(int32_t* score, int32_t points) {
	*score += points;
	printf("The score is %" PRIu32 " now.\n", *score);
}

int32_t* compare_score(int32_t* score1, int32_t* score2) {
	return (*score1 > *score2) ? score1 : score2;
}

void double_score(int32_t* score) {
	*score *= 2;
	printf("Doubled score is %" PRIu32 ".\n", *score);
}