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
		cout << "-----------------���۹�---------------" << endl;
		cout << "�̵� : W A S D" << endl;
		cout << "�Ѿ�: K" << endl;
		cout << "��ź: B" << endl;
		cout << "���Ͱ� �ִ� �����δ� �̵��� �� �����ϴ�." << endl;
		cout << "��ź�� ������ ���� ���� �� �� �����ϴ�." << endl;
		cout << "�¸�: 20kill" << endl;
		cout << "�й�: 20Monsters" << endl;
		cout << "-----------------------------------------------" << endl;
	}
}