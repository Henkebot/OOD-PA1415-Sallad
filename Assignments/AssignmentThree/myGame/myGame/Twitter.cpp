#include "Twitter.h"

Twitter::Twitter()
{
	this->tweets = nullptr;
	this->size = 0;
	std::string theFeed = this->getFeed();
	this->getTweets(theFeed);
}

Twitter::~Twitter()
{
	for (int i = 0; i < this->size; i++)
	{
		delete this->tweets[i];
	}
	delete[] this->tweets;
}

std::string& Twitter::getFeed() const
{
	std::string feed;
	std::ifstream feedFile;
	feedFile.open("feed/feed.txt");
	if (!feedFile)
	{
		feed = "#";
	}
	else
	{
		std::getline(feedFile, feed);
		feedFile.close();
	}

	return feed;
}

void Twitter::getTweets(const std::string & feed)
{
	int currentIndex = 0;
	int nrOfTweets = 0;

	std::string beforeTweet = "\"text\":\"";
	std::string afterTweet = "\",\"truncated\":";

	//find out how many tweets
	if (feed[0] != '#')
	{
		while (currentIndex != -1)
		{
			currentIndex = feed.find(beforeTweet, currentIndex);

			nrOfTweets
		}
		
	}
	
}
