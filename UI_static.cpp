// UI_static.c
#define _CRT_SECURE_NO_WARNINGS
#include "UI_static.h"
#include "UI_cleaner.h"
#include "utils.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

UIStatic uiStatic;

UIStatic::UIStatic()
{
	// 생성자 내용
}


void UIStatic::UI_static_main_box(int color)
{
	for (int y = 1; y < HEIGHT; y++) {
		utils.utils_set_color(color);
		utils.utils_gotoxy(0, y);        printf("|");
		utils.utils_gotoxy(WIDTH, y);    printf("|");
	}

	for (int x = 0; x <= WIDTH; x++) {
		utils.utils_set_color(color);
		utils.utils_gotoxy(x, 0);        printf("=");
		utils.utils_gotoxy(x, HEIGHT - 1);   printf("=");
	}
	utils.utils_set_color(COLOR_DEFAULT_TEXT);
}

void UIStatic::UI_static_title(void)
{
	const char* title_art[] = {
		" _____  _____ ______  _____ ______  _____   _____  _   _ ______  _   _  _____  _   _   ___   _     ",
		"/  ___|/  __ \\| ___ \\|_   _|| ___ \\|_   _| /  ___|| | | || ___ \\| | | ||_   _|| | | | / _ \\ | |    ",
		"\\ `--. | /  \\/| |_/ /  | |  | |_/ /  | |   \\ `--. | | | || |_/ /| | | |  | |  | | | |/ /_\\ \\| |    ",
		" `--. \\| |    |    /   | |  |  __/   | |    `--. \\| | | ||    / | | | |  | |  | | | ||  _  || |    ",
		"/\\__/ /| \\__/\\| |\\ \\  _| |_ | |      | |   /\\__/ /| |_| || |\\ \\ \\ \\_/ / _| |_ \\ \\_/ /| | | || |____",
		"\\____/  \\____/\\_| \\_| \\___/ \\_|      \\_/   \\____/  \\___/ \\_| \\_| \\___/  \\___/  \\___/ \\_| |_/\\_____/"
	};

	const int art_lines = sizeof(title_art) / sizeof(title_art[0]);
	const int start_y = 2;

	utils.utils_set_color(COLOR_TITLE);
	for (int i = 0; i < art_lines; i++) {
		int len = (int)strlen(title_art[i]);
		int tx = (WIDTH - len) / 2;
		utils.utils_gotoxy(tx, start_y + i);
		printf("%s", title_art[i]);
	}
}

void UIStatic::UI_static_hide_title(void)
{
	const char* title_art[] = {
		" _____  _             _____  _                     _                  ______                                   ",
		"|_   _|| |           /  ___|| |                   | |                 |  _  \\                                  ",
		"  | |  | |__    ___  \\ `--. | |  ___   ___  _ __  | |  ___  ___  ___  | | | | _ __   __ _   __ _   ___   _ __  ",
		"  | |  | '_ \\  / _ \\  `--. \\| | / _ \\ / _ \\| '_ \\ | | / _ \\/ __|/ __| | | | || '__| / _` | / _` | / _ \\ | '_ \\ ",
		"  | |  | | | ||  __/ /\\__/ /| ||  __/|  __/| |_) || ||  __/\\__ \\\\__ \\ | |/ / | |   | (_| || (_| || (_) || | | |",
		"  \\_/  |_| |_| \\___| \\____/ |_| \\___| \\___|| .__/ |_| \\___||___/|___/ |___/  |_|    \\__,_| \\__, | \\___/ |_| |_|",
		"                                           | |                                              __/ |              ",
		"                                           |_|                                             |___/               "
	};

	const int art_lines = sizeof(title_art) / sizeof(title_art[0]);
	const int start_y = 2;

	utils.utils_set_color(COLOR_TITLE);
	for (int i = 0; i < art_lines; i++) {
		int len = (int)strlen(title_art[i]);
		int tx = (WIDTH - len) / 2;
		utils.utils_gotoxy(tx, start_y + i);
		printf("%s", title_art[i]);
	}
}

void UIStatic::UI_static_setting_menu(void) {
	system("cls");
	UI_static_main_box(COLOR_WHITE);
	utils.utils_gotoxy(70, 8);  printf("설정 메뉴");
	utils.utils_gotoxy(69, 10);  printf("사운드 켜기");
	utils.utils_gotoxy(69, 12);  printf("사운드 끄기");
	utils.utils_gotoxy(69, 14); printf("사운드 조절       %%");
	utils.utils_gotoxy(69, 16); printf("뒤로가기");
}

