#include <iostream>
#include "twitterClient.h"
int main()
{
	twitCurl twitterObj;

	twitterObj.setTwitterUsername("PA1415_Sallad");
	twitterObj.setTwitterPassword("SalladSallad");

	twitterObj.getOAuth().setConsumerKey(std::string("LeDeJ8IzR6KJqmZbz5lZyUjTD"));
	twitterObj.getOAuth().setConsumerSecret(std::string("syL8i7g3ywcTJXJyzs8qoV3fa2Rp2y7xwI4XTybUY4iV632Umq"));

	twitterObj.getOAuth().setOAuthTokenKey("861520933361766400-k2knHKKE9ZihiJQ9LPiyMRY0MfGS8kp");
	twitterObj.getOAuth().setOAuthTokenSecret("UdpYdeG7Ussg82YQfXFXDsawozUqAlkeLTOvy2LpXpi33");

	std::string replyMsg("");
	if (twitterObj.accountVerifyCredGet())
	{
		twitterObj.getLastWebResponse(replyMsg);
		printf("\ntwitterClient:: twitCurl::accountVerifyCredGet web response:\n%s\n", replyMsg.c_str());
	}

	std::string statusMsg("TA MIG I ANDRA SIDAN!");
	twitterObj.statusUpdate(statusMsg);


	return 0;
}