#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "spo_1_w.h"


spo_1_w::spo_1_w()
{
}


spo_1_w::~spo_1_w()
{
}

int spo_1_w::wincall(int x)
{
	int c;
	DWORD dwExitCode = NULL;


	STARTUPINFO StartupInfo;
	PROCESS_INFORMATION ProcInfo;

	TCHAR CommandLine[50];
	_tcscpy(CommandLine, A2T(concatCP(x)));

	ZeroMemory(&StartupInfo, sizeof(StartupInfo));
	StartupInfo.cb = sizeof(StartupInfo);
	ZeroMemory(&ProcInfo, sizeof(ProcInfo));

	if (!CreateProcess(NULL, // �� ������������ ��� ������
		CommandLine,
		NULL,                 // ���������� �������� �� �����������.
		NULL,                 // ���������� ������ �� �����������.
		FALSE,                // ��������� ���������� ������������
		0,                      // ��� ������ �������� ��������
		NULL,                 // ���� ���������� ��������� ������������� ��������
		NULL,                 // ������������ ������� ������� ������������� ��������
		&StartupInfo,         // ��������� �� ���������  STARTUPINFO.
		&ProcInfo)           // ��������� �� ��������� ���������� � ��������.
		)

	{
		//� ������ ������ ������� ��� ������ � ��������� ������
		printf("CreateProcess failed with error code (%d).\n", GetLastError());
		return 0;
	}
	// ����� ��������� ��������� ��������      
	WaitForSingleObject(ProcInfo.hProcess, INFINITE);
	//�������� ��� �������� ��������� ��������
	GetExitCodeProcess(ProcInfo.hProcess, &dwExitCode);
	x = (int)dwExitCode;

	CloseHandle(ProcInfo.hProcess);
	CloseHandle(ProcInfo.hThread);
	return x;
}

char* spo_1_w::concatCP(int x)
{
	char* str1 = (char*)calloc(50, sizeof(char));
	_itoa(x, str1, 10);
	char* str2 = (char*)calloc(50, sizeof(char));

	strcpy(str2, "child ");
	strcat(str2, str1);

	return str2;
}