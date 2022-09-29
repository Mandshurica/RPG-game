/*
* -Author : Hojun Na
* -Date : 2022-09-29
* -Description : Basic RPG game
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int player_hp = 100;
	int player_atk = 10;
	int player_def = 8;

	int monster_hp = 80;
	int monster_atk = 10;
	int monster_def = 8;

	srand(time(NULL));

	while (1) {
		printf("Player status=========\n");
		printf("- HP: %d\n", player_hp);
		printf("- ATK: %d\n", player_atk);
		printf("- DEF: %d\n", player_def);
		printf("======================\n");
		printf("Monster status========\n");
		printf("- HP: %d\n", monster_hp);
		printf("- ATK: %d\n", monster_atk);
		printf("- DEF: %d\n", monster_def);
		printf("======================\n");

		printf("Menu==================\n");
		printf("1. Attack.\n");
		printf("2. Defense.\n");
		printf("3. Run.\n");
		printf("======================\n");

		int choice;
		scanf("%d", &choice);

		if (choice == 1) {
			int damage = player_atk - monster_def;
			int is_critical = rand() % 2;
			
			if (is_critical) damage *= 2;
			
			printf("You hit the monster with damage %d.\n", damage);
			monster_hp -= damage;

		}
		else if (choice == 2) {
			int damage = monster_atk - player_def;
			int is_critical = rand() % 2;

			if (is_critical) damage *= 2;

			printf("You got damage %d from the monster.\n", damage);
			player_hp -= damage;
		}
		else if (choice == 3) {
			printf("GAME OVER.\n");
			break;/*가장 가까운 루프를 탈출함.*/
		}
		else {
			printf("Wrong input.\n");
			continue;/*가장 가까운 루프의 처음으로 돌아감.*/
		}

		if (player_hp <= 0) {
			printf("GAME OVER.\n");
			break;
		}
		else if (monster_hp <= 0) {
			printf("You WIN.\n");
			break;
		}
	}

	return 0;
}