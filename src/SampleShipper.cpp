// SampleShipper.cpp
//
// Takes Audio from hardware, sends through EchoPrint object
// Returns Song object
#include "SampleShipper.h"
#include "EchoPrint.h"
#include "Song.h"

Song SampleShipper::ship(string filepath){

	EchoPrint echoprint;
	string result;
	result = echoprint.ID(filepath);
	Song constructedSong = stringToSong(result);
	getMBID("dummy");
	//result = echoprint.ID(filepath);
	//cout << "Hi, SampleShipper.ship sent filepath " + filepath << endl;
	//cout << "And has a JSON ID of " << result << endl << endl;

	return constructedSong;


}

Song SampleShipper::stringToSong(string jsonString){
	cout << "\n\nI am stringToSong and I have the following string to parse...\n\n\n" << jsonString << endl;
	rapidjson::Document songJSONobject;
	songJSONobject.Parse(jsonString.c_str());
	//assert(songJSONobject.IsObject());

	return Song(songJSONobject["track"].GetString(), songJSONobject["release"].GetString(), songJSONobject["artist"].GetString());
}

std::string mbidbuf;

size_t mbid_curl_write( void *ptr, size_t size, size_t nmemb, void *stream)
{
	mbidbuf.append((char*)ptr, size*nmemb);
	return size*nmemb;
}


string SampleShipper::getMBID(string Album){


	mbidbuf.clear();

	string curlRequest = "http://musicbrainz.org/ws/2/recording?query=release:u%%20guessed%%20it&fmt=json&limit=1";
		


	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, curlRequest.c_str()); 
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, mbid_curl_write);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	fwrite( mbidbuf.c_str(), mbidbuf.length(), sizeof(char), stdout);

	// cout << "getMBID got the following JSON response: " << mbidbuf;

	return mbidbuf;

}