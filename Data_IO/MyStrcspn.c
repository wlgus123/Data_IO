#include "MyStrcspn.h"

int MyStrcspn(char* p_tempStr, char* p_src)
{
	int tempStrSize = strlen(p_tempStr);
	int srcSize = strlen(p_src);
	int strCnt = 0;

	// tempStr의 크기가 0 이하일 경우 ERROR(-1) 반환
	if (p_tempStr <= 0 || p_src <= 0)
		return ERROR;

	for (size_t tempIdx = 0; tempIdx < tempStrSize; tempIdx++)
	{
		if (p_tempStr[tempIdx] == p_src[0])
		{
			for (size_t srcIdx = 0; srcIdx < srcSize; srcIdx++)
			{
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

		// 글자를 모두 찾았을 때 찾기 시작한 위치(현재 위치 - 문자 크기 + 1) 반환하기
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