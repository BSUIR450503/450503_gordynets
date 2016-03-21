#include "includes.h"


using namespace std;


int main(int argc, char** argv)
{
#ifdef _WIN32
	int x;

	if (argc < 2)
	{
		x = 1;
	}
	else
	{
		x = atoi(argv[1]);
	}
	if (x < 1)
	{
		return 0;
	}
	while (true)
	{
		spo_2_w win;
		x = win.wincall(x); //заходит в виндовую функцию создания проццеса
		if (x == 0)
		{
			break;
		}
	}

	return 0;

#elif linux

	spo_2_l lin;            //
	lin.lincall();			//

#endif
	return 0;
	
}