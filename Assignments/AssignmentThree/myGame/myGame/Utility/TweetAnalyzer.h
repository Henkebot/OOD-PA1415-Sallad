#ifndef TWEETANALYSER_H
#define TWEETANALYSER_H
#include "Identifier.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
class TweetAnalyser
{
public:
	static int getInRoom(const std::string & tweet, Identifier *& inRoom);
private:
	static std::string filterTweet(const std::string & tweet);
	static std::string toLower(const std::string & tweet);
};


#endif