void UIStatic::UI_static_select_game_mode(void)
{
	system("cls");
	UI_static_main_box(COLOR_WHITE);

	utils.utils_gotoxy(65, 10);
	printf("게임 모드를 선택하세요");
	utils.utils_gotoxy(70, 13);
	printf("일반 모드");
	utils.utils_gotoxy(70, 15);
	printf("무한 모드");
}

void UIStatic::UI_static_hero_select_box(void)
{
	UI_cleaner_all_display();
	UI_static_main_box(COLOR_WHITE);

	const char* title = "=== 영웅을 선택하세요 ===";
	utils.utils_gotoxy((WIDTH - (int)strlen(title)) / 2, 4);
	utils.utils_set_color(COLOR_TITLE);
	printf("%s", title);
	utils.utils_set_color(COLOR_DEFAULT_TEXT);

	// 3개의 선택지를 위한 박스 틀 그리기
	int box_width = 38;
	int box_height = 15;
	int start_y = 8;
	int padding = (WIDTH - (box_width * 3)) / 4;

	for (int i = 0; i < 3; i++) {
		int start_x = padding + (i * (box_width + padding));
		for (int y = 0; y < box_height; y++) {
			utils.utils_gotoxy(start_x, start_y + y);
			putchar('|');
			utils.utils_gotoxy(start_x + box_width - 1, start_y + y);
			putchar('|');
		}
		for (int x = 0; x < box_width; x++) {
			utils.utils_gotoxy(start_x + x, start_y);
			putchar('=');
			utils.utils_gotoxy(start_x + x, start_y + box_height - 1);
			putchar('=');
		}
	}
}

void UIStatic::UI_static_save_load_box(void)
{
	UI_static_main_box(COLOR_WHITE);

	const char* title = "=== 저장하기 ===";
	utils.utils_gotoxy((WIDTH - (int)strlen(title)) / 2, 4);
	utils.utils_set_color(COLOR_TITLE);
	printf("%s", title);
	utils.utils_set_color(COLOR_DEFAULT_TEXT);

	// 3개의 선택지를 위한 박스 틀 그리기
	int box_width = 38;
	int box_height = 15;
	int start_y = 8;
	int padding = (WIDTH - (box_width * 3)) / 4;

	for (int i = 0; i < 3; i++) {
		int start_x = padding + (i * (box_width + padding));
		for (int y = 0; y < box_height; y++) {
			utils.utils_gotoxy(start_x, start_y + y);
			putchar('|');
			utils.utils_gotoxy(start_x + box_width - 1, start_y + y);
			putchar('|');
		}
		for (int x = 0; x < box_width; x++) {
			utils.utils_gotoxy(start_x + x, start_y);
			putchar('=');
			utils.utils_gotoxy(start_x + x, start_y + box_height - 1);
			putchar('=');
		}
	}
}

void UIStatic::UI_static_infinite_upgrade_box(void)
{
	UI_static_main_box(COLOR_WHITE);

	const char* title = "=== 능력 강화 ===";
	utils.utils_gotoxy((WIDTH - (int)strlen(title)) / 2, 3);
	utils.utils_set_color(COLOR_TITLE);
	printf("%s", title);

	utils.utils_gotoxy((WIDTH - (int)strlen("강화할 능력을 선택하세요 (좌/우 화살표로 선택, Enter로 확정)")) / 2, 5);
	utils.utils_set_color(COLOR_DEFAULT_TEXT);
	printf("강화할 능력을 선택하세요 (좌/우 화살표로 선택, Enter로 확정)");

	// 3개의 선택지를 위한 박스 틀 그리기 (영웅 선택과 동일한 스타일)
	int box_width = 38;
	int box_height = 15;
	int start_y = 8;
	int padding = (WIDTH - (box_width * 3)) / 4;

	for (int i = 0; i < 3; i++) {
		int start_x = padding + (i * (box_width + padding));
		for (int y = 0; y < box_height; y++) {
			utils.utils_gotoxy(start_x, start_y + y); putchar('|');
			utils.utils_gotoxy(start_x + box_width - 1, start_y + y); putchar('|');
		}
		for (int x = 0; x < box_width; x++) {
			utils.utils_gotoxy(start_x + x, start_y); putchar('=');
			utils.utils_gotoxy(start_x + x, start_y + box_height - 1); putchar('=');
		}
	}
	utils.utils_set_color(COLOR_DEFAULT_TEXT);
}

