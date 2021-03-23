#pragma once

#include "../resource.h"

#include <windows.h>
#include <stdio.h>

#if _DEBUG
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#define xprintf printf
#else
#define xprintf(void*)
#endif
