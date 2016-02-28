

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#endif
void main( void )
{
#ifdef _WIN32
	int x = 9;
	
	STARTUPINFO StartupInfo;
    PROCESS_INFORMATION ProcInfo;
    TCHAR CommandLine[] = TEXT("child 9"); //отправляем через командную строку число, с которым работаем


	ZeroMemory( &StartupInfo, sizeof(StartupInfo) );
    StartupInfo.cb = sizeof(StartupInfo);
    ZeroMemory( &ProcInfo, sizeof(ProcInfo) );

	if( !CreateProcess( NULL, // Не используется имя модуля 
        CommandLine,	      // Командная строка
        NULL,                 // Дескриптор процесса не наследуется. 
        NULL,                 // Дескриптор потока не наследуется. 
        FALSE,                // Установка описателей наследования
        0,					  // Нет флагов создания процесса
        NULL,                 // Блок переменных окружения родительского процесса
        NULL,                 // Использовать текущий каталог родительского процесса
        &StartupInfo,         // Указатель на структуру  STARTUPINFO.
        &ProcInfo )           // Указатель на структуру информации о процессе.
      )
    
	{
		//в случае ошибки выводим код ошибки и завершаем работу
        printf("CreateProcess failed with error code (%d).\n", GetLastError());
        return;
    }

    // Ждать окончания дочернего процесса      
    WaitForSingleObject( ProcInfo.hProcess, INFINITE );
	//получить код возврата дочернего процесса
	DWORD dwExitCode = NULL;
	GetExitCodeProcess( ProcInfo.hProcess, &dwExitCode );

	printf("%d ^ 2 = %d\n", x, (int)dwExitCode );

	// Закрыть описатели процесса и потока 
    CloseHandle( ProcInfo.hProcess );
    CloseHandle( ProcInfo.hThread );
#else
	int x = 9;
	pid_t pid;
	int rv;
	pid=fork()
	switch(pid) 
	{
		case -1:
			perror("fork"); /* произошла ошибка */
			exit(1);
		case 0:
			x *=x;
			exit(x);
		default:
			wait();
			WEXITSTATUS(rv);
	}
#endif
}

