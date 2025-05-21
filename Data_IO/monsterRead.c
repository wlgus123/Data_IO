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
	// �б�
	FILE* fr = fopen("Monster.csv", "r");

	char name[STR_MAX];
	int ATK;
	int HP;

	// 1�� �б�
	fgets(name, STR_MAX, fr);

	// 2��°�� �б�
	fscanf(fr, "%s %d %d", name, &ATK, &HP);
	fscanf(fr, "%s %d %d", name, &ATK, &HP);

	// ���� �� �о���� (fgets ���)
	int lineCnt = 0;
	char* tempChar = NULL;

	// �������� ��� (feof)
	/*while(!feof(fr))
	{
		tempChar = fgets(name, STR_MAX, fr);
		++lineCnt;
	}*/
	// �� �� ������ ���
	while (!fgets(tempChar, STR_MAX, fr))
	{
		++lineCnt;
	}

	// ó�� �ٷ� �̵�
	rewind(fr);

	// �����Ҵ�(malloc) ����ؼ� ���� �ҷ�����
	MonsterInfo* monster = malloc(sizeof(MonsterInfo) * lineCnt);
	for (size_t i = 0; i < lineCnt; i++)
	{
		fscanf(fr, "%s %d %d", monster[i].name, &monster[i].ATK, &monster[i].HP);
		printf("%s %d %d\n", monster[i].name, monster[i].ATK, monster[i].HP);
	}

	free(monster);
}