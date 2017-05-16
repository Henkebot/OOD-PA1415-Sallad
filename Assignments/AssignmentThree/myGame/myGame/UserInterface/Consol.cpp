#include "Consol.h"

static std::string messages[10]{ "" };

void Consol::setMessage(const std::string & message)
{
	Consol::moveUp();
	Consol::messages[9] = message;
}

std::string Consol::getMessages(int index)
{
	return Consol::messages[index];
}

void Consol::moveUp()
{
	for (int i = 9; i > 0; i++)
	{
		Consol::messages[i - 1] = Consol::messages[i];
	}
}
