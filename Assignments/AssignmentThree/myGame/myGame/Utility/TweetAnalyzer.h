#ifndef TWEETANALYSER_H
#define TWEETANALYSER_H
#include "Identifier.h"
#include <string>
static class TweetAnalyser
{
public:
	static int getInRoom(const std::string & tweet, Identifier *& inRoom);
private:
	static int getNrOfWords(const std::string & tweet);
};


#endif