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