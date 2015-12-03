// SampleShipper.cpp
//
// Takes Audio from hardware, sends through EchoPrint object
// Returns Song object
#include "SampleShipper.h"
#include "EchoPrint.h"
#include "Song.h"
#include <boost/algorithm/string.hpp>

Song SampleShipper::ship(string filepath){

	EchoPrint echoprint;
	string result;
	result = echoprint.ID(filepath);
	Song constructedSong = stringToSong(result);

	getArt(getMBID(constructedSong.getAlbum()));

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

	string curlRequest = "http://musicbrainz.org/ws/2/recording?query=release:\"" + Album + "\"&fmt=json&limit=1";
	size_t pos = 0;

 	boost::replace_all(curlRequest, " ", "%%20");

  	cout << "Stringed request:" << curlRequest << endl;

	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, curlRequest.c_str()); 
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, mbid_curl_write);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	//fwrite( mbidbuf.c_str(), mbidbuf.length(), sizeof(char), stdout);

	// cout << "getMBID got the following JSON response: " << mbidbuf;

	return JSONtoMBID(mbidbuf);

}

string SampleShipper::JSONtoMBID(string latest){

	rapidjson::Document mbResponse;
	mbResponse.Parse(mbidbuf.c_str());
	//assert(mbResponse.HasMember("recordings"));
	//assert(mbResponse["recordings"][0].HasMember("releases"));

	string MBID = mbResponse["recordings"][0]["releases"][0]["id"].GetString();

	return MBID;

}

void SampleShipper::getArt(string MBID){

	CoverArtArchive::CCoverArt CoverArt("example-1.0");

	std::vector<unsigned char> ImageData=CoverArt.FetchFront(MBID);

    if (ImageData.size())
    {
            string FileName = "./bin/fetchedart.jpg";

            std::ofstream Front(FileName.c_str());
            Front.write((const char *)&ImageData[0],ImageData.size());
            Front.close();
    }

    string resize = "convert ./bin/fetchedart.jpg -resize 800x800 ./bin/fetchedart.jpg";
	FILE* resizeHandle = popen(resize.c_str(), "r");
	pclose(resizeHandle);
}