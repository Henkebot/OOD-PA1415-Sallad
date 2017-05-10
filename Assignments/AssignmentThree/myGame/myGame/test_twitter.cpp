#include "Twitter.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Twitter t;
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << t.getRandomTweet() << std::endl;
		system("pause");
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}