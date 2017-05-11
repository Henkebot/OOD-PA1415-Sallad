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

std::string Twitter::getRandomTweet() const
{
	if (size == 0) throw "Zero size";
	std::string aTweet = *this->tweets[rand() % this->size];
	return aTweet;
}

std::string Twitter::getFeed() const
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
	int skipper = 0;

	std::string beforeTweet = "\"text\":\"";
	std::string afterTweet = "\",\"truncated\":";

	
	if (feed[0] != '#')
	{
		//find out how many tweets
		while (currentIndex != -1)
		{
			currentIndex = feed.find(beforeTweet, currentIndex + skipper);
			nrOfTweets++;
			skipper = 1;
		}
		nrOfTweets--;
		if (nrOfTweets != 0)
		{
			this->size = nrOfTweets;
			this->tweets = new std::string*[this->size];
			int startIndex = 0;
			int endIndex = 0;
			skipper = 0;
			for (int i = 0; i < this->size; i++)
			{
				startIndex = feed.find(beforeTweet, startIndex + skipper);
				endIndex = feed.find(afterTweet, startIndex);
				std::string tweet = "";
				for (int k = startIndex + 8; k < endIndex; k++)
				{
					tweet += feed[k];
				}
				std::cout << tweet << std::endl;
				this->tweets[i] = new std::string(tweet);
				skipper = 1;
			}
		}
	}
	
}
