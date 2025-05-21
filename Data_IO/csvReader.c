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
	// 읽기 다른 방법
	while (fgets(tempStr, STR_MAX, p_file))
		++lineCnt;

	return lineCnt;
}

void main()
{
	char tempLineStr[STR_MAX] = "고블린,10,10\n";

	// 들여쓰기 없애기
	int pos = strcspn(tempLineStr, "\n"); // \n을 찾아내고 그 위치의 값을 바꾸는 역할
	tempLineStr[pos] = '\0';

	int val = 0;
	char* tempTok = strtok(tempLineStr, ",");
	while (tempTok != NULL)
	{
		tempTok = strtok(NULL, ",");

		// 문자 -> 숫자
		// 숫자 형태인 문자를 int형으로 바꿔서 변수에 저장
		val = atoi(tempTok);
	}

	// 읽기
	FILE* fr = fopen("Monster.csv", "r");

	int lineCnt = FileLineCount(fr);

	char lineStr[STR_MAX] = "";
	MonsterInfo* monster = malloc(sizeof(MonsterInfo) * lineCnt);

	for (size_t i = 0; i < lineCnt; i++)
	{
		fgets(lineStr, STR_MAX, fr);

		// 콤마(,)가 있기 전까지 문자열 읽어들이기 (strtok 사용)
		// lineStr = "고블린,10,10\n"
		char* token = strtok(lineStr, ",");
		while (token != NULL)
		{
			token = strtok(NULL, ",");
		}

	}

	free(monster);
}