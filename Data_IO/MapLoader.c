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
#define STRMAX 1000

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

int getLineSize(FILE* p_file)
{
	char tempStr[STRMAX];
	int lineCnt = 0;
	while (fgets(tempStr, STRMAX, p_file))
	{
		++lineCnt;
	}

	return lineCnt;
}

void main()
{
	// ���嵵 ���� ���� ������� �ؼ� �����ϱ�
	// �Լ�, ����, �ε� ó��
	// strcspn(tempstr, "\n") -> mystrcspn() ���� ���� �����
	// �����Ҵ� ó������
	// ����_C���_�̸�_�й�.zip
	// 12�� 30�� ~

	printf("%d\n", MyStrcspn("Hello\nWorld\n", "\n"));

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