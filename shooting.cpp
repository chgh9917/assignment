#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main() {
	int mapSizeY = 20;
	int mapSizeX = 52;

	int KillCount = 0;
	int MonsterCount = 3;
	int FrameCount = 0;
	int BoomCount = 0;
	bool Boom = false;

	int BoomX = 0;
	int BoomY = 0;

	int PlayerX = 25;
	int PlayerY = 18;

	int MonsterX_1 = 10;
	int MonsterX_2 = 28;
	int MonsterX_3 = 42;

	int MonsterY_1 = 3;
	int MonsterY_2 = 5;
	int MonsterY_3 = 7;

	char ArrPixel[20][52];

	memset((void*)ArrPixel, '*', sizeof(char) * mapSizeY * mapSizeX);

	for (int y = 0; y < 20; y++) {
		ArrPixel[y][50] = '\n';
		ArrPixel[y][50] = 0;
	}
	ArrPixel[MonsterY_1][MonsterX_1] = 'M';
	ArrPixel[MonsterY_2][MonsterX_2] = 'M';
	ArrPixel[MonsterY_2][MonsterX_3] = 'M';

	while (true) {
		system("cls");
		ArrPixel[PlayerY][PlayerX] = '@';
		for (int y = 0; y < mapSizeY; y++) {
			printf_s(ArrPixel[y]);
		}
		cout << "--------------------------------- " << endl;
		cout << "MONSTER : %d KILL: %d " << MonsterCount << KillCount << endl;
		cout << "-----------------조작법---------------" << endl;
		cout << "이동 : W A S D" << endl;
		cout << "총알: K" << endl;
		cout << "폭탄: B" << endl;
		cout << "몬스터가 있는 곳으로는 이동할 수 없습니다." << endl;
		cout << "폭탄이 터지는 동안 재사용 할 수 없습니다." << endl;
		cout << "승리: 20kill" << endl;
		cout << "패배: 20Monsters" << endl;
		cout << "-----------------------------------------------" << endl;
	}
}