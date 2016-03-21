#include "spo_1_l.h"


spo_1_l::spo_1_l()
{
}


spo_1_l::~spo_1_l()
{
}

int spo_1_l::lincall(int x)
{
#ifdef linux
	pid_t pid;
	int rv = 0;
printf("\n");
	pid = fork();
	switch (pid)
	{
	case -1:
		perror("fork");
		exit(0);
	case 0:
		x *= x;
		exit(x);
	default:
		wait(&rv);
		WEXITSTATUS(rv);
		printf("%d\n", rv / 256);
		exit(0);
	};
#endif
return 0;
}
