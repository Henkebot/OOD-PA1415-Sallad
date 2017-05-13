#include "TweetAnalyzer.h"

int TweetAnalyser::getInRoom(const std::string & tweet, Identifier *& inRoom)
{
	int nrOfWords = TweetAnalyser::getNrOfWords(tweet);
	std::string lowerCaseTweet = tweet;
	std::transform(lowerCaseTweet.begin(), lowerCaseTweet.end(), lowerCaseTweet.begin(), ::tolower);
	return 0;
}

int TweetAnalyser::getNrOfWords(const std::string & tweet)
{
	int nSpaces = 0;
	unsigned int i = 0;

	// Skip over spaces at the beginning of the word
	while (isspace(tweet.at(i)))
		i++;

	for (; i < tweet.length(); i++)
	{
		if (isspace(tweet.at(i)))
		{
			nSpaces++;

			// Skip over duplicate spaces & if a NULL character is found, we're at the end of the string
			while (isspace(tweet.at(i++)))
				if (tweet.at(i) == '\0')
					nSpaces--;
		}
	}

	// The number of words = the number of spaces + 1
	return nSpaces + 1;
}
