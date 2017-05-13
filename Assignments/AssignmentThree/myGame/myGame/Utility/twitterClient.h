#pragma once
#pragma comment(lib, "legacy_stdio_definitions.lib") 
#include <cstdio>

#include <iostream>
#include <fstream>
#include "../include/twitcurl.h"

namespace Twitter
{
	void init();

	bool auth();

	std::string getFeed();
	
}