#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

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

}