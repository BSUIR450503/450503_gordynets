#pragma once

#include "includes.h"

class spo_2_w
{
public:
	spo_2_w();
	~spo_2_w();

	int wincall(int x);
	
private:
	char* concatCP(int x);
};

