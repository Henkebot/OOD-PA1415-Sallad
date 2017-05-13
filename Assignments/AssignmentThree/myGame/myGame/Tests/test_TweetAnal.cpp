#include <iostream>
FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
#include "../UserInterface/Application.h"
#include "../Utility/TweetAnalyzer.h"
#include "../Utility/Identifier.h"

int main()
{
	Identifier* test = nullptr;
	TweetAnalyser::getInRoom("We like big B... BTH xD", test);


	return 0;
}