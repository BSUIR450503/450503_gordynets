#pragma once

#ifdef _WIN32
#include <conio.h>
#include "atlbase.h"
#include "atlstr.h"
#include "comutil.h"
#include <windows.h>
#include "spo_2_w.h"

#else 
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "spo_2_l.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>