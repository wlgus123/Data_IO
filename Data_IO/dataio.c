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
	// ������ I/O ����
	// RAM�̶� �Ȱ����� SSD ���� ��ü�� �ٸ�

	int volumn = 10;

	// ���� ó��
	/*FILE* fw = fopen("b.txt", "w");

	fprintf(fw, "%d\n", volumn);

	fclose(fw);*/ // �� �ݾ���� �� (�޸� ����)

	// �б�
	FILE* fr = fopen("b.txt", "r");
	// ������ ���� ��� NULL�� ��ȯ��
	if (fr == NULL)
	{
		printf("������ �����ϴ�.\n");
	}

	// ���� �о���̱� (fscanf)
	char tempStr[STR_MAX];
	int tempVal = 0;
	int tempVal2 = 0;
	fscanf(fr, "%s %d", tempStr, &tempVal);
	fscanf(fr, "%s %d", tempStr, &tempVal2);
	
	printf("�о� ���� ��: %d, %d\n", tempVal, tempVal2);
	
	// ������ ���� �� fr�� NULL�� �ٲٱ�
	if (fr)
	{
		fclose(fr);
		fr = NULL;
	}

	// �б�2
	FILE* fr2 = fopen("b.txt", "r");
	// ������ ���� ��� NULL�� ��ȯ��
	if (fr2 == NULL)
	{
		printf("������ �����ϴ�.\n");
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

	// ������ ����
	// ���̺귯��(json, csv, xml) ���
	// DB ����(2-2�б�)
	// sqlite3

	// ���� ������ ����
	Option op = { 10, 1, 0, ""};
}