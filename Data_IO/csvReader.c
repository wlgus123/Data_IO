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

int FileLineCount(FILE* p_file)
{
	char tempStr[1000];
	int lineCnt = 0;
	// �б� �ٸ� ���
	while (fgets(tempStr, STR_MAX, p_file))
		++lineCnt;

	return lineCnt;
}

void main()
{
	char tempLineStr[STR_MAX] = "���,10,10\n";

	// �鿩���� ���ֱ�
	int pos = strcspn(tempLineStr, "\n"); // \n�� ã�Ƴ��� �� ��ġ�� ���� �ٲٴ� ����
	tempLineStr[pos] = '\0';

	int val = 0;
	char* tempTok = strtok(tempLineStr, ",");
	while (tempTok != NULL)
	{
		tempTok = strtok(NULL, ",");

		// ���� -> ����
		// ���� ������ ���ڸ� int������ �ٲ㼭 ������ ����
		val = atoi(tempTok);
	}

	// �б�
	FILE* fr = fopen("Monster.csv", "r");

	int lineCnt = FileLineCount(fr);

	char lineStr[STR_MAX] = "";
	MonsterInfo* monster = malloc(sizeof(MonsterInfo) * lineCnt);

	for (size_t i = 0; i < lineCnt; i++)
	{
		fgets(lineStr, STR_MAX, fr);

		// �޸�(,)�� �ֱ� ������ ���ڿ� �о���̱� (strtok ���)
		// lineStr = "���,10,10\n"
		char* token = strtok(lineStr, ",");
		while (token != NULL)
		{
			token = strtok(NULL, ",");
		}

	}

	free(monster);
}