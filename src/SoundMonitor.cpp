// SoundMonitor.cpp 
//
// Interfaces hardware and software fingerprinting

#include "SoundMonitor.h"

using namespace std;

Song SoundMonitor::update(){

	AudioInputController audioinput;
	SampleShipper sampleshipper;

	string filename = audioinput.recordSample();

	Song latestSong = sampleshipper.ship(filename);

	return latestSong;

}