// SampleShipper.h
//
//

#ifndef SAMPLESHIPPER_H
#define SAMPLESHIPPER_H

#include "Song.h"
#include "rapidjson/document.h"

class SampleShipper {
	public:
		Song ship(string);
	private:
		Song stringToSong(string);

};

#endif
