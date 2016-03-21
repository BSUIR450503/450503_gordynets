#pragma once
#include "spo_2_l.h"


spo_2_l::spo_2_l()
{
}


spo_2_l::~spo_2_l()
{
}

int spo_2_l::lincall()
{
#ifdef linux
	int x = 1;
	printf("process %d\n", x);
	pid_t pid;          // проццес айди
	int rv;             // возращаемое значение
	while (true)
	{

		switch (getchar())
		{
			case '+':
			{
				pid = fork();
				switch (pid)
				{
					case -1:
					{
						perror("fork error!");
						exit(0);
					}
					case 0:
					{
						x++;
						printf("Process #%d \n", x);
					}break;

					default:
					{   
						wait(&rv);        // ждем оканчание дочернего проццеса
						WEXITSTATUS(rv);  // получаем возращаемое значение
						if (rv == 0)
						{
							exit(0);
						}
						printf("Process #%d \n", rv / 256);
					}
				};
			}break;

			case '-':
			{
				x--;
				exit(x);
			}
			case 'q':
			{
				exit(0);
				break;
			}
		};

	}
#endif
	return 0;
}