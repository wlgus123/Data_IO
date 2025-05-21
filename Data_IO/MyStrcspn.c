#include "MyStrcspn.h"

int MyStrcspn(char* p_tempStr, char* p_src)
{
	int tempStrSize = strlen(p_tempStr);
	int srcSize = strlen(p_src);
	int strCnt = 0;

	// tempStr�� ũ�Ⱑ 0 ������ ��� ERROR(-1) ��ȯ
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

		// ���ڸ� ��� ã���� �� ã�� ������ ��ġ(���� ��ġ - ���� ũ�� + 1) ��ȯ�ϱ�
		if (strCnt == srcSize)
		{
			return tempIdx;
		}
	}

	// ���ڸ� ã�� ������ �� ERROR(-1) ��ȯ
	if (strCnt == 0)
	{
		return ERROR;
	}

	return ERROR;
}