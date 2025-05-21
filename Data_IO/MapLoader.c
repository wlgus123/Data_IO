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

// 전역변수
char* g_MapInfo[MAXWIDTHSIZE];
//char g_MapInfo[5][MAXHEIGHTSIZE][MAXWIDTHSIZE]; // 3차원 배열로 여러 스테이지 지정 가능

// or 구조체 형식으로
typedef struct MapInfoData
{
	char MapCreatorName[256];
	int MapSizeW;
	int MapSizeH;
	int BoxCnt;
	// -> 부가적인 요소
	char MapInfo[MAXHEIGHTSIZE][MAXWIDTHSIZE];
} MapInfoData;

MapInfoData gameMap[3]; // 구조체 배열

void main()
{
	// 저장도 파일 명을 물어보도록 해서 저장하기
	// 함수, 형식, 로드 처리
	// strcspn(tempstr, "\n") -> mystrcspn() 같은 역할 만들기
	// 동적할당 처리까지
	// 과제_C언어_이름_학번.zip
	// 12시 30분 ~

	// MyStrcspn 불러오기
	// 맵 데이터 변수 초기화
	int mapW = 0;
	int mapH = 0;
	int boxCnt = 0;
	char** map = NULL;

	// 파일 읽어오기
	FILE* fr = fopen("MapData.txt", "r");
	if (!fr)
	{
		printf("파일을 읽어들이지 못했습니다.\n");
		return;
	}

	char tempStr[STRMAX];
	fscanf(fr, "%s %d %d ", tempStr, &mapW, &mapH); // 맵 크기
	fscanf(fr, "%s %d ", tempStr, &boxCnt); // 박스 갯수
	fgets(tempStr, mapW, fr); // 맵 정보(글자만)

	// 동적할당 처리
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
		pos = MyStrcspn(map[i], "\n"); // \n이 있는 위치 찾기(MyStrscpn 사용)

		// \n이 없을 경우 건너뛰기
		if (pos == -1)
		{
			continue;
		}

		map[i][pos] = '\0';
	}

	for (size_t i = 0; i < mapH; i++)
	{
		// 한 줄에 아무것도 없을 때 (\0일 때) 건너뛰기
		if (map[i][0] == '\0')
		{
			continue;
		}
		printf("%s\n", map[i]);
	}

	// 메모리 해제
	for (size_t i = 0; i < mapH; i++)
	{
		free(map[i]);
	}
	free(map);
	fclose(fr);

	// 동적할당 처리
	// 파일 읽어오기
	//MapInfoData map;
	//map.MapSizeW = 0;
	//map.MapSizeH = 0;
	//map.BoxCnt = 0;
	//FILE* fr = fopen("MapData.txt", "r");
	//if (!fr)
	//{
	//	printf("파일을 불러오지 못했습니다.\n");
	//	return;
	//}
	//int lineSize = getLineSize(fr); // 줄 수 불러오기

	//fclose(fr);

	//MapInfoData mapInfo;
	//// 구조체 값 초기화
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

	//	// 맵 넓이 사이즈 구하기
	//	int sizeW = strlen(mapInfo.MapInfo[y]);
	//	// 맵 넓이가 다른 맵도 있기 때문에 더 넓은 사이즈가 있으면 사이즈 설정
	//	if (mapInfo.MapSizeW < sizeW)
	//	{
	//		mapInfo.MapSizeW = sizeW;
	//	}

	//	// 맵 높이 구하기
	//	++mapInfo.MapSizeH;
	//}

	//// 저장하기
	//char fileName[256] = "SaveData.txt";
	//FILE* fw = fopen(fileName, "w");

	//// 맵 정보 쓰기 (fprintf 사용)
	//// 맵 사이즈 지정
	//fprintf(fw, "MAPSIZE: %d %d\n", mapInfo.MapSizeW, mapInfo.MapSizeH);
	//// 맵 박스 갯수
	//fprintf(fw, "BOXCOUT: %d\n", mapInfo.BoxCnt);
	//// 맵 정보
	//fprintf(fw, "MAPINFO:\n");

	//for (size_t i = 0; i < mapInfo.MapSizeH; i++)
	//{
	//	fprintf(fw, "%s\n", mapInfo.MapInfo[i]);
	//}

	//fclose(fw);

	//char fileName[256] = "MapInfo1.txt";

	//int val = 0;

	//printf("스테이지를 선택하세요: ");
	//scanf("%d", &val);

	////fileName[7] = val + '0'; // "0"

	//sprintf(fileName, "MapInfo%d.txt", val);

	//// 파일 읽어 오기
	//FILE* fr = fopen(fileName, "r");

	//if (fr == NULL)
	//{
	//	printf("파일을 읽어오지 못했습니다.\n");
	//	return;
	//}

	/*char mapinfo1[MAXWIDTHSIZE] = "";
	char mapinfo2[MAXWIDTHSIZE] = "";*/
	// 변수에 값 입력
	// 읽기, 쓰기
	//fscanf(fr, "%s", &mapinfo1[0]);	// 첫 번째 줄 정보
	//fscanf(fr, "%s", &mapinfo2[0]);	// 두 번째 줄 정보

	/*while (true)
	{
		char* tempstr = fgets(mapinfo1, MAXWIDTHSIZE, fr);
		if (tempstr == NULL) break;
	}*/

	//int lineCnt = 0;
	//while (fgets(g_MapInfo[lineCnt], MAXWIDTHSIZE, fr))
	//{
	//	int pos = strcspn(g_MapInfo[lineCnt], "\n"); // \n을 찾아내고 그 위치의 값을 바꾸는 역할
	//	g_MapInfo[lineCnt][pos] = '\0'; // 찾은 \n의 위치에 NULL 넣기
	//	lineCnt++;
	//}

	//char* tempstr = fgets(mapinfo1, MAXWIDTHSIZE, fr); // fgets는 반환타입이 char*
	// 파일에 값이 없을 때 tempstr에는 NULL이 반환됨
	//tempstr = fgets(mapinfo2, MAXWIDTHSIZE, fr); // fgets는 반환타입이 char*

	//fclose(fr);
}