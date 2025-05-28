#include "MyStrcspn.h"

// 조건은 최소한 3개 정도 잡아주기
int MyStrcspn(const char* p_tempStr
	, const char* p_src
	, int p_offsetPos) // 찾을 위치
{
	// 찾을 위치가 0보다 작을 경우 0으로 초기화
	if (p_offsetPos < 0)
		p_offsetPos = 0;

	int strSize = strlen(p_tempStr);
	int srcSize = strlen(p_src);
	int strCnt = 0;

	// 찾을 위치가 tempStr 크기보다 클 경우 tempStr 크기 - 1로 초기화
	if (p_offsetPos >= strSize)
		p_offsetPos = strSize - 1;

	// tempStr의 크기가 0 이하일 경우 ERROR(-1) 반환
	if (p_tempStr <= 0 || p_src <= 0)
	{
		return ERROR;
	}

	for (size_t tempIdx = p_offsetPos; tempIdx < strSize; tempIdx++)
	{
		if (p_tempStr[tempIdx] == p_src[0])
		{
			for (size_t srcIdx = 0; srcIdx < srcSize; srcIdx++)
			{
				if (tempIdx + srcIdx >= strSize)
					continue;

				if (p_tempStr[tempIdx + srcIdx] == p_src[srcIdx])
				{
					++strCnt;
				}
				else
				{
					strCnt = 0;
					break;
				}
			}
		}
		else
		{
			strCnt = 0;
		}

		// 글자를 모두 찾았을 때 찾기 시작한 위치(tempIdx) 반환하기
		if (strCnt == srcSize)
		{
			return tempIdx;
		}
	}

	// 글자를 찾지 못했을 때 ERROR(-1) 반환
	if (strCnt == 0)
	{
		return ERROR;
	}

	return ERROR;
}