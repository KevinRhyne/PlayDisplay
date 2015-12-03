// SoundMonitor.cpp 
//
// Interfaces hardware and software fingerprinting

#include "SoundMonitor.h"

using namespace std;

Song SoundMonitor::update(){

	AudioInputController audioinput;
	SampleShipper sampleshipper;

	Song latestSong("NULL", "NULL", "NOARTIST");
	string filename;

	while(latestSong.getArtist() == "NOARTIST") {
		filename = audioinput.recordSample();
		latestSong = sampleshipper.ship(filename);
	}

	return latestSong;

}