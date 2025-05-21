#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>

#include "MyStrcspn.h"

#define MAXWIDTHSIZE 64
#define MAXHEIGHTSIZE 24
#define STRMAX 256

// ��������
char* g_MapInfo[MAXWIDTHSIZE];
//char g_MapInfo[5][MAXHEIGHTSIZE][MAXWIDTHSIZE]; // 3���� �迭�� ���� �������� ���� ����

// or ����ü ��������
typedef struct MapInfoData
{
	char MapCreatorName[256];
	int MapSizeW;
	int MapSizeH;
	int BoxCnt;
	// -> �ΰ����� ���
	char MapInfo[MAXHEIGHTSIZE][MAXWIDTHSIZE];
} MapInfoData;

MapInfoData gameMap[3]; // ����ü �迭

void main()
{
	// ���嵵 ���� ���� ������� �ؼ� �����ϱ�
	// �Լ�, ����, �ε� ó��
	// strcspn(tempstr, "\n") -> mystrcspn() ���� ���� �����
	// �����Ҵ� ó������
	// ����_C���_�̸�_�й�.zip
	// 12�� 30�� ~

	// MyStrcspn �ҷ�����
	// �� ������ ���� �ʱ�ȭ
	int mapW = 0;
	int mapH = 0;
	int boxCnt = 0;
	char** map = NULL;

	// ���� �о����
	FILE* fr = fopen("MapData.txt", "r");
	if (!fr)
	{
		printf("������ �о������ ���߽��ϴ�.\n");
		return;
	}

	char tempStr[STRMAX];
	fscanf(fr, "%s %d %d ", tempStr, &mapW, &mapH); // �� ũ��
	fscanf(fr, "%s %d ", tempStr, &boxCnt); // �ڽ� ����
	fgets(tempStr, mapW, fr); // �� ����(���ڸ�)

	// �����Ҵ� ó��
	map = (char**)malloc(sizeof(char*) * mapH);

	for (size_t i = 0; i < mapH; i++)
	{
		char tempStr2[STRMAX];
		fgets(tempStr2, mapW, fr);

		map[i] = (char*)malloc(strlen(tempStr2) + sizeof(char*) + 1); // + '\0'
		strcpy(map[i], tempStr2);
	}

	int pos = -1;
	for (size_t i = 0; i < mapH; i++)
	{
		pos = MyStrcspn(map[i], "\n"); // \n�� �ִ� ��ġ ã��(MyStrscpn ���)

		// \n�� ���� ��� �ǳʶٱ�
		if (pos == -1)
		{
			continue;
		}

		map[i][pos] = '\0';
	}

	for (size_t i = 0; i < mapH; i++)
	{
		// �� �ٿ� �ƹ��͵� ���� �� (\0�� ��) �ǳʶٱ�
		if (map[i][0] == '\0')
		{
			continue;
		}
		printf("%s\n", map[i]);
	}

	// �޸� ����
	for (size_t i = 0; i < mapH; i++)
	{
		free(map[i]);
	}
	free(map);
	fclose(fr);

	// �����Ҵ� ó��
	// ���� �о����
	//MapInfoData map;
	//map.MapSizeW = 0;
	//map.MapSizeH = 0;
	//map.BoxCnt = 0;
	//FILE* fr = fopen("MapData.txt", "r");
	//if (!fr)
	//{
	//	printf("������ �ҷ����� ���߽��ϴ�.\n");
	//	return;
	//}
	//int lineSize = getLineSize(fr); // �� �� �ҷ�����

	//fclose(fr);

	//MapInfoData mapInfo;
	//// ����ü �� �ʱ�ȭ
	//mapInfo.MapSizeW = 0;
	//mapInfo.MapSizeH = 0;
	//mapInfo.BoxCnt = 0;

	//for (size_t y = 0; y < MAXHEIGHTSIZE; y++)
	//{
	//	for(size_t x = 0; x < MAXWIDTHSIZE; x++)
	//	{
	//		mapInfo.MapInfo[y][x] = g_MapInfo[y][x];

	//		if (g_MapInfo[y][x] == 'X')
	//		{
	//			mapInfo.BoxCnt++;
	//		}
	//	}

	//	// �� ���� ������ ���ϱ�
	//	int sizeW = strlen(mapInfo.MapInfo[y]);
	//	// �� ���̰� �ٸ� �ʵ� �ֱ� ������ �� ���� ����� ������ ������ ����
	//	if (mapInfo.MapSizeW < sizeW)
	//	{
	//		mapInfo.MapSizeW = sizeW;
	//	}

	//	// �� ���� ���ϱ�
	//	++mapInfo.MapSizeH;
	//}

	//// �����ϱ�
	//char fileName[256] = "SaveData.txt";
	//FILE* fw = fopen(fileName, "w");

	//// �� ���� ���� (fprintf ���)
	//// �� ������ ����
	//fprintf(fw, "MAPSIZE: %d %d\n", mapInfo.MapSizeW, mapInfo.MapSizeH);
	//// �� �ڽ� ����
	//fprintf(fw, "BOXCOUT: %d\n", mapInfo.BoxCnt);
	//// �� ����
	//fprintf(fw, "MAPINFO:\n");

	//for (size_t i = 0; i < mapInfo.MapSizeH; i++)
	//{
	//	fprintf(fw, "%s\n", mapInfo.MapInfo[i]);
	//}

	//fclose(fw);

	//char fileName[256] = "MapInfo1.txt";

	//int val = 0;

	//printf("���������� �����ϼ���: ");
	//scanf("%d", &val);

	////fileName[7] = val + '0'; // "0"

	//sprintf(fileName, "MapInfo%d.txt", val);

	//// ���� �о� ����
	//FILE* fr = fopen(fileName, "r");

	//if (fr == NULL)
	//{
	//	printf("������ �о���� ���߽��ϴ�.\n");
	//	return;
	//}

	/*char mapinfo1[MAXWIDTHSIZE] = "";
	char mapinfo2[MAXWIDTHSIZE] = "";*/
	// ������ �� �Է�
	// �б�, ����
	//fscanf(fr, "%s", &mapinfo1[0]);	// ù ��° �� ����
	//fscanf(fr, "%s", &mapinfo2[0]);	// �� ��° �� ����

	/*while (true)
	{
		char* tempstr = fgets(mapinfo1, MAXWIDTHSIZE, fr);
		if (tempstr == NULL) break;
	}*/

	//int lineCnt = 0;
	//while (fgets(g_MapInfo[lineCnt], MAXWIDTHSIZE, fr))
	//{
	//	int pos = strcspn(g_MapInfo[lineCnt], "\n"); // \n�� ã�Ƴ��� �� ��ġ�� ���� �ٲٴ� ����
	//	g_MapInfo[lineCnt][pos] = '\0'; // ã�� \n�� ��ġ�� NULL �ֱ�
	//	lineCnt++;
	//}

	//char* tempstr = fgets(mapinfo1, MAXWIDTHSIZE, fr); // fgets�� ��ȯŸ���� char*
	// ���Ͽ� ���� ���� �� tempstr���� NULL�� ��ȯ��
	//tempstr = fgets(mapinfo2, MAXWIDTHSIZE, fr); // fgets�� ��ȯŸ���� char*

	//fclose(fr);
}