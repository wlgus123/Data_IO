#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <direct.h>
#include <errno.h>

#define STR_MAX 256

typedef struct Option
{
	int volumn;
	int ISSound;

	int ISMemeber;
	char ID[256];
} Option;

void main()
{
	// 데이터 I/O 예제
	// RAM이랑 똑같지만 SSD 접근 자체가 다름

	int volumn = 10;

	// 쓰기 처리
	/*FILE* fw = fopen("b.txt", "w");

	fprintf(fw, "%d\n", volumn);

	fclose(fw);*/ // 꼭 닫아줘야 함 (메모리 해제)

	// 읽기
	FILE* fr = fopen("b.txt", "r");
	// 파일이 없을 경우 NULL로 반환함
	if (fr == NULL)
	{
		printf("파일이 없습니다.\n");
	}

	// 파일 읽어들이기 (fscanf)
	char tempStr[STR_MAX];
	int tempVal = 0;
	int tempVal2 = 0;
	fscanf(fr, "%s %d", tempStr, &tempVal);
	fscanf(fr, "%s %d", tempStr, &tempVal2);
	
	printf("읽어 들인 값: %d, %d\n", tempVal, tempVal2);
	
	// 파일이 있을 때 fr을 NULL로 바꾸기
	if (fr)
	{
		fclose(fr);
		fr = NULL;
	}

	// 읽기2
	FILE* fr2 = fopen("b.txt", "r");
	// 파일이 없을 경우 NULL로 반환함
	if (fr2 == NULL)
	{
		printf("파일이 없습니다.\n");
	}
	
	char lineRead[STR_MAX];
	
	while (1)
	{
		char* result = fgets(lineRead, sizeof(lineRead), fr2);
		if (result == NULL) break;
	}

	/*while (fgets(lineRead, STR_MAX, fr2) != NULL)
	{
		fputs(lineRead, fr2);
	}*/

	// 데이터 저장
	// 라이브러리(json, csv, xml) 사용
	// DB 저장(2-2학기)
	// sqlite3

	// 정보 가지고 오기
	Option op = { 10, 1, 0, ""};
}