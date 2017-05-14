#include "TweetAnalyzer.h"

int TweetAnalyser::getInRoom(const std::string & tweet, Identifier *& inRoom)
{
	std::string lowerCaseTweet = TweetAnalyser::toLower(tweet);
	int nrOfKeywords = 0;
	int keywordsFound = 0;

	inRoom = new Identifier[50];

	std::string tweetAsOneLine = TweetAnalyser::filterTweet(lowerCaseTweet);

	std::ifstream keywords;
	keywords.open("keywords/keywords.txt");
	if (!keywords)
	{
		//do stuff
	}
	keywords >> nrOfKeywords;
	keywords.ignore();

	std::string keyword = "";
	std::string id = "";

	for (int i = 0; i < nrOfKeywords && keywordsFound < 50; i++)
	{
		std::getline(keywords, keyword);
		std::getline(keywords, id);

		int found = 0;
		int skipper = 0;
		bool wordFound = false;
		int nrOfStuffToSpawn = 0;
		while (found != -1)
		{
			found = tweetAsOneLine.find(keyword, found + skipper);
			if (found != -1)
			{
				std::cout << "Found a keyword! It's a " << id << std::endl;
				nrOfStuffToSpawn++;
				if (wordFound == false)
				{
					keywordsFound++;
					wordFound = true;
				}
			}
			skipper = 1;
		}
		if (wordFound)
		{
			inRoom[keywordsFound - 1].setNewId(id);
			inRoom[keywordsFound - 1].setNewAmount(nrOfStuffToSpawn);
		}
			
	}
	keywords.close();

	return nrOfKeywords;
}

std::string TweetAnalyser::filterTweet(const std::string & tweet)
{
	//this function filters the tweet from unwanted chars.
	char chars[] = "abcdefghijklmnopqrstuvwxyz1234567890";
	int length = tweet.length();
	std::string str = "";
	bool found = false;

	for (int i = 0; i < length; i++)
	{
		found = false;
		for (int k = 0; k < 36 && !found; k++)
		{
			if (tweet[i] == chars[k])
			{
				found = true;
				str += chars[k];
			}
		}
	}
	return str;
}

std::string TweetAnalyser::toLower(const std::string & tweet)
{
	std::string lower = "";

	for (int i = 0; i < static_cast<int>(tweet.length()); i++)
	{
		if (static_cast<int>(tweet[i]) >= 64 && static_cast<int>(tweet[i] < 90))
		{
			char c = static_cast<int>(tweet[i]) + 32;
			lower += c;
		}
		else
		{
			lower += tweet[i];
		}
	}


	return lower;
}

