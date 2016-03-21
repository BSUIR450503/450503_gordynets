// spo_1.cpp: определяет точaку входа для консольного приложения.
//

#include "includes.h"


using namespace std;


int main(int argc, char** argv)
{
	int x = 11;
	printf("%d ^2 = ", x);
#ifdef _WIN32
	
	spo_1_w win;
	
	x = win.wincall(x);
	printf("%d", x);
	system("pause");

#elif linux

	spo_1_l lin;
	lin.lincall(x);

#endif
	return 0;

}
