#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int rand_X() {
	int Rand_X = rand() % 49;
	return Rand_X;
}
int rand_Y() {
	int Rand_Y = rand() % 15;
	return Rand_Y;
}
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

		if (Boom == true) {
			BoomCount += 1;
		}
		if (BoomCount == 1) {
			if (ArrPixel[BoomY][BoomX - 1] == 'M'
				|| ArrPixel[BoomY][BoomX + 1] == 'M'
				|| ArrPixel[BoomY + 1][BoomX] == 'M'
				|| ArrPixel[BoomY - 1][BoomX] == 'M') {
				KillCount += 1;
				MonsterCount -= 1;
			}
			ArrPixel[BoomY][BoomX - 1] = 'B';
			ArrPixel[BoomY][BoomX + 1] = 'B';
			ArrPixel[BoomY + 1][BoomX] = 'B';
			ArrPixel[BoomY - 1][BoomX] = 'B';
		}
		else if (BoomCount == 2) {
				if (ArrPixel[BoomY][BoomX - 2] == 'M'
					|| ArrPixel[BoomY][BoomX + 2] == 'M'
					|| ArrPixel[BoomY + 2][BoomX] == 'M'
					|| ArrPixel[BoomY - 2][BoomX] == 'M') {
					KillCount += 1;
					MonsterCount -= 1;
				}
				ArrPixel[BoomY][BoomX - 2] = 'B';
				ArrPixel[BoomY][BoomX + 2] = 'B';
				ArrPixel[BoomY + 2][BoomX] = 'B';
				ArrPixel[BoomY - 2][BoomX] = 'B';
		}
		else if (BoomCount == 3) {
			if (ArrPixel[BoomY][BoomX - 3] == 'M'
				|| ArrPixel[BoomY][BoomX + 3] == 'M'
				|| ArrPixel[BoomY + 3][BoomX] == 'M'
				|| ArrPixel[BoomY - 3][BoomX] == 'M') {
				KillCount += 1;
				MonsterCount -= 1;
			}
			ArrPixel[BoomY][BoomX - 3] = 'B';
			ArrPixel[BoomY][BoomX + 3] = 'B';
			ArrPixel[BoomY + 3][BoomX] = 'B';
			ArrPixel[BoomY - 3][BoomX] = 'B';
		}
		else if (BoomCount == 4) {
			if (ArrPixel[BoomY][BoomX - 4] == 'M'
				|| ArrPixel[BoomY][BoomX + 4] == 'M'
				|| ArrPixel[BoomY + 4][BoomX] == 'M'
				|| ArrPixel[BoomY - 4][BoomX] == 'M') {
				KillCount += 1;
				MonsterCount -= 1;
			}
			ArrPixel[BoomY][BoomX - 4] = 'B';
			ArrPixel[BoomY][BoomX + 4] = 'B';
			ArrPixel[BoomY + 4][BoomX] = 'B';
			ArrPixel[BoomY - 4][BoomX] = 'B';
		}
		else if (BoomCount == 5) {
			for (int i = -4; i < 5; i++) {
				ArrPixel[BoomY + i][BoomX] = '*';
				ArrPixel[BoomY][BoomX+i] = '*';
			}
			Boom = false;
			BoomCount = 0;
		}

		if (KillCount == 20) {
			cout << "Win..." << endl;
			break;
		}
		if (MonsterCount == 20) {
			cout << "Game over!!" << endl;
			break;
		}

		for (int i = 0; i < mapSizeY; i++) {
			for (int j = 0; j < mapSizeX; j++) {
				if (ArrPixel[i][j] == '^') {
					ArrPixel[i][j] = '*';
					if (ArrPixel[i - 1][j] = 'M') {
						ArrPixel[i - 1][j] = '*';
						KillCount += 1;
						MonsterCount -= 1;
					}
					else {
						if (i - 1 > 0) {
							ArrPixel[i - 1][j] = '^';
						}
					}
				}
			}
		}
		switch (_getch())
		{
		case 'a':
		case 'A':
			if (PlayerX != 0 && ArrPixel[PlayerY][PlayerX - 1] != 'M') {
				ArrPixel[PlayerY][PlayerX] = '*';
				ArrPixel[PlayerY][PlayerX - 1] = '@';
				PlayerX -= 1;
			}
			break;
		case 'd':
		case 'D':
			if (PlayerX != (mapSizeX-3) && ArrPixel[PlayerY][PlayerX + 1] != 'M') {
				ArrPixel[PlayerY][PlayerX] = '*';
				ArrPixel[PlayerY][PlayerX + 1] = '@';
				PlayerX += 1;
			}
			break;
		case 'w':
		case 'W':
			if (PlayerX != 0 && ArrPixel[PlayerY-1][PlayerX] != 'M') {
				ArrPixel[PlayerY][PlayerX] = '*';
				ArrPixel[PlayerY-1][PlayerX] = '@';
				PlayerY -= 1;
			}
			break;
		case 's':
		case 'S':
			if (PlayerX != (mapSizeX - 1) && ArrPixel[PlayerY+1][PlayerX] != 'M') {
				ArrPixel[PlayerY][PlayerX] = '*';
				ArrPixel[PlayerY+1][PlayerX] = '@';
				PlayerY += 1;
			}
			break;
		case 'r':
		case 'R':
			break;
		case 'k':
		case'K':
			if (ArrPixel[PlayerY - 1][PlayerX] == 'M') {
				KillCount += 1;
				MonsterCount -= 1;
			}
			ArrPixel[PlayerY - 1][PlayerX] = '^';
			break;

		case'b':
		case'B':
			if (Boom == false
				&& PlayerY-3-4>-1
				&& PlayerY-3+4<20
				&& PlayerX-4>-1
				&& PlayerX+4<50) {
				if (ArrPixel[PlayerY - 3][PlayerX] == 'M') {
					KillCount += 1;
					MonsterCount -= 1;
				}
				Boom = true;
				ArrPixel[PlayerY - 3][PlayerX] = 'B';
				BoomY = PlayerY - 3;
				BoomX = PlayerX;
				break;
			}
		}
		FrameCount += 1;
		if (FrameCount % 10 == 0) {
			ArrPixel[rand_Y()][rand_X()] = 'M';
			MonsterCount += 1;
		}
	}
}