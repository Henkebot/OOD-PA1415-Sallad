#ifndef TWITTEsR_H
#define TWITTEsR_H
#pragma once
#pragma comment(lib, "legacy_stdio_definitions.lib") 
#include <cstdio>
#include <iostream>
#include <fstream>
#include "../include/twitcurl.h"
#include <string>

class Twitter
{
public:
	Twitter();
	~Twitter();
	std::string getRandomTweet() const;

	// If the authentication fails it will use the local feed instead!
	bool authenticate(); 
	void readFeed();

	int getNumberOfTweets() const;

private:
	std::string getFeed() const; //Import the the feed from file and return the string

	void getTweets(const std::string & feed); //Reed the feed and filter it down to single tweets and stores them in the array

private:
	std::string** tweets;
	int size;
	twitCurl twitterObj;
	bool succAuth;

};


#endif