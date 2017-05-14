#ifndef IDENTIFIER_H
#define IDENTIFIER_H
#include <string>
class Identifier
{
public:
	Identifier(const std::string & id = "", int amount = 1);
	void setNewId(const std::string & id);
	void setNewAmount(int amount);
	std::string getId() const;
	int getAmount() const;
private:
	std::string id;
	int amount;
};



#endif // !IDENTIFIER_H
