#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>

#define ERROR -1

int MyReplaceStr(OUT char p_str[], const char* p_findStr, const char* p_changeStr);
int MyReplaceStr2(OUT char p_str[], const char* p_findStr, const char* p_changeStr);