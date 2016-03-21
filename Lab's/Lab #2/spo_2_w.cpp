#pragma once
#include "spo_2_w.h"


spo_2_w::spo_2_w()
{
}


spo_2_w::~spo_2_w()
{
}

int spo_2_w::wincall(int x)
{
	int c;
	DWORD dwExitCode = NULL;
	STARTUPINFO StartupInfo; 
	PROCESS_INFORMATION ProcInfo;
	ZeroMemory( &ProcInfo, sizeof(ProcInfo) );

	if (x > 0)
	{
		printf("Process: #%d \n", x);
		switch (getch())
		{
			
			case '+':
			{	
				x++;
				
				STARTUPINFO StartupInfo;
				PROCESS_INFORMATION ProcInfo;

				TCHAR CommandLine[50];
				_tcscpy(CommandLine, A2T(concatCP(x)));

				ZeroMemory(&StartupInfo, sizeof(StartupInfo));
				StartupInfo.cb = sizeof(StartupInfo);
				ZeroMemory(&ProcInfo, sizeof(ProcInfo));

				if (!CreateProcess(NULL, // Не используется имя модуля
					CommandLine,
					NULL,                 // Дескриптор процесса не наследуется.
					NULL,                 // Дескриптор потока не наследуется.
					FALSE,                // Установка описателей наследования
					0,                    // Нет флагов создания процесса
					NULL,                 // Блок переменных окружения родительского процесса
					NULL,                 // Использовать текущий каталог родительского процесса
					&StartupInfo,         // Указатель на структуру  STARTUPINFO.
					&ProcInfo)            // Указатель на структуру информации о процессе.
					)

				{
					
					printf("CreateProcess failed with error code (%d).\n", GetLastError());    //в случае ошибки выводим код ошибки и завершаем работу
					return 0;
				}
				   
				WaitForSingleObject(ProcInfo.hProcess, INFINITE);       // Ждать окончания дочернего процесса   
				
				GetExitCodeProcess(ProcInfo.hProcess, &dwExitCode);     //получить код возврата дочернего процесса

				x = (int)dwExitCode;                                    //записываем возращенное значение

			}break;

			case '-':
			{
				if (x == 1)
				{
					return 0;
				}
				x--;

				// Закрыть описатели процесса и потока и вернули х
				CloseHandle(ProcInfo.hProcess);
				CloseHandle(ProcInfo.hThread);

				return x;
			}break;

			case 'q':
			{
				// Закрыть описатели процесса и потока и вернули 0
				CloseHandle(ProcInfo.hProcess);
				CloseHandle(ProcInfo.hThread);

				return 0;
			}break;

			default:
			{
				return x;
			}break;

		};

	}
	else
	{
		CloseHandle(ProcInfo.hProcess);
		CloseHandle(ProcInfo.hThread);

		return x;
	}
}

char* spo_2_w::concatCP(int x) // добавляем к названию имени проццеса его номер
{
	char* str1 = (char*)calloc(50, sizeof(char));
	itoa(x, str1, 10);
	char* str2 = (char*)calloc(50, sizeof(char));

	strcpy(str2, "spown2 ");
	strcat(str2, str1);

	return str2;
}