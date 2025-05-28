#include "MyStrcspn.h"

// ������ �ּ��� 3�� ���� ����ֱ�
int MyStrcspn(const char* p_tempStr
	, const char* p_src
	, int p_offsetPos) // ã�� ��ġ
{
	// ã�� ��ġ�� 0���� ���� ��� 0���� �ʱ�ȭ
	if (p_offsetPos < 0)
		p_offsetPos = 0;

	int strSize = strlen(p_tempStr);
	int srcSize = strlen(p_src);
	int strCnt = 0;

	// ã�� ��ġ�� tempStr ũ�⺸�� Ŭ ��� tempStr ũ�� - 1�� �ʱ�ȭ
	if (p_offsetPos >= strSize)
		p_offsetPos = strSize - 1;

	// tempStr�� ũ�Ⱑ 0 ������ ��� ERROR(-1) ��ȯ
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

		// ���ڸ� ��� ã���� �� ã�� ������ ��ġ(tempIdx) ��ȯ�ϱ�
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