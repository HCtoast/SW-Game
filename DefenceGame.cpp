#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define GBOARD_ORIGIN_X 8
#define GBOARD_ORIGIN_Y 4
#define GBOARD_WIDTH 100
#define GBOARD_LINE 5
int GOLD = 500;
int STAGE = 1;

void setCurrentCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printInfo() {
	setCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y - 2);
	printf("Gold : %d \t\t Stage : %d", GOLD, STAGE);
}

void drawGameBoard() {
	for (int j = 0; j <= 5; j++) {
		if (j == 0) {
			for (int i = 0; i <= GBOARD_WIDTH / 2; i++) {
				setCurrentCursorPos(GBOARD_ORIGIN_X + (i * 2), GBOARD_ORIGIN_Y);
				if (i == 0) {
					printf("┌");
				}
				else if (i == GBOARD_WIDTH / 2) {
					printf("┐");
				}
				else {
					printf("─");
				}
			}
			for (int i = 1; i < GBOARD_LINE; i++) {
				setCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + i);
				printf("│");
				setCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, GBOARD_ORIGIN_Y + i);
				printf("│");
			}
		}
		else if (j == 5) {
			for (int i = 0; i <= GBOARD_WIDTH / 2; i++) {
				setCurrentCursorPos(GBOARD_ORIGIN_X + (i * 2), GBOARD_ORIGIN_Y + j * GBOARD_LINE);
				if (i == 0) {
					printf("└");
				}
				else if (i == GBOARD_WIDTH / 2) {
					printf("┘");
				}
				else {
					printf("─");
				}
			}
		}
		else {
			for (int i = 0; i <= GBOARD_WIDTH / 2; i++) {
				setCurrentCursorPos(GBOARD_ORIGIN_X + (i * 2), GBOARD_ORIGIN_Y + j * GBOARD_LINE);
				if (i == 0) {
					printf("├");
				}
				else if (i == GBOARD_WIDTH / 2) {
					printf("┤");
				}
				else {
					printf("─");
				}
			}
			for (int i = 1; i < GBOARD_LINE; i++) {
				setCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + j * GBOARD_LINE + i);
				printf("│");
				setCurrentCursorPos(GBOARD_ORIGIN_X + GBOARD_WIDTH, GBOARD_ORIGIN_Y + j * GBOARD_LINE + i);
				printf("│");
			}
		}
	}
}

void main() {
	system("mode con cols=160 lines=40");
	printInfo();
	drawGameBoard();
}