void UIStatic::UI_static_battle_box(void)
{
	for (int x = 1; x < WIDTH - 1; x++) {
		utils.utils_gotoxy(x, 18); putchar('=');
		utils.utils_gotoxy(x, 20); putchar('=');
	}

	for (int y = 19; y < 27; y++) {
		if (y == 20) continue; // 20행은 비워둠
		utils.utils_gotoxy(37, y); printf("|");
		utils.utils_gotoxy(111, y); printf("|");
	}

	utils.utils_gotoxy(14, 19); printf("플레이어 행동");
	utils.utils_gotoxy(124, 19); printf("플레이어 스텟");
}

void UIStatic::UI_static_select_heal_or_store_box(void)
{
	UI_static_main_box(COLOR_WHITE);

	const char* title = "=== 선택하세요. ===";
	utils.utils_gotoxy((WIDTH - (int)strlen(title)) / 2, 4);
	utils.utils_set_color(COLOR_TITLE);
	printf("%s", title);
	utils.utils_set_color(COLOR_DEFAULT_TEXT);

	// 3개의 선택지를 위한 박스 틀 그리기
	int box_width = 38;
	int box_height = 15;
	int start_y = 8;
	int padding = (WIDTH - (box_width * 3)) / 4;

	for (int i = 0; i < 3; i++) {
		int start_x = padding + (i * (box_width + padding));
		for (int y = 0; y < box_height; y++) {
			utils.utils_gotoxy(start_x, start_y + y);
			putchar('|');
			utils.utils_gotoxy(start_x + box_width - 1, start_y + y);
			putchar('|');
		}
		for (int x = 0; x < box_width; x++) {
			utils.utils_gotoxy(start_x + x, start_y);
			putchar('=');
			utils.utils_gotoxy(start_x + x, start_y + box_height - 1);
			putchar('=');
		}
	}
}

void UIStatic::UI_static_inventory_box(void)
{
	for (int i = 1; i < WIDTH - 1; i++) {
		utils.utils_gotoxy(i, 4); putchar('=');
	}

	for (int y = 1; y < 4; y++) {
		utils.utils_gotoxy(9, y); putchar('|');
		utils.utils_gotoxy(53, y); putchar('|');
		utils.utils_gotoxy(97, y); putchar('|');
		utils.utils_gotoxy(141, y); putchar('|');
	}

	for (int i = 1; i < WIDTH - 1; i++) {
		utils.utils_gotoxy(i, 18); putchar('=');
		utils.utils_gotoxy(i, 20); putchar('=');
	}

	for (int y = 5; y < 27; y++) {
		if (y == 18 || y == 20) continue;
		utils.utils_gotoxy(75, y); putchar('|');
	}

	for (int y = 19; y < 27; y++) {
		if (y == 20) continue;
		utils.utils_gotoxy(37, y); putchar('|');
		utils.utils_gotoxy(111, y); putchar('|');
	}

	utils.utils_gotoxy(12, 19); printf("착용 중인 무기");
	utils.utils_gotoxy(49, 19); printf("착용 중인 방어구");
	utils.utils_gotoxy(85, 19); printf("착용시 능력치 변화");
	utils.utils_gotoxy(123, 19); printf(" 플레이어 스텟");
}

void UIStatic::UI_static_shop_box(void)
{
	for (int i = 1; i < WIDTH - 1; i++) {
		utils.utils_gotoxy(i, 4); putchar('=');
	}

	for (int y = 1; y < 4; y++) {
		utils.utils_gotoxy(9, y); putchar('|');
		utils.utils_gotoxy(56, y); putchar('|');
		utils.utils_gotoxy(103, y); putchar('|');
	}

	for (int i = 1; i < WIDTH - 1; i++) {
		utils.utils_gotoxy(i, 18); putchar('=');
		utils.utils_gotoxy(i, 20); putchar('=');
	}

	for (int y = 5; y < 27; y++) {
		if (y == 18 || y == 20) continue;
		utils.utils_gotoxy(75, y); putchar('|');
	}

	for (int y = 19; y < 27; y++) {
		if (y == 20) continue;
		utils.utils_gotoxy(37, y); putchar('|');
		utils.utils_gotoxy(111, y); putchar('|');
	}

	utils.utils_gotoxy(18, 19); printf("구매");
	utils.utils_gotoxy(55, 19); printf("판매");
	utils.utils_gotoxy(85, 19); printf("착용시 능력치 변화");
	utils.utils_gotoxy(128, 19); printf("코인");
}