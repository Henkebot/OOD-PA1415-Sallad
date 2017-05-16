#ifndef CONSOL_H
#define CONSOL_H
#include <string>

static class Consol
{
public:
	static void setMessage(const std::string & message);
	static std::string getMessages(int index);
private:
	static std::string messages[10];
	static void moveUp();
};


#endif