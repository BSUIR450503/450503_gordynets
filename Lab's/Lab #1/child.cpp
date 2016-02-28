#include "stdafx.h"
#include <Windows.h>

int main(int argc, char** argv)
{
	int x = 0;
	x = atoi(argv[1]);
	x*=x;
	return x;
}

