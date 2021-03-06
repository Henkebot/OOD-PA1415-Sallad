#include "Twitter.h"

Twitter::Twitter()
{
	this->tweets = nullptr;
	this->size = 0;

	succAuth = false;
}

Twitter::~Twitter()
{
	delete[] this->tweets;
}

std::string Twitter::getRandomTweet() const
{
	if (size == 0) throw "Zero size";
	bool foundTweet = false;
	const bool NOT_USED = false;
	std::string aTweet = "";

	while (!foundTweet)
	{
		int index = rand() % this->size;
		if (this->usedTweets[index] == NOT_USED)
		{
			foundTweet = true;
			aTweet = this->tweets[index];
			this->usedTweets[index] = true;
		}

	}

	return aTweet;
}

bool Twitter::authenticate()
{
	twitterObj.setTwitterUsername("PA1415_Sallad");
	twitterObj.setTwitterPassword("SalladSallad");

	twitterObj.getOAuth().setConsumerKey(std::string("LeDeJ8IzR6KJqmZbz5lZyUjTD"));
	twitterObj.getOAuth().setConsumerSecret(std::string("syL8i7g3ywcTJXJyzs8qoV3fa2Rp2y7xwI4XTybUY4iV632Umq"));

	twitterObj.getOAuth().setOAuthTokenKey("861520933361766400-k2knHKKE9ZihiJQ9LPiyMRY0MfGS8kp");
	twitterObj.getOAuth().setOAuthTokenSecret("UdpYdeG7Ussg82YQfXFXDsawozUqAlkeLTOvy2LpXpi33");

	succAuth = twitterObj.accountVerifyCredGet();

	return succAuth;
}


void Twitter::readFeed(const std::string& user, int maxAmountOfRooms)
{
	if (succAuth)
	{
		std::string timeline = "";
		//Sista �r namnet
		if (user == "")
			this->user = "Local";
		else
			this->user = user;
		if (twitterObj.timelineUserGet(false, true, maxAmountOfRooms, user))
		{
			twitterObj.getLastWebResponse(timeline);
			if (timeline.find("{\"errors\":[{\"code\":34,\"message\":\"Sorry, that page does not exist.\"}]}") != -1)
			{
				twitterObj.timelineUserGet(false, true, maxAmountOfRooms);
				twitterObj.getLastWebResponse(timeline);
				this->user = "Local";
			}
			else if (timeline.find("\"error\":\"Not authorized.\"") != -1)
			{
				twitterObj.timelineUserGet(false, true, maxAmountOfRooms);
				twitterObj.getLastWebResponse(timeline);
				this->user = "Local";
			}
		}
		getTweets(timeline);
	}
	else
	{
		getTweets(getFeed());
	}
}

int Twitter::getNumberOfTweets() const
{
	return size;
}

std::string * Twitter::getAllTweets() const
{
	return new std::string(*this->tweets);
}

std::string Twitter::getUser() const
{
	return user;
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
	int tweetCounter = 0;

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
		std::cout << "nrOfTweets:" << nrOfTweets << std::endl;
		if (nrOfTweets != 0)
		{
			this->size = nrOfTweets;
			this->tweets = new std::string[this->size];
			this->usedTweets = new bool[this->size]{ false };
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
				//std::cout << tweet << std::endl;
				if (tweet.size() <= 144)
				{
					this->tweets[tweetCounter++] = std::string(tweet);
				}
				
				skipper = 1;
			}
		}
		this->size -= (this->size - tweetCounter);
	}
	
}
