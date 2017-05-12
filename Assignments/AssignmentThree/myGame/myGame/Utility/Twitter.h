#ifndef TWITTER_H
#define TWITTER_H
#include <iostream>
#include <string>
#include <fstream>
#pragma comment(lib, "legacy_stdio_definitions.lib") 
#include <cstdio>
FILE _iob[] = { *stdin, *stdout, *stderr };
extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
#include "../include/twitcurl.h"

class Twitter
{
public:
	Twitter();
	~Twitter();
	std::string getRandomTweet() const;
private:
	std::string getFeed() const; //Import the the feed from file and return the string
	void getTweets(const std::string & feed); //Reed the feed and filter it down to single tweets and stores them in the array

private:
	std::string** tweets;
	int size;
};


#endif