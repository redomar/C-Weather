#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "dotenv.h"

int main()
{
	env_load(".", false);
	char *connection = getenv("AQI_API_TOKEN");
	printf(connection);
	api();
	return 0;
}

int api()
{
	CURL *curl;
	CURLcode res;
	char url[] = "https://reqres.in/api/users";
	char postData[] = "email=eve.holt@reqres.in&password=pistol";
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return 0;
}
