#include "MyReplaceStr.h"
#include "MyStrcspn.h"

int MyReplaceStr(OUT char p_str[]
	, const char* p_findStr
	, const char* p_changeStr)
{
	// �迭�� �������� ����
	// ������: str[0] = 'e'; �Ұ���
	// ���� �ٲ��� ���ϴ� �ٸ� �޸𸮿� ���������� ��� ���ױ� ������ ���� �Ұ��� (read only)
	// �迭: str[0] = 'e';�� ����
	// �Լ��� ���� ������ ������ ������(������), �� ������(�迭) ������

	int pos = MyStrcspn(p_str, p_findStr, 0);
	if (pos <= -1)
		return;

	// ġȯ ����
	int strSize = strlen(p_str);
	int changeSize = strlen(p_changeStr);
	int findSize = strlen(p_findStr);

	// 1:1 ġȯ
	if (changeSize == findSize)
	{
		for (size_t i = 0; i < changeSize; i++)
		{
			p_str[i + pos] = p_changeStr[i];
		}
	}

	// n:1 ġȯ
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

	// 1:n ġȯ
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

		// �������κ� �۾�
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
