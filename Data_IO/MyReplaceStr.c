#include "MyReplaceStr.h"
#include "MyStrcspn.h"

int MyReplaceStr(OUT char p_str[]
	, const char* p_findStr
	, const char* p_changeStr)
{
	// 배열과 포인터의 차이
	// 포인터: str[0] = 'e'; 불가능
	// 내가 바꾸지 못하는 다른 메모리에 강제적으로 등록 시켰기 때문에 수정 불가능 (read only)
	// 배열: str[0] = 'e';가 가능
	// 함수에 보낼 때부터 에러가 나는지(포인터), 안 나는지(배열) 결졍됨

	int pos = MyStrcspn(p_str, p_findStr, 0);
	if (pos <= -1)
		return;

	// 치환 조건
	int strSize = strlen(p_str);
	int changeSize = strlen(p_changeStr);
	int findSize = strlen(p_findStr);

	// 1:1 치환
	if (changeSize == findSize)
	{
		for (size_t i = 0; i < changeSize; i++)
		{
			p_str[i + pos] = p_changeStr[i];
		}
	}

	// n:1 치환
	if (changeSize > findSize)
	{
		for (size_t i = 0; i < changeSize; i++)
		{
			p_str[i + pos] = p_changeStr[i];
		}

		for (size_t i = pos + changeSize; i < strSize; i++)
		{
			p_str[i] = p_str[i + 1];
		}
	}

	// 1:n 치환
	if (findSize > changeSize)
	{
		char cpyStr[100] = "";

		int cpyIdx = 0;
		for (int i = pos + findSize; i < strSize + 1; i++)
		{
			cpyStr[cpyIdx++] = p_str[i];
		}

		for (int i = 0; i < changeSize; i++)
		{
			p_str[i + pos] = p_changeStr[i];
		}

		// 나머지부분 작업
		int strIdx = pos + changeSize;
		int endIdx = strSize + (changeSize - findSize);
		cpyIdx = 0;

		for (int i = strIdx; i < endIdx; i++)
		{
			p_str[i] = cpyStr[cpyIdx++];
		}
		p_str[endIdx + 1] = '\0';

	}
}
