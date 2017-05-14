#include <iostream>
FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
#include "../Utility/Twitter.h"
int main()
{
	
	Twitter twitterObj;

	twitterObj.authenticate();
	twitterObj.readFeed();

	std::cout << twitterObj.getRealRandomTweet() << std::endl;
	std::cout << twitterObj.getRealRandomTweet() << std::endl;
	std::cout << twitterObj.getRealRandomTweet() << std::endl;
	std::cout << twitterObj.getRealRandomTweet() << std::endl;
	
	system("pause");

	return 0;
}