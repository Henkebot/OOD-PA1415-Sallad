#include "twitterClient.h"
namespace Twitter
{
	twitCurl twitterObj;

	void Twitter::init()
	{
		twitterObj.setTwitterUsername("PA1415_Sallad");
		twitterObj.setTwitterPassword("SalladSallad");

		twitterObj.getOAuth().setConsumerKey(std::string("LeDeJ8IzR6KJqmZbz5lZyUjTD"));
		twitterObj.getOAuth().setConsumerSecret(std::string("syL8i7g3ywcTJXJyzs8qoV3fa2Rp2y7xwI4XTybUY4iV632Umq"));

		twitterObj.getOAuth().setOAuthTokenKey("861520933361766400-k2knHKKE9ZihiJQ9LPiyMRY0MfGS8kp");
		twitterObj.getOAuth().setOAuthTokenSecret("UdpYdeG7Ussg82YQfXFXDsawozUqAlkeLTOvy2LpXpi33");
	}

	bool auth()
	{
		return twitterObj.accountVerifyCredGet();
	}

	std::string getFeed()
	{
		std::string timeline = "";
		if (twitterObj.timelineUserGet(true, true, 0))
		{
			twitterObj.getLastWebResponse(timeline);
			//printf("\ntwitterClient:: twitCurl::timelineUserGet web response:\n%s\n", timeline.c_str());
		}
		return timeline;
	}

}
