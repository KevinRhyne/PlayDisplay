// SoundMonitor.h
//
// 


#ifndef SOUNDMONITOR_H
#define SOUNDMONITOR_H

#include <string>
#include "Song.h"
#include "SampleShipper.h"
#include "AudioInputController.h"

using namespace std;

class SoundMonitor{
	public:
		Song update();
		
};

#endif
