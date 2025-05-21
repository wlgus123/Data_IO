#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define STR_MAX 256

typedef struct MonsterInfo
{
	char name[STR_MAX];
	int ATK;
	int HP;
}MonsterInfo;

void main()
{
	// 읽기
	FILE* fr = fopen("Monster.csv", "r");

	char name[STR_MAX];
	int ATK;
	int HP;

	// 1줄 읽기
	fgets(name, STR_MAX, fr);

	// 2번째줄 읽기
	fscanf(fr, "%s %d %d", name, &ATK, &HP);
	fscanf(fr, "%s %d %d", name, &ATK, &HP);

	// 라인 수 읽어오기 (fgets 사용)
	int lineCnt = 0;
	char* tempChar = NULL;

	// 원론적인 방법 (feof)
	/*while(!feof(fr))
	{
		tempChar = fgets(name, STR_MAX, fr);
		++lineCnt;
	}*/
	// 좀 더 간단한 방법
	while (!fgets(tempChar, STR_MAX, fr))
	{
		++lineCnt;
	}

	// 처음 줄로 이동
	rewind(fr);

	// 동적할당(malloc) 사용해서 정보 불러오기
	MonsterInfo* monster = malloc(sizeof(MonsterInfo) * lineCnt);
	for (size_t i = 0; i < lineCnt; i++)
	{
		fscanf(fr, "%s %d %d", monster[i].name, &monster[i].ATK, &monster[i].HP);
		printf("%s %d %d\n", monster[i].name, monster[i].ATK, monster[i].HP);
	}

	free(monster);
}