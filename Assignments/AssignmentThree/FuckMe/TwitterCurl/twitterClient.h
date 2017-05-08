#pragma once
#pragma comment(lib, "legacy_stdio_definitions.lib") 
#include <cstdio>
#include <iostream>
#include <fstream>
FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
#include "include/twitcurl.h"


